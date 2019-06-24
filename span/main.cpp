//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#include "Types.h"
#include "OpKinds.h"
#include "Expr.h"
#include "Instr.h"
#include "Objects.h"
#include "TUnit.h"

#include <utility>  // for std::move

using namespace span::ir;

/// Manually creates a translation unit
tunit::TUnit* createTUnit1() {
  tunit::VarMap varMap;
  tunit::FuncMap funcMap;
  tunit::RecordMap recordMap;

  varMap["v:main:argc"] = new types::Type{types::TY_INT32};
  varMap["v:main:argv"] = new types::PointerType{
      new types::PointerType{
          new types::Type{types::TY_INT8}, 1
      }, 2
  };
  varMap["v:main:x"] = new types::Type{types::TY_INT32};
  varMap["v:main:y"] = new types::Type{types::TY_INT32};
  varMap["v:main:z"] = new types::Type{types::TY_INT32};

  funcMap["f:main"] = object::Function {
    "f:main",

    types::FunctionType {
      new types::Type{types::TY_INT32},
      ParamTypes{
        new types::Type{types::TY_INT32},
        new types::PointerType{
          new types::PointerType{
            new types::Type{types::TY_INT8}, 1
          }, 2
        }
      },
      false
    },

    {"v:main:argc", "v:main:argv"},

    object::CFG {
      object::CFGNodeMap {
        {-1, object::CFGNode{
          instr::AssignI{expr::VarExpr{"v:main:z"},
                         expr::BinaryExpr{op::BO_Add,
                                          expr::VarExpr{"v:main:x"},
                                          expr::VarExpr{"v:main:y"}}}}},
        {0, object::CFGNode{
            instr::ReturnI{expr::VarExpr{"v:main:z"}}}}
      },

      object::CFGNodeIdEdges{
          {-1, 0, object::EdgeKind::UNCOND_EDGE}
      }

    }, // end CFG

    false // not variadic
  };

  tunit::TUnit *tUnit = new TUnit {
    "tunit1",
    "Manually created Translation Unit",
    std::move(varMap),
    std::move(funcMap),
    std::move(recordMap)
  };

  return tUnit;
}

int main() {
  tunit::TUnit* tUnit = createTUnit1();
  tUnit->print();

  return 0;
}

