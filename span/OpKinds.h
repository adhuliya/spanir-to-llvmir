//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#ifndef SPAN_OPKINDS_H
#define SPAN_OPKINDS_H
#include "OpKinds.def"

#define CAST_OPERATION(Name) CK_##Name,
#define BINARY_OPERATION(Name, Spelling) BO_##Name,
#define UNARY_OPERATION(Name, Spelling) UO_##Name,


/// Encapsulates all of SPAN
namespace span {
  /// Contains all of SPAN IR
  namespace ir {
    /// The operators used in expressions
    namespace op {

      /// CastKind - The kind of operation required for a conversion.
      enum CastKind {
     
      };

      /// All binary operators
  enum BinaryOperatorKind {
        BINARY_OPERATION(NUM_START_OC, 200)
        BINARY_OPERATION(ADD_OC, 201)
	BINARY_OPERATION(SUB_OC, 202)
	BINARY_OPERATION(MUL_OC, 203)
	BINARY_OPERATION(DIV_OC, 204)
	BINARY_OPERATION(MOD_OC, 205)
      };

      /// All unary operators
 enum UnaryOperatorKind {
  UNARY_OPERATION(PLUS_OC, 101)
	UNARY_OPERATION(MINUS_OC, 102)
	UNARY_OPERATION(ADDROF_OC, 103)
	UNARY_OPERATION(DEREF_OC, 104)
	UNARY_OPERATION(SIZEOF_OC, 105)
	UNARY_OPERATION(BIT_NOT_OC, 110)
	UNARY_OPERATION(LNOT_OC, 120)
	UNARY_OPERATION(CAST_OC, 130)
      };

    } // end namespace op
  } // end namespace ir
}  // end namespace span



#endif //SPAN_OPKINDS_H
