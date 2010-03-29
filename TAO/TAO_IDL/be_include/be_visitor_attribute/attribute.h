/* -*- c++ -*- */

//=============================================================================
/**
 *  @file    attribute.h
 *
 *  $Id$
 *
 *  Visitor for the Attribute class.
 *
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================


#ifndef _BE_VISITOR_ATTRIBUTE_ATTRIBUTE_H
#define _BE_VISITOR_ATTRIBUTE_ATTRIBUTE_H

// ************************************************************
// Attribute visitor
// ************************************************************

/**
 * @class be_visitor_attribute
 *
 * @brief be_visitor_attribute
 *
 * This is a concrete visitor to generate code for attributes. We have one
 * class for mapping into the client and server.
 */
class be_visitor_attribute : public be_visitor_decl
{
public:
  /// constructor
  be_visitor_attribute (be_visitor_context *ctx);

  /// destructor
  ~be_visitor_attribute (void);

  /// visit attribute. We provide code for this method in the derived class
  virtual int visit_attribute (be_attribute *node);

  void for_facets (bool val);
  void op_scope (be_decl *node);
  void port_prefix (ACE_CString &prefix);

private:
  bool for_facets_;
  be_decl *op_scope_;
  ACE_CString port_prefix_;
};

#endif /* _BE_VISITOR_ATTRIBUTE_ATTRIBUTE_H*/
