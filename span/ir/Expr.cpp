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

UnitExpr::UnitExpr(types::Type *type, BasicExprKinds exprCode):Expr(type, exprCode)
{} //constructor          

VarExpr::VarExpr(std::string name,types::Type *type):name{name},UnitExpr(type, EX_VAR_EXPR)
{} // constructor

BinaryExpr::BinaryExpr(op::BinaryOperatorKind opCode, UnitExpr *operand1, UnitExpr *operand2):opCode{opCode},operand1{operand1},operand2{operand2},
Expr((operand1->getTypeCode() > operand2->getTypeCode())?operand1->getType():operand2->getType(), EX_BINARY_EXPR)
{}

UnaryExpr::UnaryExpr(op::UnaryOperatorKind opCode,UnitExpr *operand):opCode{opCode},operand{operand},Expr(operand->getType(), EX_UNARY_EXPR)
{}          