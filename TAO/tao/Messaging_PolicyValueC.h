// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_MESSAGING_POLICYVALUEC_H_
#define _TAO_IDL_MESSAGING_POLICYVALUEC_H_

#include "ace/pre.h"
#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "IOPC.h"
#include "Sequence.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

TAO_NAMESPACE  Messaging
{
  struct PolicyValue;
  class PolicyValue_var;
  
  struct TAO_Export PolicyValue
  {
    
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef PolicyValue_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

    static void _tao_any_destructor (void*);
    
    CORBA::PolicyType ptype;
    
#if !defined (_MESSAGING_POLICYVALUE__TAO_SEQ_OCTET_CH_)
#define _MESSAGING_POLICYVALUE__TAO_SEQ_OCTET_CH_
    
    class _tao_seq_Octet;
    
    // *************************************************************
    // _tao_seq_Octet
    // *************************************************************
    
    class TAO_Export _tao_seq_Octet : public 
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
    TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
    TAO_Unbounded_Sequence<CORBA::Octet>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
    {
    public:
      _tao_seq_Octet (void); // default ctor
      _tao_seq_Octet (CORBA::ULong max); // uses max size
      _tao_seq_Octet (
          CORBA::ULong max, 
          CORBA::ULong length, 
          CORBA::Octet *buffer, 
          CORBA::Boolean release = 0
        );
      _tao_seq_Octet (const _tao_seq_Octet &); // copy ctor
      ~_tao_seq_Octet (void);
      static void _tao_any_destructor (void*);
      
#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      _tao_seq_Octet (
          CORBA::ULong length,
          const ACE_Message_Block* mb
        )
        : TAO_Unbounded_Sequence<CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE == 1 */
      
    };
    
#endif /* end #if !defined */
    
    
#if !defined (__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef _tao_seq_Octet _pvalue_seq;
#endif /* ! __GNUC__ || ACE_HAS_GNUG_PRE_2_8 */

    _tao_seq_Octet pvalue;
    
  };
  
  class TAO_Export PolicyValue_var
  {
  public:
    PolicyValue_var (void);
    PolicyValue_var (PolicyValue *);
    PolicyValue_var (const PolicyValue_var &);
    ~PolicyValue_var (void);
    
    PolicyValue_var &operator= (PolicyValue *);
    PolicyValue_var &operator= (const PolicyValue_var &);
    PolicyValue *operator-> (void);
    const PolicyValue *operator-> (void) const;
    
    operator const PolicyValue &() const;
    operator PolicyValue &();
    operator PolicyValue &() const;
    // Variable-size types only.
    operator PolicyValue *&();
    
    // in, inout, out, _retn 
    const PolicyValue &in (void) const;
    PolicyValue &inout (void);
    PolicyValue *&out (void);
    PolicyValue *_retn (void);
    PolicyValue *ptr (void) const;
  
  private:
    PolicyValue *ptr_;
  };
  
  class TAO_Export PolicyValue_out
  {
  public:
    PolicyValue_out (PolicyValue *&);
    PolicyValue_out (PolicyValue_var &);
    PolicyValue_out (const PolicyValue_out &);
    PolicyValue_out &operator= (const PolicyValue_out &);
    PolicyValue_out &operator= (PolicyValue *);
    operator PolicyValue *&();
    PolicyValue *&ptr (void);
    PolicyValue *operator-> (void);
    
  private:
    PolicyValue *&ptr_;
    // Assignment from T_var not allowed.
    void operator= (const PolicyValue_var &);
  };
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_PolicyValue;
  
  
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  
#if !defined (__TAO_UNBOUNDED_SEQUENCE_MESSAGING_POLICYVALUESEQ_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_MESSAGING_POLICYVALUESEQ_CH_
  
  class TAO_EXPORT_MACRO _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq
    : public TAO_Unbounded_Base_Sequence
  {
  public:
    // = Initialization and termination methods.
    _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq (void);
    _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq (CORBA::ULong maximum); 
    _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq (
        CORBA::ULong maximum,
        CORBA::ULong length,
        PolicyValue *data,
        CORBA::Boolean release = 0
      );
    _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq (
        const _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq &rhs
      );
    _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq &operator= (
        const _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq &rhs
      );
    virtual ~_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq (void);
    
    // = Accessors.
    PolicyValue &operator[] (CORBA::ULong i);
    const PolicyValue &operator[] (CORBA::ULong i) const;
    
    // = Static operations.
    static PolicyValue *allocbuf (CORBA::ULong size);
    static void freebuf (PolicyValue *buffer);
    
    // Implement the TAO_Base_Sequence methods (see Sequence.h)
    virtual void _allocate_buffer (CORBA::ULong length);
    virtual void _deallocate_buffer (void);
    PolicyValue *get_buffer (CORBA::Boolean orphan = 0);
    const PolicyValue *get_buffer (void) const;
    void replace (
        CORBA::ULong max,
        CORBA::ULong length,
        PolicyValue *data,
        CORBA::Boolean release
      );
  };
  
