//
// Created by codeman on 19/6/19.
//

#ifndef SPAN_TUINT_H
#define SPAN_TUINT_H

#include "types.h"
#include "objects.h"

namespace span {
  namespace ir {
    namespace tunit {
      class TUnit {
        std::unordered_map<span::VarName, Type> vars;
        std::unordered_map<span::FunctionName, obj::Function> functions;
        std::unordered_map<span::RecordName, types::Record> records;
      };
    } // end namespace tunit
  } // end namespace ir
} // end namespace span

#endif //SPAN_TUINT_H
