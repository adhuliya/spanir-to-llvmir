//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#include "Types (copy).h"
#include "Objects (copy).h"
#include "TUnit (copy).h"

using namespace std;
using namespace span::ir::tunit;
using namespace span;


TUnit::TUnit(std::string name, std::string description,
  VarMap&& varMap, FuncMap funcMap) :
  name{name}, description{description},
  varMap{varMap}, funcMap{funcMap}
  //recordMap{recordMap} 
  {}

/// Get TUnit name, generally the filename.
const std::string& TUnit::getName() 
{
  return name;
}

/// Set TUnit name, generally the filename.
void TUnit::setName(std::string name) 
{
  this->name = name;
}


/// \param description an optional description of the translation unit

// checking
void TUnit::show()
{
  std::cout<<"hello hello from TUnit\n";
}

