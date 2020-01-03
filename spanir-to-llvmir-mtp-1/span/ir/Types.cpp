//
// Created by codeman on 19/6/19.
//

#include "Types (copy).h"

using namespace span::ir::types;
using namespace span;


//
// Created by codeman on 19/6/19.
//

Type::Type(BasicTypeKinds typeCode): typeCode{typeCode} {}

BasicTypeKinds Type::getTypeCode() 
{
  return typeCode;
}

bool Type::isInteger()
{
  return (typeCode>=TY_INT1 && typeCode<=TY_UINT64);
}

bool Type::isUnsigned()
{
  return (typeCode==TY_UINT8 ||typeCode==TY_UINT16 || typeCode==TY_UINT32 ||      typeCode==TY_UINT64);
}

bool Type::isFloat(){
  return (typeCode>=TY_FLOAT32 && typeCode<=TY_FLOAT128);
}

bool Type::isNumeric(){
  return (typeCode>=TY_INT1 && typeCode<=TY_FLOAT128);
} 

bool  Type::isPointer(){
  return (typeCode==TY_PTR);
}

bool Type::isFunc(){
  return (typeCode==TY_FUNCTION);
}

bool Type::isStruct(){
  return (typeCode==TY_STRUCT);
}

bool Type::isVoid(){
  return (typeCode==TY_VOID);
}

/*bool operator==(Type &other) //incomplete
{ 
      if(typeCode==other.typeCode)
        return true;
      else 
        return false;
}*/

// MyMap::MyMap(){}
// unordered_map <int, string> MyMap::Initialise_Map(){
//   edge_record.insert({0,"False Edge"});
//   edge_record.insert({1,"True Edge"});
//   edge_record.insert({2,"Uncond Edge"});
// }


  
PointerType::PointerType(Type *to,std::int32_t indlev) : to{to}, indlev{indlev},Type(TY_PTR){}



FunctionType::FunctionType(Type *returnType,
  ParamTypes paramTypes, bool variadic) :
returnType{returnType}, paramTypes{paramTypes}, variadic{variadic},Type(TY_FUNCTION){
}

const Type& FunctionType::getReturnType() {
  return *returnType;
}

void FunctionType::setReturnType(Type *returnType) {
  // NOTE: make sure there is no memory leak
  this->returnType=returnType;
}

const ParamTypes& FunctionType::getParamTypes() {
  return paramTypes;
}

bool FunctionType::isVariadic() {
  return variadic;
}

/// Pretty print.
//void FunctionType::print();


Record::Record(bool isStruct, std::string name,
  RecordFields fields): _isStruct{isStruct}, name{name}, fields{fields},Type(_isStruct?TY_STRUCT:TY_UNION){
}

/// True if the record is a struct.
bool Record::isStruct() {return _isStruct;}

/// True if the record is a union.
bool Record::isUnion() {return !_isStruct;}

/// Get the name of the record.
const std::string& Record::getName() 
  {return name;}

void Record::setName(std::string name) {
  this->name = name;
}

RecordFields& Record::getFields() {
  return this->fields;
}

/// Pretty print the record.
//void Record::print();

 


// definition of type classes go here.
