//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#include "Types (copy).h"
#include "OpKinds (copy).h"
#include "Instr (copy).h"
#include "Expr (copy).h"
#include "Objects (copy).h"
using namespace span::ir::object;
using namespace span;

/// A CFG Node.
CFGNode::CFGNode(instr::InstrT *insn, std::vector<CFGNodeEdge*> inEdges, std::vector<CFGNodeEdge*> outEdges):insn{insn}, inEdges{inEdges}, outEdges{outEdges}{}

/// A labeled edge connecting CFG Nodes.
CFGNodeEdge::CFGNodeEdge(CFGNode *from, CFGNode *to, EdgeKind edgeKind):from{from}, to{to}, edgeKind{edgeKind}{}

/// Control Flow Graph.
CFG::CFG(CFGNodeMap cfgNodeMap, CFGNodeIdEdges cfgEdges) : cfgNodeMap{cfgNodeMap}, cfgEdges{cfgEdges} {
	//types::MyMap mymap;
	//edge_record = mymap.Initialise_Map();
}
      
/// A function declaration/definition.
Function::Function(std::string name,
  types::FunctionType f_type,
  std::vector<std::string> paramNames,
  CFG cfg, 
  bool body): name{name}, f_type{f_type},
  paramNames{paramNames}, cfg{cfg}, body{body} {}

std::string Function::getName()
{
  return name;
}

