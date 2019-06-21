//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#ifndef SPAN_OBJECTS_H
#define SPAN_OBJECTS_H

#include <unordered_map>
#include <vector>

#include "types.h"
#include "opKinds.h"
#include "instr.h"
#include "expr.h"

namespace span {
  namespace ir {
    /// Objects in a translation unit
    namespace obj {
      enum EdgeKind {
        FALSE_EDGE,
        TRUE_EDGE,
        UNCOND_EDGE,
      };

      /// Edge from bb id to bb id (useful for serialization/deserialization)
      typedef std::pair<BasicBlockId, std::pair<BasicBlockId, EdgeKind>> BBIdEdge;
      /// Edge from CFGNode id to CFGNode id (useful for serialization/deserialization)
      typedef std::pair<CFGNodeId , std::pair<CFGNodeId , EdgeKind>> CFGNodeIdEdge;

      class BBEdge;
      class CFGNode;

      /// A basic block containing a sequence of instructions.
      class BB {
        BasicBlockId id;
        std::vector<InstrT*> insns;
        std::vector<BBEdge*> inEdges;
        std::vector<BBEdge*> outEdges;

        std::vector<CFGNode> nodes;
      };

      /// A labeled edge connecting basic blocks.
      class BBEdge {
        BB *from;
        BB *to;
        EdgeKind edgeKind;
      };

      class CFGNodeEdge;

      /// A CFG Node.
      class CFGNode {
        InstrT *insn;
        std::vector<CFGNodeEdge*> inEdges;
        std::vector<CFGNodeEdge*> outEdges;
      };

      /// A labeled edge connecting CFG Nodes.
      class CFGNodeEdge {
        CFGNode *from;
        CFGNode *to;
        EdgeKind edgeKind;
      };

      /// Control Flow Graph.
      class CFG {
        // BB id -1 is the start node (always)
        // BB id 0 is the end node (always)
        std::unordered_map<BasicBlockId, BB> bbMap;
        std::vector<BBEdgeIdEdge> bbEdges;
        BB *startBB;
        BB *endBB;

        // Node id -1 is the start node (always)
        // Node id 0 is the end node (always)
        std::unordered_map<CFGNodeId, CFGNode> cfgNodeMap;
        std::vector<CFGNodeIdEdge> cfgEdges;
        CFGNode *startNode;
        CFGNode *endNode;
      };

      /// A function declaration/definition.
      class Function {
        std::string name;
        types::Function type;
        std::vector<std::string> paramNames;

        std::vector<instr::InstrT*> insns;
        CFG cfg;
        bool body;
      };
    } // end namespace obj
  } // end namespace ir
} // end namespace span

#endif //SPAN_OBJECTS_H
