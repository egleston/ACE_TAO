// This may look like C, but it's really -*- C++ -*-


//=============================================================================
/**
 *  @file     Reply_Dispatcher.h
 *
 *  $Id$
 *
 *   Define the interface for the Reply_Dispatcher strategies.
 *
 *
 *  @author  Alexander Babu Arulanthu <alex@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_REPLY_DISPATCHER_H
#define TAO_REPLY_DISPATCHER_H
#include "ace/pre.h"

#include "tao/IOPC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Condition.h"

// Forward Declarations.
class TAO_GIOP_Message_State;
class TAO_GIOP_Message_Version;
class TAO_Transport;
class TAO_Pluggable_Reply_Params;

/**
 * @class TAO_Reply_Dispatcher
 *
 *
 * Different invocation modes process the Reply messages in
 * different ways.  Traditional synchronous replies simply receive
 * the message and wake up the waiting thread (if any).
 * Asynchronous Method Invocation (Callbacks) must process the
 * message in the thread that receives it.
 * Deferred Synchronous (DII) and AMI in the Poller mode save the
 * reply for later processing in the application.
 * The lower level components in the ORB only deal with this
 * abstract interface, when the invocation is made the right type
 * of Reply Dispatcher is instantiated and registered with the
 * Transport object.
 */
class TAO_Export TAO_Reply_Dispatcher
{

public:
  /// Constructor.
  TAO_Reply_Dispatcher (void);

  /// Destructor.
  virtual ~TAO_Reply_Dispatcher (void);

  /**
   * Dispatch the reply. Return 1 on sucess, -1 on error.
   * @@ TODO Pluggable Messaging:  this method has too many arguments,
   *    the "Right Thing"[tm] is for the Transport Object to create a
   *    "ClientReply" that encapsulates all we need to process a
   *    reply.  Naturally it is possible that different messaging
   *    protocols implement different variants of such ClientReply
   *    class.
   */
  virtual int dispatch_reply (TAO_Pluggable_Reply_Params &params) = 0;

  /**
   * The used for the pending reply has been closed.
   * No reply is expected.
   * @@ TODO: If the connection was closed due to a CloseConnection
   *    message then we could re-issue the request instead of raising
   *    the exception, it would a matter of simply adding a boolean
   *    argument to this function.
   */
  virtual void connection_closed (void) = 0;

  /// Get the reply status.
  CORBA::ULong reply_status (void) const;

  /// Following methods are useful only when the invocation has a
  /// timeout.
  /**
   * MT invocations with timeouts are a different beast in
   * itself. They need some special attention. Things get nasty when
   * the leader thread collects the reply and at the same time the
   * follower timesout waiting for the reply. There is a semantic
   * problem here. Does the follower throw an exception back as a
   * CORBA::TIMEOUT or just make one last check to see whether anyone
   * (leader) has collected the reply. Some of these extra methods
   * here help the invocation threads to make a decision one way or
   * another. The code is designed to be on the positive side ie. the
   * follower will collect the reply if a leader has collected its
   * reply already, instead of throwing an exception.  Its a decision
   * that can be argued for hours.
   *
   * The following methods should be no-ops if timeouts arent set.
   */
  enum
    {
      TIMEOUT = 0,
      NO_TIMEOUT
    };

  /// Set whether the dispatcher should be prepared for a timeout. The
  /// set operation is not synchronized.
  void has_timeout (CORBA::Boolean t);

  /// Methods used to change the state to indicate that whether
  /// dispatching is started or not!
  void start_dispatch (void);
  void end_dispatch (void);

  /// Wait on the condition variable for the dispatch to end. If no
  /// threads are dispatching will just return immediately.
  int wait_for_dispatch_completion (void);

protected:
  /// Reply or LocateReply status.
  CORBA::ULong reply_status_;

  /// Mutex and Synch condition for timeouts..
  TAO_SYNCH_MUTEX mutex_;
  TAO_Condition<TAO_SYNCH_MUTEX> condition_;

  /// Flag to indicate whether the invocation for which this
  /// dispatcher is used, has a timeout or not.
  CORBA::Boolean timeout_;

  /// Variable to indicate whether dispatching is happening in this
  /// reply dispatcher.
  /**
   * Point to note is that, the value of the flag is not of much
   * importance for the normal case, but only for the  case when
   * timeouts are set.
   */
  CORBA::Boolean dispatching_;

  /// Any threads waiting for end of dispatch?
  CORBA::Boolean threads_waiting_;

};

#if defined (__ACE_INLINE__)
#include "tao/Reply_Dispatcher.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_REPLY_DISPATCHER_H */
