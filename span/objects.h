//
// Created by codeman on 19/6/19.
//
// The objects in the translation unit.

#ifndef SPAN_OBJECTS_H
#define SPAN_OBJECTS_H

#include <unordered_map>
#include <vector>

#include "types.h"
#include "OperationKinds.h"
#include "instr.h"
#include "expr.h"

namespace span {
  namespace ir {
    namespace obj {
      enum EdgeKind {
        FALSE_EDGE,
        TRUE_EDGE,
        UNCOND_EDGE,
      };

      typedef std::pair<BasicBlockId, std::pair<BasicBlockId, EdgeKind>> BBIdEdge;
      typedef std::pair<CFGNodeId , std::pair<CFGNodeId , EdgeKind>> CFGNodeIdEdge;

      class BBEdge;
      class CFGNode;

      class BB {
        BasicBlockId id;
        std::vector<InstrT*> insns;
        std::vector<BBEdge*> inEdges;
        std::vector<BBEdge*> outEdges;

        std::vector<CFGNode> nodes;
      };

      class BBEdge {
        BB *from;
        BB *to;
        EdgeKind edgeKind;
      };

      class CFGNodeEdge;

      class CFGNode {
        InstrT *insn;
        std::vector<CFGNodeEdge*> inEdges;
        std::vector<CFGNodeEdge*> outEdges;
      };

      class CFGNodeEdge {
        CFGNode *from;
        CFGNode *to;
        EdgeKind edgeKind;
      };

      class CFG {
        std::unordered_map<BasicBlockId, BB> bbMap;
        std::vector<BBEdgeIdEdge> bbEdges;
        BB *startBB;
        BB *endBB;

        std::unordered_map<CFGNodeId, CFGNode> bbMap;
        std::vector<CFGNodeIdEdge> cfgEdges;
        CFGNode *startNode;
        CFGNode *endNode;
      };

      class Function {
        std::string name;
        types::Function type;
        std::vector<std::string> paramNames;

        std::vector<instr::InstrT*> insns;
        CFG cfg;
      };
    } // end namespace obj
  } // end namespace ir
} // end namespace span

#endif //SPAN_OBJECTS_H
