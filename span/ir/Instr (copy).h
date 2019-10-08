//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#ifndef SPAN_INSTR_H
#define SPAN_INSTR_H
#include "Expr (copy).h"
#include "Types (copy).h"
#define BASICINSTR(name) INS_##name,


namespace span {
  namespace ir {
    /// The instructions (three-address).
    namespace instr {

      enum BasicInstrKinds 
      {
        BASICINSTR(NOP_INSTR)
        BASICINSTR(BLOCK_ALL_INSTR)
        BASICINSTR(USE_INSTR)
        BASICINSTR(COND_READ_INSTR)
        BASICINSTR(UNDEF_VAL_INSTR)
        BASICINSTR(LIVE_INSTR)
        BASICINSTR(EX_READ_INSTR)
        BASICINSTR(ASSIGN_INSTR)
        BASICINSTR(RETURN_INSTR)
        BASICINSTR(CALL_INSTR)
        BASICINSTR(COND_INSTR)
        BASICINSTR(GOTO_INSTR)
      };

      class InstrT 
      {
        BasicInstrKinds InstrCode;
      public:
        InstrT(BasicInstrKinds InstrCode);

        string print()
        {
          string s="";
          s += to_string(InstrCode) + " tttt ";  
          return s;
        }
      };

      class AssignI : public InstrT {
        expr::VarExpr *lhs;
        expr::Expr *rhs;
      public:
         AssignI(expr::VarExpr *lhs,expr::Expr *rhs);

         string print()
         {
            string s="";
            s += lhs->print() + " " + rhs->print()+" ";  
            return s;
         }
      };

      class CallI : public InstrT {
      public:
      };

      class ReturnI : public InstrT {
        expr::Expr *inst;
      public:
         ReturnI(expr::Expr *inst);

         string print()
         {
            string s="";
            s += inst->print() + " ";  
            return s;
         }
      };

    } // end namespace instr
  } // end namespace ir
} // end namespace span

#endif //SPAN_INSTR_H
