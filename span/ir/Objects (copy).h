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

#include "Types (copy).h"
#include "OpKinds (copy).h"
#include "Instr (copy).h"
#include "Expr (copy).h"

namespace span {
  namespace ir {
    /// Objects in a translation unit
    namespace object {
      enum EdgeKind {
        FALSE_EDGE,
        TRUE_EDGE,
        UNCOND_EDGE,
      };
    
      class BBEdge;
      class CFGNode;


      /// Edge from bb id to bb id (useful for serialization/deserialization)
      using BBIdEdge = std::pair<BasicBlockId, std::pair<BasicBlockId, EdgeKind>>;

      /// Edge from CFGNode id to CFGNode id (useful for serialization/deserialization)
      using CFGNodeIdEdge = std::pair<CFGNodeId , std::pair<CFGNodeId , EdgeKind>>;
      using CFGNodeIdEdges = std::vector<CFGNodeIdEdge>;

      using CFGNodeMap = std::unordered_map<CFGNodeId, CFGNode>;

     
      /// A basic block containing a sequence of instructions.
      class BB {
        BasicBlockId id;
        std::vector<instr::InstrT*> insns;
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
        instr::InstrT *insn;
        std::vector<CFGNodeEdge*> inEdges;
        std::vector<CFGNodeEdge*> outEdges;
        public:
          CFGNode(instr::InstrT *insn={}, std::vector<CFGNodeEdge*> inEdges={}, std::vector<CFGNodeEdge*> outEdges = {});

          string print()
          {
            string s="";
            if(insn != NULL)
              s += insn->print()+ " ";
            else
              s += "EMTPY BLOCK\n";
            //s += insn->print()+ " ";
            return s;
          }
        };

      /// A labeled edge connecting CFG Nodes.
      class CFGNodeEdge {
        CFGNode *from;
        CFGNode *to;
        EdgeKind edgeKind;
        public:
          CFGNodeEdge(CFGNode *from, CFGNode *to, EdgeKind edgeKind);
      };

      /// Control Flow Graph.
      class CFG {
        private:
          // Node id -1 is the start node (always)
          // Node id 0 is the end node (always)
          CFGNodeMap cfgNodeMap;
          CFGNodeIdEdges cfgEdges;
          CFGNode *startNode;
          CFGNode *endNode;

          // BB id -1 is the start node (always)
          // BB id 0 is the end node (always)
          std::unordered_map<BasicBlockId, BB> bbMap;
          std::vector<BBIdEdge> bbEdges;
          BB *startBB;
          BB *endBB;
        public:
          CFG(CFGNodeMap cfgNodeMap, CFGNodeIdEdges cfgEdges);

          string print()
          {
            string s="";
            s += "\nCFG nodes(STRT)\n";
            for(auto x:cfgNodeMap)
              s += "id= "+to_string(x.first) + " " + x.second.print()+" ";
            s += "\nCFG nodes(END)\n";
            return s;
          }
      };

      /// A function declaration/definition.
      class Function {
      public:
        Function(std::string name,
            types::FunctionType f_type,
            std::vector<std::string> paramNames,
            CFG cfg,                        
            bool body);

        std::string getName();

        string print()
        {
          string s = "";
          s += "f:name = " + name + " details = " + f_type.print() + " \n";
          for(auto x: paramNames)
          {
            s += x + " ";
          }
          s += cfg.print() + " " + " isbody= " + to_string(body);


          return s;
        }
        

      private:
        std::string name;
        types::FunctionType f_type; /// Function's type signature
        std::vector<std::string> paramNames;
        CFG cfg; /// Control Flow Graph of the function.
        bool body; /// true if function has a body
        std::vector<instr::InstrT*> insns; /// Sequence of instructions.
      };
    } // end namespace object
  } // end namespace ir
} // end namespace span

#endif //SPAN_OBJECTS_H
