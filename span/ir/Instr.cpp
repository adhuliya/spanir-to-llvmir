//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//


#include "Expr (copy).h"
#include "Types (copy).h"
#include "Instr (copy).h"
using namespace span::ir::instr;
using namespace span;

InstrT::InstrT(BasicInstrKinds InstrCode) : InstrCode{InstrCode}{}

AssignI::AssignI(expr::VarExpr *lhs,expr::Expr *rhs):lhs{lhs},rhs{rhs}, InstrT(INS_ASSIGN_INSTR){}
 

ReturnI::ReturnI(expr::Expr *inst):inst{inst}, InstrT(INS_RETURN_INSTR){}
          
      