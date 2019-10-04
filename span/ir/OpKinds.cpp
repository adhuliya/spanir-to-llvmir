//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//


#include "OpKinds (copy).h"
using namespace span::ir::op;


     
BinaryOp::BinaryOp(BinaryOperatorKind opCode): opCode{opCode} {}

BinaryOperatorKind BinaryOp::getOpCode() 
{
  return opCode;
}


bool BinaryOp::isBinaryOp()
{
  return (opCode>=BO_NUM_START_OC && opCode<=BO_MOD_OC);
}

virtual void BinaryOp::print() 
{
  std::string s="";
  if(opCode == BO_ADD_OC)
    s = "+";
  else if(opCode == BO_SUB_OC)
    s = "-";
  else if(opCode == BO_MUL_OC)
    s = "*";
  else if(opCode == BO_DIV_OC)
    s = "/";
  else if(opCode == BO_MOD_OC)
    s = "%";

  std::cout << "BasicOp: " << s;
}

  //BinaryOp operator = (Complex const &obj)


/// ******************************   OBJECTS    **************************************//// 

BinaryOp BO_ADD(BO_ADD_OC); 
BinaryOp BO_SUB(BO_SUB_OC); 
BinaryOp BO_MUL(BO_MUL_OC); 
BinaryOp BO_DIV(BO_DIV_OC); 
BinaryOp BO_MOD(BO_MOD_OC);