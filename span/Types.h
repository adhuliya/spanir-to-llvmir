//
// Created by codeman on 19/6/19.
//

#ifndef SPAN_TYPES_H
#define SPAN_TYPES_H

#include <string>
#include <vector>
#include <iostream>

#define BASICTYPE(name, description) TY_##name,

namespace span {
  // Some global typedefs
  using BasicBlockId = int32_t
  using CFGNodeId = int32_t;
  using VarName = std::string;
  using FunctionName = std::string;
  using RecordName = std::string;

  namespace ir {
    namespace types {
      enum BasicTypeKinds {
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

      class Type {
      public:
        Type(BasicTypeKinds typeCode): typeCode{typeCode} {}

        BasicTypeKinds getTypeCode() {
          return typeCode;
        }

        virtual void print() {
          std::cout << "BasicType: " << typeCode;
        }

      private:
        BasicTypeKinds typeCode;
      };
    } // end namespace types
  } // end namespace ir

  using RecordField = std::pari<std::string, Type*>;
  using RecordFields = std::vector<RecordField>;
  using ParamsTypes = std::vector<Type*>;

  namespace ir {
    namespace types {

      class PointerType : public Type {
      public:
        PointerType(Type *to,
            int32_t indlev) : to{to}, indlev{indlev} {
        }

      private:
        Type *to;
        int32_t indlev; /// indirection level
      };

      class FunctionType : public Type {
      public:
        FunctionType(Type *returnType,
            ParamTypes paramTypes, bool variadic) :
            returnType{returnType}, paramTypes{paramTypes}, variadic{variadic} {
        }

        const Type& getReturnType() {
          return *returnType;
        }

        void setReturnType(const Type *returnType) {
          // NOTE: make sure there is no memory leak
          this->returnType = returnType;
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
            RecordFields fields): _isStruct{isStruct}, name{name}, fields{fields} {
        }

        /// True if the record is a struct.
        bool isStruct() {return _isStruct;}

        /// True if the record is a union.
        bool isUnion() {return !_isStruct;}

        /// Get the name of the record.
        const std::string& getName() {return name;}

        void setName(std::string name) {
          return this->name = name;
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

