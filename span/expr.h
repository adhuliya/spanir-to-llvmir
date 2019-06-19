//
// Created by codeman on 19/6/19.
//

#ifndef SPAN_EXPR_H
#define SPAN_EXPR_H

#include "OperationKinds.h"

namespace span {
  namespace ir {
    namespace expr {
      class Expr {
        Type *type;
      };

      class UnitExpr : public Expr {

      };

      class VarExpr : public UnitExpr {
        std::string name;
      };

      class BinaryExpr : public Expr {
        BinaryOperatorKind opCode;
        Expr *operand1;
        Expr *operand2;
      };

      class UnaryExpr : public Expr {
        UnaryOperatorKind opCode;
        Expr *operand;
      };

    } // end namespace expr
  } // end namespace ir
} // end namespace span

#endif //SPAN_EXPR_H
