//
// Created by codeman on 19/6/19.
//

#ifndef SPAN_TYPES_H
#define SPAN_TYPES_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdint>
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

  // edge labels 
  EdgeLabel FalseEdge = "FalseEdge";  // False edge 
  EdgeLabel TrueEdge = "TrueEdge";  // True edge 
  EdgeLabel UnCondEdge = "UnCondEdge";  // Unconditional edge 

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
        Type(BasicTypeKinds typeCode): typeCode{typeCode} {}

        BasicTypeKinds getTypeCode() 
        {
          return typeCode;
        }

        
        virtual void print() 
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

          std::cout << "BasicType: " << s;
        }

        bool isInteger()
        {
          return (typeCode>=TY_INT1 && typeCode<=TY_UINT64);
        }

        bool isUnsigned()
        {
          return (typeCode==TY_UINT8 ||typeCode==TY_UINT16 || typeCode==TY_UINT32 ||      typeCode==TY_UINT64);
        }

        bool isFloat(){
          return (typeCode>=TY_FLOAT32 && typeCode<=TY_FLOAT128);
        }

        bool isNumeric(){
          return (typeCode>=TY_INT1 && typeCode<=TY_FLOAT128);
        } 

        bool  isPointer(){
          return (typeCode==TY_PTR);
        }

        bool isFunc(){
          return (typeCode==TY_FUNCTION);
        }

        bool isStruct(){
          return (typeCode==TY_STRUCT);
        }

        bool isVoid(){
          return (typeCode==TY_VOID);
        }

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
    } // end namespace types
  } // end namespace ir


  using RecordField = std::pair<std::string, ir::types::Type*>;
  using RecordFields = std::vector<RecordField>;
  using ParamTypes = std::vector<ir::types::Type*>;

  namespace ir {
    namespace types {

      class PointerType : public Type {
      public:
        PointerType(Type *to,std::int32_t indlev) : to{to}, indlev{indlev},Type(TY_PTR){}

      private:
        Type *to;
        std::int32_t indlev; /// indirection level
      };

      class FunctionType : public Type {
      public:
        FunctionType(Type *returnType,
          ParamTypes paramTypes, bool variadic) :
        returnType{returnType}, paramTypes{paramTypes}, variadic{variadic},Type(TY_FUNCTION){
        }

        const Type& getReturnType() {
          return *returnType;
        }

        void setReturnType(Type *returnType) {
          // NOTE: make sure there is no memory leak
          this->returnType=returnType;
        }

        const ParamTypes& getParamTypes() {
          return paramTypes;
        }

        bool isVariadic() {
          return variadic;
        }

        /// Pretty print.
        void print();

      private:
        Type *returnType;
        ParamTypes paramTypes;
        bool variadic;
      }; // end class FunctionType

      class Record : public Type {
      public:
        Record(bool isStruct, std::string name,
          RecordFields fields): _isStruct{isStruct}, name{name}, fields{fields},Type(_isStruct?TY_STRUCT:TY_UNION){
        }

        /// True if the record is a struct.
        bool isStruct() {return _isStruct;}

        /// True if the record is a union.
        bool isUnion() {return !_isStruct;}

        /// Get the name of the record.
        const std::string& getName() {return name;}

        void setName(std::string name) {
          this->name = name;
        }

        RecordFields& getFields() {
          return this->fields;
        }

        /// Pretty print the record.
        void print();

      private:
        bool _isStruct; // false for union, true for struct
        std::string name;
        RecordFields fields;
      };
    } // end namespace types
  } // end namespace ir


} // end namespace span
#endif //SPAN_TYPES_H
