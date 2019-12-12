//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#include "OpKinds (copy).h"
#include "Types (copy).h"
#include "Expr (copy).h"
using namespace span::ir::expr; 
using namespace span;



Expr::Expr(types::Type *type,BasicExprKinds exprCode): type{type}, exprCode{exprCode} //constructor
{}

ir::types::Type* Expr::getType()
{
  return type;
}

ir::types::BasicTypeKinds Expr::getTypeCode()
{
  return type->getTypeCode();
}

UnitExpr::UnitExpr(types::Type *type, BasicExprKinds exprCode):type{type},exprCode{exprCode},Expr(type, exprCode)
{} //constructor          

VarExpr::VarExpr(std::string name,types::Type *type):name{name}, type{type},UnitExpr(type, EX_VAR_EXPR)
{} // constructor

LitExpr::LitExpr(float val, types::Type *type):type{type}, UnitExpr(type, EX_LIT_EXPR){
	if(type->isInteger())
		v.i = val;
	else
		v.f = val;
} //constructor

BinaryExpr::BinaryExpr(UnitExpr *operand1, op::BinaryOperatorKind opCode, UnitExpr *operand2):operand1{operand1},opCode{opCode},operand2{operand2},
Expr((operand1->getTypeCode() > operand2->getTypeCode())?operand1->getType():operand2->getType(), EX_BINARY_EXPR)
{}

UnaryExpr::UnaryExpr(std::string name, op::UnaryOperatorKind opCode,UnitExpr *operand):name{name}, opCode{opCode},operand{operand},UnitExpr(operand->getType(), EX_UNARY_EXPR)
{}          