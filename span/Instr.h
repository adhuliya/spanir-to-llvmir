//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#ifndef SPAN_INSTR_H
#define SPAN_INSTR_H
#include "Expr.h"


namespace span {
  namespace ir {
    /// The instructions (three-address).
    namespace instr {
      class InstrT {
      public:
      };

      class AssignI : public InstrT {
        expr::VarExpr *lhs;
        expr::Expr *rhs;
      public:
         AssignI(expr::VarExpr *lhs,expr::VarExpr *rhs):lhs{lhs},rhs{rhs}{}
         
         
      };

      class CallI : public InstrT {
      public:
          
      };

      class ReturnI : public InstrT {
        expr::Expr *inst;
      public:
         ReturnI(expr::Expr *inst):inst{inst}{}
          
      };

    } // end namespace instr
  } // end namespace ir
} // end namespace span

#endif //SPAN_INSTR_H
