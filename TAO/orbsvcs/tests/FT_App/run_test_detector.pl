eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

# Purpose:
#       To test the FaultDetectorFactory and FaultDetectors
#
# Process being tested:
#       Fault_Detector
#         implements FaultDetectorFactory interface
#         implements PullMonitorable interface
#
# Processes used in test:
#       FT_Replica
#           implements TestReplica interface.
#           implements PullMonitorable.
#       StubNotifier
#           implements FaultNotifier interface (as a stub.)
#           implements PullMonitorable.
#           client for FaultDetectorFactory interface.
#       FT_Client
#           client for TestReplica interface.
#           client for PullMonitorable.
#
# Test Scenario ( ***Test: marks behavior being tested):
#   Phase 1:
#     Start two FT_Replicas
#       FT_Replicas write TestReplica IORs (FR#1 and FR#2) to files
#     Start the Fault_Detector
#       Fault_Detector writes its IOR (FDF) to a file
#   Phase 2:
#     Wait for IORs: FR#1, FR#2, and FDF
#     Start the StubNotifier giving it IORS: FR#1, FR#2 and FDF
#      StubNotifier calls FDF to create a FaultDetector
#       for each Replica.
#      StubNotifier writes FaultNotifier IOR (FN) to a file.
#   Phase 3:
#     Wait for IOR: FN
#     Start FT_Client giving it IORS: FR#1 and FR#2. [1]
#       FT_Client interacts with FR#1.
#       FT_Client asks FR#1 to fault.  It does so.
#       FT_Client notices fault and switches to FR#2. [1]
#       ***Test: FD#1 notices fault and notifies StubNotifier
#       ***Test: FD#1 terminates
#       FT_Client interacts with FR#2.
#       FT_Client asks FR#2 to shut down.
#       FT_Client shuts down.
#       ***Test: FD#2 notices FR2 is gone, interprets this
#         as a fault, and notifies StubNotifier.
#       ***Test: FD#2 terminates.
#       ***Test: FDF is idle, so it terminates.
#       StubNotifier sees FDF terminate, so it terminates
#     Phase 4:
#       Wait for all processes to terminate.
#       Check termination status.
#       Delete temp files.
#
# [1] Client mediated fault tolerance.  These points will
#     change when IOGR support is available.
use lib '../../../../bin';
use PerlACE::Run_Test;

########################
#command line options
#set defaults:
my($verbose) = 0;         # 1: report perl actions before executing them
my($debug_builds) = 0;    # 0: use exes from Release directories
my($simulated) = 1;       # 1: use "client simulated" fault tolerance

foreach $i (@ARGV) {
  if ($i eq "--debug_build")
  {
    $debug_builds = 1;
  }
  elsif ($i eq "--no_simulate")  # reverse this once we have FT ORB support
  {
    $simulated = 0;
  }
  elsif ($i eq "-v")
  {
    $verbose += 1;
  }
}


my($build_directory) = "/Release";
if ( $debug_builds ) {
  $build_directory = "";
}

if ( $verbose > 1) {
  print "verbose: $verbose\n";
  print "debug_builds: $debug_builds -> $build_directory\n";
  print "simulated: $simulated\n";
}


#define temp files
my($replica1_ior) = PerlACE::LocalFile ("replica1.ior");
my($replica2_ior) = PerlACE::LocalFile ("replica2.ior");
my($detector_ior) = PerlACE::LocalFile ("detector.ior");
my($notifier_ior) = PerlACE::LocalFile ("notifier.ior");
my($client_data) = PerlACE::LocalFile ("persistent.dat");

#discard junk from previous tests
unlink $replica1_ior;
unlink $replica2_ior;
unlink $detector_ior;
unlink $notifier_ior;
unlink #client_data

my($status) = 0;

