//
// Created by codeman on 19/6/19.
//

#ifndef SPAN_OPERATIONKINDS_H
#define SPAN_OPERATIONKINDS_H

namespace span {
  namespace ir {
    namespace op {

      /// CastKind - The kind of operation required for a conversion.
      enum CastKind {
        #define CAST_OPERATION(Name) CK_##Name,

        #include "OperationKinds.def"
      };

      enum BinaryOperatorKind {
        #define BINARY_OPERATION(Name, Spelling) BO_##Name,

        #include "OperationKinds.def"
      };

      enum UnaryOperatorKind {
        #define UNARY_OPERATION(Name, Spelling) UO_##Name,

        #include "OperationKinds.def"
      };
    } // end namespace op
  } // end namespace ir
}  // end namespace span

#endif

#endif //SPAN_OPERATIONKINDS_H
