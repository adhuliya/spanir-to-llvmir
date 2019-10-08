//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#ifndef SPAN_TUNIT_H
#define SPAN_TUNIT_H

#include <bits/stdc++.h>
#include "Types (copy).h"
#include "Objects (copy).h"

#include <unordered_map>
#include <string>
using namespace std;

namespace span {
  namespace ir {
    namespace tunit {
      /// The variables in a translation unit.
      using VarMap = std::unordered_map<span::VarName, types::Type*>;
      /// The functions declared/defined in a translation unit.
      using FuncMap = std::unordered_map<span::FunctionName, object::Function>;
      /// The records defined in the translation unit.
      using RecordMap = std::unordered_map<span::RecordName, types::Record>;

      /// Holds the complete translation unit.
      class TUnit {
        public:
          TUnit(std::string name, std::string description,
              VarMap&& varMap, FuncMap funcMap);

          /// Get TUnit name, generally the filename.
          const std::string& getName();

          /// Set TUnit name, generally the filename.
          void setName(std::string name);

          /// Get TUnit (optional) description
          std::string getDescription();

          /// Set TUnit (optional) description
          /// \param description an optional description of the translation unit
          void setDescription(std::string description);

          // checking
          std::vector<string> Ret_String();

        private:
          std::string name;
          std::string description;

          VarMap varMap;
          FuncMap funcMap;
          RecordMap recordMap;

          std::vector<string> v;

      };
    } // end namespace tunit
  } // end namespace ir
} // end namespace span

#endif //SPAN_TUNIT_H
