//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#ifndef SPAN_OPKINDS_H
#define SPAN_OPKINDS_H

/// Encapsulates all of SPAN
namespace span {
  /// Contains all of SPAN IR
  namespace ir {
    /// The operators used in expressions
    namespace op {

      /// CastKind - The kind of operation required for a conversion.
      enum CastKind {
        #define CAST_OPERATION(Name) CK_##Name,

        #include "OpKinds.def"
      };

      /// All binary operators
      enum BinaryOperatorKind {
        #define BINARY_OPERATION(Name, Spelling) BO_##Name,

        #include "OpKinds.def"
      };

      /// All unary operators
      enum UnaryOperatorKind {
        #define UNARY_OPERATION(Name, Spelling) UO_##Name,

        #include "OpKinds.def"
      };
    } // end namespace op
  } // end namespace ir
}  // end namespace span

#endif

#endif //SPAN_OPKINDS_H
