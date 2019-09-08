//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#ifndef SPAN_EXPR_H
#define SPAN_EXPR_H

#include "OpKinds.h"
#include "Types.h"

#define BASICEXPR(name) EX_##name,


namespace span 
{
  namespace ir 
  {
    /// The expressions used in instructions.
    namespace expr 
    {

      enum BasicExprKinds 
      {
        BASICEXPR(VAR_EXPR)
        BASICEXPR(LIT_EXPR)
        BASICEXPR(FUNC_EXPR)
        BASICEXPR(UNARY_EXPR)
        BASICEXPR(CAST_EXPR)
        BASICEXPR(BASIC_EXPR)
        BASICEXPR(ADDROF_EXPR)
        BASICEXPR(SIZEOF_EXPR)
        BASICEXPR(BINARY_EXPR)
        BASICEXPR(ARR_EXPR)
        BASICEXPR(CALL_EXPR)
        BASICEXPR(PTRCALL_EXPR)
        BASICEXPR(MEMBER_EXPR)
        BASICEXPR(PHI_EXPR)
        BASICEXPR(SELECT_EXPR)
        BASICEXPR(ALLOC_EXPR)
      };

      class Expr 
      {
        types::Type *type;
        
      public:
        Expr(types::Type *type): type{type}{} //constructor
        void print(){type->print();}
        types::Type* getType(){return type;}
        types::BasicTypeKinds getTypeCode(){return type->getTypeCode();}
        
        
      };

      class UnitExpr : public Expr 
      {
      public:
          UnitExpr(types::Type *type):Expr(type){} //constructor          
          
        };

        class VarExpr : public UnitExpr 
        {
          std::string name;
        public:
        VarExpr(std::string name,types::Type *type):name{name},UnitExpr(type){} // constructor
        
        
      };

      class LitExpr : public UnitExpr  //incomplete
      { 
        union val
        {
          int i;
          float f;
        };
      public: 
      };

      class BinaryExpr : public Expr 
      {
        op::BinaryOperatorKind opCode;
        UnitExpr *operand1;
        UnitExpr *operand2;

      public:
        BinaryExpr(op::BinaryOperatorKind opCode, UnitExpr *operand1, UnitExpr          *operand2):opCode{opCode},operand1{operand1},operand2{operand2},
        Expr((operand1->getTypeCode()>operand2->getTypeCode())?operand1-           >getType():operand2->getType()){}
        
      };

      class UnaryExpr : public Expr {
        op::UnaryOperatorKind opCode;
        UnitExpr *operand;

      public:
        UnaryExpr(op::UnaryOperatorKind opCode,UnitExpr *operand):opCode{opCode},operand{operand},Expr(operand->getType()){}  
        
      };

        } // end namespace expr
    } // end namespace ir
} // end namespace span

#endif //SPAN_EXPR_H
