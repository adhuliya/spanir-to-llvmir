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
using namespace span;
//using namespace span::ir::object;
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

        virtual string print()
        {
          string s="";  
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
          s += "lhs:: " + lhs->print() + " ::  rhs:: " + rhs->print()+" ::";   
          return s;
        }
      };

      class CallI : public InstrT {
        expr::Expr *inst;
        public:
          CallI(expr::Expr *inst);

          string print()
          {
            string s="";
            s += inst->print() + " ";
            return s;
          }        
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

      class CondI : public InstrT {
          //  A conditional instruction.  //
        expr::Expr *inst; 
        //LabelName trueLabel = "None";
        //LabelName falseLabel = "None";
        //EdgeKind falseLabel;
        //EdgeKind trueLabel;

        public :
          CondI(expr::Expr *inst); 

          string print()
          {
            string s="";
            s += inst->print() + " ";  
            return s;
          } 
      };
    
  /*
  """"""
  def __init__(self,
               arg: expr.UnitET,
               trueLabel: types.LabelNameT = None,
               falseLabel: types.LabelNameT = None,
               loc: Optional[types.Loc] = None
  ) -> None:
    super().__init__(COND_INSTR_IC, loc)
    self.arg = arg
    self.trueLabel = trueLabel
    self.falseLabel = falseLabel
  */
    } // end namespace instr
  } // end namespace ir
} // end namespace span

#endif //SPAN_INSTR_H
