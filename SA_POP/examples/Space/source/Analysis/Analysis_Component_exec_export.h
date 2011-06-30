
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl ANALYSIS_COMPONENT_EXEC
// ------------------------------
#ifndef ANALYSIS_COMPONENT_EXEC_EXPORT_H
#define ANALYSIS_COMPONENT_EXEC_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (ANALYSIS_COMPONENT_EXEC_HAS_DLL)
#  define ANALYSIS_COMPONENT_EXEC_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && ANALYSIS_COMPONENT_EXEC_HAS_DLL */

#if !defined (ANALYSIS_COMPONENT_EXEC_HAS_DLL)
#  define ANALYSIS_COMPONENT_EXEC_HAS_DLL 1
#endif /* ! ANALYSIS_COMPONENT_EXEC_HAS_DLL */

#if defined (ANALYSIS_COMPONENT_EXEC_HAS_DLL) && (ANALYSIS_COMPONENT_EXEC_HAS_DLL == 1)
#  if defined (ANALYSIS_COMPONENT_EXEC_BUILD_DLL)
#    define ANALYSIS_COMPONENT_EXEC_Export ACE_Proper_Export_Flag
#    define ANALYSIS_COMPONENT_EXEC_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define ANALYSIS_COMPONENT_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* ANALYSIS_COMPONENT_EXEC_BUILD_DLL */
#    define ANALYSIS_COMPONENT_EXEC_Export ACE_Proper_Import_Flag
#    define ANALYSIS_COMPONENT_EXEC_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define ANALYSIS_COMPONENT_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* ANALYSIS_COMPONENT_EXEC_BUILD_DLL */
#else /* ANALYSIS_COMPONENT_EXEC_HAS_DLL == 1 */
#  define ANALYSIS_COMPONENT_EXEC_Export
#  define ANALYSIS_COMPONENT_EXEC_SINGLETON_DECLARATION(T)
#  define ANALYSIS_COMPONENT_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* ANALYSIS_COMPONENT_EXEC_HAS_DLL == 1 */

// Set ANALYSIS_COMPONENT_EXEC_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (ANALYSIS_COMPONENT_EXEC_NTRACE)
#  if (ACE_NTRACE == 1)
#    define ANALYSIS_COMPONENT_EXEC_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define ANALYSIS_COMPONENT_EXEC_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !ANALYSIS_COMPONENT_EXEC_NTRACE */

#if (ANALYSIS_COMPONENT_EXEC_NTRACE == 1)
#  define ANALYSIS_COMPONENT_EXEC_TRACE(X)
#else /* (ANALYSIS_COMPONENT_EXEC_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define ANALYSIS_COMPONENT_EXEC_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (ANALYSIS_COMPONENT_EXEC_NTRACE == 1) */

#endif /* ANALYSIS_COMPONENT_EXEC_EXPORT_H */

// End of auto generated file.