my($REP1) = new PerlACE::Process (".$build_directory/ft_replica", "-o $replica1_ior -r 1");
my($REP2) = new PerlACE::Process (".$build_directory/ft_replica", "-o $replica2_ior -r 2");
my($DET) = new PerlACE::Process ("$ENV{'TAO_ROOT'}/orbsvcs/Fault_Detector$build_directory/Fault_Detector", "-o $detector_ior -q");
my($NOT) = new PerlACE::Process (".$build_directory/ft_notifier", "-o $notifier_ior -q -d $detector_ior -r $replica1_ior,$replica2_ior");
my($CL);
if (simulated) {
  $CL = new PerlACE::Process (".$build_directory/ft_client", "-f $replica1_ior,$replica2_ior -c testscript");
}else{
  #todo figure out how to get iogr
  $CL = new PerlACE::Process (".$build_directory/ft_client", "-f $replica1_iogr -c testscript");
}

print "TEST: starting replica1 ". $REP1->Executable . "\n" if ($verbose);
$REP1->Spawn ();

print "TEST: waiting for replica 1's IOR\n" if ($verbose);
if (PerlACE::waitforfile_timed ($replica1_ior, 5) == -1) {
    print STDERR "ERROR: cannot find file <$replica1_ior>\n";
    $REP1->Kill (); $REP1->TimedWait (1);
    exit 1;
}

print "\nTEST: starting replica2" . $REP2->Executable . "\n" if ($verbose);
$REP2->Spawn ();

print "TEST: waiting for replica 2's IOR\n" if ($verbose);
if (PerlACE::waitforfile_timed ($replica2_ior, 5) == -1) {
    print STDERR "ERROR: cannot find file <$replica2_ior>\n";
    $REP1->Kill (); $REP1->TimedWait (1);
    $REP2->Kill (); $REP2->TimedWait (1);
    exit 1;
}

print "\nTEST: starting detector factory" . $DET->Executable . "\n" if ($verbose);
$DET->Spawn ();

print "TEST: waiting for detector's IOR\n" if ($verbose);
if (PerlACE::waitforfile_timed ($detector_ior, 5) == -1) {
    print STDERR "ERROR: cannot find file <$detector_ior>\n";
    $REP1->Kill (); $REP1->TimedWait (1);
    $REP2->Kill (); $REP2->TimedWait (1);
    $DET->Kill (); $DET2->TimedWait(1);
    exit 1;
}

print "\nTEST: starting notifier" . $NOT->Executable . "\n" if ($verbose);
$NOT->Spawn ();

print "TEST: waiting for notifier's IOR\n" if ($verbose);
if (PerlACE::waitforfile_timed ($notifier_ior, 5) == -1) {
    print STDERR "ERROR: cannot find file <$notifier_ior>\n";
    $REP1->Kill (); $REP1->TimedWait (1);
    $REP2->Kill (); $REP2->TimedWait (1);
    $DET->Kill (); $DET2->TimedWait(1);
    $NOT->Kill (); $NOT->TimedWait(1);
    exit 1;
}

print "\nTEST: starting client." . $CL->Executable . "\n" if ($verbose);
$client = $CL->SpawnWaitKill (60);

if ($client != 0) {
    print STDERR "ERROR: client returned $client\n";
    $status = 1;
}

print "\nTEST: wait for replica 1.\n" if ($verbose);
$replica1 = $REP1->WaitKill (60);
if ($replica1 != 0) {
    print STDERR "ERROR: replica returned $replica1\n";
    $status = 1;
}

print "\nTEST: wait for replica 2.\n" if ($verbose);
$replica2 = $REP2->WaitKill (60);
if ($replica2 != 0) {
    print STDERR "ERROR: replica returned $replica2\n";
    $status = 1;
}

print "\nTEST: wait for detector factory to leave.\n" if ($verbose);
$detector = $DET->WaitKill (60);
if ($detector != 0) {
    print STDERR "ERROR: detector returned $detector\n";
    $status = 1;
}

print "\nTEST: wait for notifier to leave.\n" if ($verbose);
$notifier = $NOT->WaitKill (60);
if ($notifier != 0) {
    print STDERR "ERROR: notifier returned $notifier\n";
    $status = 1;
}

print "\nTEST: releasing scratch files.\n" if ($verbose);
unlink $replica1_ior;
unlink $replica2_ior;
unlink $detector_ior;
unlink $notifier_ior;

#client's work file
unlink $client_data;

exit $status;
