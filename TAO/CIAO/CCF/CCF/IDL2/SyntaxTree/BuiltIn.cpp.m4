divert(-1)

# file      : CCF/IDL2/SyntaxTree/BuiltIn.cpp.m4
# author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
# cvs-id    : $Id$

include(`BuiltIn.m4')

define(`built_in_type',
  `built_in_type_impl(`make_class_name(`$1')', `make_var_name(`$1')')')dnl


define(`built_in_type_impl', `

      // $1
      //
      //
      namespace
      {
        TypeInfo
        $2_init_ ()
        {
          TypeInfo ti (typeid ($1));
          ti.add_base (Access::PUBLIC,
                       true,
                       BuiltInTypeDef::static_type_info ());
          return ti;
        }

        TypeInfo $2_ ($2_init_ ());
      }

      TypeInfo const& $1::
      static_type_info () { return $2_; }')

divert(0)dnl
dnl
dnl
dnl
// file      : CCF/IDL2/SyntaxTree/BuiltIn.cpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

// Note, that this file is automatically generated!
//

#include "CCF/IDL2/SyntaxTree/BuiltIn.hpp"

using namespace Introspection;

namespace CCF
{
  namespace IDL2
  {
    namespace SyntaxTree
    {

      // BuiltInTypeDef
      //
      //
      namespace
      {
        TypeInfo
        built_in_type_def_init_ ()
        {
          TypeInfo ti (typeid (BuiltInTypeDef));
          ti.add_base (Access::PUBLIC, true, TypeDef::static_type_info ());
          return ti;
        }

        TypeInfo built_in_type_def_ (built_in_type_def_init_ ());
      }

      TypeInfo const& BuiltInTypeDef::
      static_type_info () { return built_in_type_def_; }
dnl
built_in_type(`object')
built_in_type(`value base')
built_in_type(`any')
built_in_type(`boolean')
built_in_type(`char')
built_in_type(`double')
built_in_type(`float')
built_in_type(`long')
built_in_type(`long double')
built_in_type(`long long')
built_in_type(`octet')
built_in_type(`short')
built_in_type(`string')
built_in_type(`unsigned long')
built_in_type(`unsigned long long')
built_in_type(`unsigned short')
built_in_type(`void')
built_in_type(`wchar')
built_in_type(`wstring')
dnl
    }
  }
}
