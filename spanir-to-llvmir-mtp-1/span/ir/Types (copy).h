//
// Created by codeman on 19/6/19.
//

#ifndef SPAN_TYPES_H
#define SPAN_TYPES_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
#include <cstdint>
using namespace std;
#define BASICTYPE(name, description) TY_##name,

namespace span 
{
  // Some global typedefs
  using VarName = std::string;
  using LabelName = std::string;
  using FunctionName = std::string;
  using RecordName = std::string;
  using StructName = std::string;

  using TypeCode = int32_t;

  using OpSymbol = std::string;
  using OpName = std::string;

  using Numeric = int32_t;
  using Lit = int32_t;


  using BasicBlockId = int32_t;
  using CFGNodeId = int32_t;
  using EdgeLabel = std::string;

  using Ret_Str = std::string;

  // edge labels 
  // EdgeLabel FalseEdge = "None";  // False edge 
  // EdgeLabel TrueEdge = "None";  // True edge 
  // EdgeLabel UnCondEdge = "UnCondEdge";  // Unconditional edge 

// source location line:col given by user (only used to communicate back) 
// this is a 64 bit integer

  using SourceLocation = int64_t; 

  namespace ir 
  {
    namespace types 
    {
      enum BasicTypeKinds 
      {
        BASICTYPE(VOID, "void type")
        BASICTYPE(INT1, "1 bit integer")
        BASICTYPE(INT8, "8 bit signed integer")
        BASICTYPE(UINT8, "8 bit unsigned integer")
        BASICTYPE(INT16, "16 bit signed integer")
        BASICTYPE(UINT16, "16 bit unsigned integer")
        BASICTYPE(INT32, "32 bit signed integer")
        BASICTYPE(UINT32, "32 bit unsigned integer")
        BASICTYPE(INT64, "64 bit signed integer")
        BASICTYPE(UINT64, "64 bit unsigned integer")
        BASICTYPE(FLOAT32, "32 bit float")
        BASICTYPE(FLOAT64, "64 bit float")
        BASICTYPE(FLOAT128, "128 bit float")
        BASICTYPE(PTR, "Pointer type")
        BASICTYPE(FUNCTION, "A Function")
        BASICTYPE(STRUCT, "A Structure Type")
        BASICTYPE(UNION, "A Union Type")
      };

      class Type 
      {
      public:
        Type(BasicTypeKinds typeCode);

        BasicTypeKinds getTypeCode(); 
        
        virtual string print()
        {
          std::string s="";
          if(typeCode == TY_VOID)
            s = "VOID";
          else if(typeCode == TY_INT1)
            s = "INT1";
          else if(typeCode == TY_INT8)
            s = "INT8";
          else if(typeCode == TY_UINT8)
            s = "UINT8";
          else if(typeCode == TY_INT16)
            s = "INT16";
          else if(typeCode == TY_UINT16)
            s = "UINT16";
          else if(typeCode == TY_INT32)
            s = "INT32";
          else if(typeCode == TY_UINT32)
            s = "UINT32";
          else if(typeCode == TY_INT64)
            s = "INT64";
          else if(typeCode == TY_UINT64)
            s = "UINT64";
          else if(typeCode == TY_FLOAT32)
            s = "FLOAT32";
          else if(typeCode == TY_FLOAT64)
            s = "FLOAT64";
          else if(typeCode == TY_FLOAT128)
            s = "FLOAT128";
          else if(typeCode == TY_PTR)
            s = "PTR";
          else if(typeCode == TY_FUNCTION)
            s = "FUNCTION";
          else if(typeCode == TY_STRUCT)
            s = "STRUCT";
          else if(typeCode == TY_UNION)
            s = "UNION";

          //std::cout << "BasicType: " << s;
          return s;
        } 
        

        bool isInteger();

        bool isUnsigned();

        bool isFloat();

        bool isNumeric();

        bool isPointer();

        bool isFunc();

        bool isStruct();

        bool isVoid();

        /*bool operator==(Type &other) //incomplete
        { 
              if(typeCode==other.typeCode)
                return true;
              else 
                return false;
        }*/

      private:
        BasicTypeKinds typeCode;
      };

      // class MyMap{
      //   public:
      //     unordered_map <int, string> edge_record;
      //     MyMap();
      //     unordered_map <int, string> Initialise_Map();
      // };
    } // end namespace types
  } // end namespace ir


  using RecordField = std::pair<std::string, ir::types::Type*>;
  using RecordFields = std::vector<RecordField>;
  using ParamTypes = std::vector<ir::types::Type*>;

  namespace ir {
    namespace types {

      class PointerType : public Type {
      public:
        PointerType(Type *to,std::int32_t indlev);

        string print()
        {
          string s = "";
          s += to->print() + " indlev= " + to_string(indlev) + " ";
          return s;
        }

      private:
        Type *to;
        std::int32_t indlev; /// indirection level
      };

      class FunctionType : public Type {
      public:
        FunctionType(Type *returnType,
          ParamTypes paramTypes, bool variadic);

        const Type& getReturnType();

        void setReturnType(Type *returnType);

        const ParamTypes& getParamTypes();

        bool isVariadic();
        long long ll = 1;

        /// Pretty print.
        string print()
        {
          string s = "";
          s += "ret_type = " + returnType->print() + " ";
          for(auto x : paramTypes)
          {
            s += "paramtypes" + to_string(ll) + "= " + x->print() + " ";
            ll++;
          }
          s += "isVariadic= " + to_string(variadic) + " ";
          return s;
        }

      private:
        Type *returnType;
        ParamTypes paramTypes;
        bool variadic;
      }; // end class FunctionType

      class Record : public Type {
      public:
        Record(bool isStruct, std::string name,
          RecordFields fields);

        /// True if the record is a struct.
        bool isStruct();
        /// True if the record is a union.
        bool isUnion();

        /// Get the name of the record.
        const std::string& getName();

        void setName(std::string name);


        RecordFields& getFields();
        

        /// Pretty print the record.
        string print()
        {
          Ret_Str s = "";
          if(_isStruct)
          {
            s += "Struct ";
          }
          else
            s += "Union ";

          s += "name= " + name + " fields det= ";

          for(auto x : fields)
            s += x.first + " typ= " + x.second->print() + " "; 

          return s;
        }

      private:
        bool _isStruct; // false for union, true for struct
        std::string name;
        RecordFields fields;
      };
    } // end namespace types
  } // end namespace ir


} // end namespace span
#endif //SPAN_TYPES_H
