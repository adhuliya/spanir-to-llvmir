//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#ifndef SPAN_EXPR_H
#define SPAN_EXPR_H

#include "OpKinds (copy).h"
#include "Types (copy).h"

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
        BasicExprKinds exprCode;
      public:
        Expr(types::Type *type,BasicExprKinds exprCode); //constructor
        virtual string print()
        {
          string s="";
          return s;
        }
        types::Type* getType();
        types::BasicTypeKinds getTypeCode();
        
        
      };

      class UnitExpr : public Expr 
      {
        //string name;
        types::Type *type;
        BasicExprKinds exprCode;
      public:
        UnitExpr(types::Type *type, BasicExprKinds exprCode); //constructor    
        virtual string print()
        {
          string s="";
          s += "type-" + type->print()+" ";
          return s;
        }      
          
      };

      class VarExpr : public UnitExpr 
      {
        std::string name;
        types::Type *type;
      public:
        VarExpr(std::string name,types::Type *type); // constructor
        
        string print()
        {
          string s="";
          s += "name-" + name + " type-" + type->print()+" ";
          return s;
        }
      };

      class LitExpr : public UnitExpr  //incomplete
      {
        types::Type *type;
        union val
        {
          int i;
          float f;
        }v;
        public:
          LitExpr(float val,types::Type *type);

          string print()
          {
            string s="";
            //s += "valint=" + to_string(v.i) + "  valfloat=" + to_string(v.f) + 
            if(type->isInteger())
              s += "val_int=" + to_string(v.i) + "  ";
            else
              s += "val_float=" + to_string(v.f) + "  ";
            s += "type-" + type->print()+" ";
            return s;
          }
      };

      class BinaryExpr : public Expr 
      {
        op::BinaryOperatorKind opCode;
        UnitExpr *operand1;
        UnitExpr *operand2;
      public:
        BinaryExpr(UnitExpr *operand1, op::BinaryOperatorKind opCode, UnitExpr *operand2);
        string print()
        {
          string s="";
          s += "op1-" + operand1->print() + " operator-" + to_string(opCode) + " op2-" + operand2->print();
          return s;
        }
      };

      class UnaryExpr : public UnitExpr {
      public:
        std::string name;
        op::UnaryOperatorKind opCode;
        UnitExpr *operand;

      public:
        UnaryExpr(std::string name, op::UnaryOperatorKind opCode, UnitExpr *operand);  
        
        string print()
        {
          string s="";
          s += "name-" + name +" Unary_opcode-" + to_string(opCode) + " operand-" + operand->print();
          return s;
        }
      };

    } // end namespace expr
  } // end namespace ir
} // end namespace span

#endif //SPAN_EXPR_H
