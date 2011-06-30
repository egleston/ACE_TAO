
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl FMUF_CONTROLLER_STUB
// ------------------------------
#ifndef FMUF_CONTROLLER_STUB_EXPORT_H
#define FMUF_CONTROLLER_STUB_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (FMUF_CONTROLLER_STUB_HAS_DLL)
#  define FMUF_CONTROLLER_STUB_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && FMUF_CONTROLLER_STUB_HAS_DLL */

#if !defined (FMUF_CONTROLLER_STUB_HAS_DLL)
#  define FMUF_CONTROLLER_STUB_HAS_DLL 1
#endif /* ! FMUF_CONTROLLER_STUB_HAS_DLL */

#if defined (FMUF_CONTROLLER_STUB_HAS_DLL) && (FMUF_CONTROLLER_STUB_HAS_DLL == 1)
#  if defined (FMUF_CONTROLLER_STUB_BUILD_DLL)
#    define FMUF_CONTROLLER_STUB_Export ACE_Proper_Export_Flag
#    define FMUF_CONTROLLER_STUB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define FMUF_CONTROLLER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* FMUF_CONTROLLER_STUB_BUILD_DLL */
#    define FMUF_CONTROLLER_STUB_Export ACE_Proper_Import_Flag
#    define FMUF_CONTROLLER_STUB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define FMUF_CONTROLLER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* FMUF_CONTROLLER_STUB_BUILD_DLL */
#else /* FMUF_CONTROLLER_STUB_HAS_DLL == 1 */
#  define FMUF_CONTROLLER_STUB_Export
#  define FMUF_CONTROLLER_STUB_SINGLETON_DECLARATION(T)
#  define FMUF_CONTROLLER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* FMUF_CONTROLLER_STUB_HAS_DLL == 1 */

// Set FMUF_CONTROLLER_STUB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (FMUF_CONTROLLER_STUB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define FMUF_CONTROLLER_STUB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define FMUF_CONTROLLER_STUB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !FMUF_CONTROLLER_STUB_NTRACE */

#if (FMUF_CONTROLLER_STUB_NTRACE == 1)
#  define FMUF_CONTROLLER_STUB_TRACE(X)
#else /* (FMUF_CONTROLLER_STUB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define FMUF_CONTROLLER_STUB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (FMUF_CONTROLLER_STUB_NTRACE == 1) */

#endif /* FMUF_CONTROLLER_STUB_EXPORT_H */

// End of auto generated file.