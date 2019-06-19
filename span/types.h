//
// Created by codeman on 19/6/19.
//

#ifndef SPAN_TYPES_H
#define SPAN_TYPES_H

#include <string>
#include <vector>

#define BASICTYPE(name, description) TY_##name,
namespace span {
  // Some global typedefs
  typedef int32_t BasicBlockId;
  typedef int32_t CFGNodeId;
  typedef std::string VarName;
  typedef std::string FunctionName;
  typedef std::string RecordName;

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
        BasicTypeKind typeCode;
      };

      class Function : public Type {
        Type *returnType;
        std::vector<Type*> params;
        bool variadic;
      public:
      };

      class Record : public Type {
        bool isStruct; // false for union, true for struct
        std::string name;
        std::vector<std::pair<std::string, Type*>> fields;
      public:
      };
    } // end namespace types
  } // end namespace ir
} // end namespace span

#endif //SPAN_TYPES_H