#endif /* end #if !defined */
  
  
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
  
#if !defined (_MESSAGING_POLICYVALUESEQ_CH_)
#define _MESSAGING_POLICYVALUESEQ_CH_
  
  class PolicyValueSeq;
  class PolicyValueSeq_var;
  
  // *************************************************************
  // PolicyValueSeq
  // *************************************************************
  
  class TAO_Export PolicyValueSeq : public 
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<PolicyValue>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
  {
  public:
    PolicyValueSeq (void); // default ctor
    PolicyValueSeq (CORBA::ULong max); // uses max size
    PolicyValueSeq (
        CORBA::ULong max, 
        CORBA::ULong length, 
        PolicyValue *buffer, 
        CORBA::Boolean release = 0
      );
    PolicyValueSeq (const PolicyValueSeq &); // copy ctor
    ~PolicyValueSeq (void);
    static void _tao_any_destructor (void*);
    
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef PolicyValueSeq_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */
    
    
  };
  
#endif /* end #if !defined */
  
  
#if !defined (_MESSAGING_POLICYVALUESEQ___VAR_CH_)
#define _MESSAGING_POLICYVALUESEQ___VAR_CH_
  
  // *************************************************************
  // class Messaging::PolicyValueSeq_var
  // *************************************************************
  
  class TAO_Export PolicyValueSeq_var
  {
  public:
    PolicyValueSeq_var (void);
    PolicyValueSeq_var (PolicyValueSeq *);
    PolicyValueSeq_var (const PolicyValueSeq_var &);
    ~PolicyValueSeq_var (void);
    
    PolicyValueSeq_var &operator= (PolicyValueSeq *);
    PolicyValueSeq_var &operator= (const PolicyValueSeq_var &);
    PolicyValueSeq *operator-> (void);
    const PolicyValueSeq *operator-> (void) const;
    
    operator const PolicyValueSeq &() const;
    operator PolicyValueSeq &();
    operator PolicyValueSeq &() const;
    operator PolicyValueSeq *&(); // variable-size base types only
    
    PolicyValue & operator[] (CORBA::ULong index);
    const PolicyValue & operator[] (CORBA::ULong index) const;
    
    // in, inout, out, _retn 
    const PolicyValueSeq &in (void) const;
    PolicyValueSeq &inout (void);
    PolicyValueSeq *&out (void);
    PolicyValueSeq *_retn (void);
    PolicyValueSeq *ptr (void) const;
  
  private:
    PolicyValueSeq *ptr_;
  };
  
  
#endif /* end #if !defined */
  
  
#if !defined (_MESSAGING_POLICYVALUESEQ___OUT_CH_)
#define _MESSAGING_POLICYVALUESEQ___OUT_CH_
  
  class TAO_Export PolicyValueSeq_out
  {
  public:
    PolicyValueSeq_out (PolicyValueSeq *&);
    PolicyValueSeq_out (PolicyValueSeq_var &);
    PolicyValueSeq_out (const PolicyValueSeq_out &);
    PolicyValueSeq_out &operator= (const PolicyValueSeq_out &);
    PolicyValueSeq_out &operator= (PolicyValueSeq *);
    operator PolicyValueSeq *&();
    PolicyValueSeq *&ptr (void);
    PolicyValueSeq *operator-> (void);
    PolicyValue & operator[] (CORBA::ULong index);
  
  private:
    PolicyValueSeq *&ptr_;
    // Assignment from T_var not allowed.
    void operator= (const PolicyValueSeq_var &);
  };
  
  
#endif /* end #if !defined */
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_PolicyValueSeq;
  
  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_POLICIES;
  
  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong INVOCATION_POLICIES;
  
  
}
TAO_NAMESPACE_CLOSE // module Messaging

TAO_Export void operator<<= (CORBA::Any &, const Messaging::PolicyValue &); // copying version
TAO_Export void operator<<= (CORBA::Any &, Messaging::PolicyValue*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, Messaging::PolicyValue *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Messaging::PolicyValue *&);
TAO_Export void operator<<= (CORBA::Any &, const Messaging::PolicyValueSeq &); // copying version
TAO_Export void operator<<= (CORBA::Any &, Messaging::PolicyValueSeq*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, Messaging::PolicyValueSeq *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Messaging::PolicyValueSeq *&);

#ifndef __ACE_INLINE__

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const Messaging::PolicyValue &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, Messaging::PolicyValue &);

#if !defined _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_H_
#define _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const Messaging::PolicyValue::_tao_seq_Octet &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    Messaging::PolicyValue::_tao_seq_Octet &
  );

#endif /* _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_H_ */


#if !defined _TAO_CDR_OP_Messaging_PolicyValueSeq_H_
#define _TAO_CDR_OP_Messaging_PolicyValueSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const Messaging::PolicyValueSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    Messaging::PolicyValueSeq &
  );

#endif /* _TAO_CDR_OP_Messaging_PolicyValueSeq_H_ */


#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "Messaging_PolicyValueC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */
