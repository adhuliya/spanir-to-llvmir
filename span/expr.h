//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#ifndef SPAN_EXPR_H
#define SPAN_EXPR_H

#include "opKinds.h"

namespace span {
  namespace ir {
    /// The expressions used in instructions.
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
