//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#ifndef SPAN_TUNIT_H
#define SPAN_TUNIT_H

#include "types.h"
#include "objects.h"

#include <unordered_map>
#include <string>

namespace span {
  namespace ir {
    namespace tunit {
      /// The variables in a translation unit.
      typedef std::unordered_map<span::VarName, Type> VarMap;
      /// The functions declared/defined in a translation unit.
      typedef std::unordered_map<span::FunctionName, obj::Function> FuncMap;
      /// The records defined in the translation unit.
      typedef std::unordered_map<span::RecordName, types::Record> RecordMap;

      /// Holds the complete translation unit.
      class TUnit {
        std::string name;
        std::string description;

        VarMap varMap;
        FuncMap funcMap;
        RecordMap recordMap;

      public:
        /// Get TUnit name, generally the filename.
        std::string getName();
        /// Set TUnit name, generally the filename.
        void setName(std::string name);

        /// Get TUnit (optional) description
        std::string getDescription();

        /// Set TUnit (optional) description
        /// \param description an optional description of the translation unit
        void setDescription(std::string description);

      };
    } // end namespace tunit
  } // end namespace ir
} // end namespace span

#endif //SPAN_TUNIT_H

