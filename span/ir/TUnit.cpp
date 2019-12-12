//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//
#include <bits/stdc++.h>
#include "Types (copy).h"
#include "Objects (copy).h"
#include "TUnit (copy).h"

using namespace std;
using namespace span::ir::tunit;
using namespace span;
using namespace span::ir;


TUnit::TUnit(std::string name, std::string description,
  VarMap&& varMap, FuncMap funcMap) :
  name{name}, description{description},
  varMap{varMap}, funcMap{funcMap}
  //recordMap{recordMap} 
  {
    //types::MyMap mymap();
  }

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


/// Get TUnit (optional) description
std::string TUnit::getDescription()
{
  return description;
}

/// Set TUnit (optional) description
/// \param description an optional description of the translation unit
void TUnit::setDescription(std::string description)
{
  this->description = description;
}

// checking
vector<string> TUnit::Ret_String()
{
  v.push_back("***      First Argument::test Case name:-    ***");
  v.push_back(getName());
  v.push_back("***      Second Argument::Input Prigram Desc:-     ***");
  v.push_back(getDescription());
  v.push_back("***      Third Argument::All Vars:-         ***");
  v.push_back("*** program vars (START)***");
  for(auto x : varMap)
  {
    v.push_back(x.first + "  typecode is = " + (x.second->print()));

  } 
  v.push_back("*** program vars (END)***");

  v.push_back("***      Fourth Argument::All Func Desc:-      ***");
  v.push_back("*** funcion description (START)***");
  for(auto x : funcMap)
  {
    v.push_back(x.first + " :: " + x.second.print());
  } 
  v.push_back("*** funcion description (END)***");
  return v;
}

