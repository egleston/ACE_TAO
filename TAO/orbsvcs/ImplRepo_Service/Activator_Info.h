// $Id$
#ifndef ACTIVATOR_INFO_H
#define ACTIVATOR_INFO_H

#include "ImR_ActivatorC.h"

#include "ace/SString.h"
#include "ace/Bound_Ptr.h"


#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/**
* @brief Information about IMR registered Activators.
*/
struct Activator_Info
{
  Activator_Info (const ACE_CString& aname,
    CORBA::Long atoken,
    const ACE_CString& aior,
    ImplementationRepository::Activator_ptr act =
    ImplementationRepository::Activator::_nil ());

  /// Reset the connection portion
  void reset();

  ACE_CString name;
  CORBA::Long token;
  ACE_CString ior;
  ImplementationRepository::Activator_var activator;
  int waiting_clients;
};

typedef ACE_Strong_Bound_Ptr<Activator_Info, ACE_Null_Mutex> Activator_Info_Ptr;

#endif /* ACTIVATOR_INFO_H */
