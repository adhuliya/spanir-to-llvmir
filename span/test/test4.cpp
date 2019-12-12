#include <bits/stdc++.h>
#include <vector>
using namespace std;

#include "/home/zubair/Desktop/spanir-to-llvmir-mtp-1/span/ir/Types (copy).h"
#include "/home/zubair/Desktop/spanir-to-llvmir-mtp-1/span/ir/Objects (copy).h"
#include "/home/zubair/Desktop/spanir-to-llvmir-mtp-1/span/ir/TUnit (copy).h"
#include "/home/zubair/Desktop/spanir-to-llvmir-mtp-1/span/ir/Expr (copy).h"
#include "/home/zubair/Desktop/spanir-to-llvmir-mtp-1/span/ir/Instr (copy).h"

using namespace span::ir;
using namespace span::ir::expr;
using namespace span::ir::op;



/*
Dictionary of all the variables in a module.
Even local/automatic variables are included.
The naming of the variables is such that none of the names collide.
Naming convention:
1. Global variables are prefixed with "v:"
2. Automatic variables are prefixed with, "v:" along with
 their function name, separated with a colon.
   
Eg.
"v:x" is a global variable. (one colon in name)
"v:main:x" is a local variable in function main. (has two colons)
*/
int main()
{
  cout<<"HELLO from test program\n";
  types::Type ty_argc(types::TY_INT32);     // used for parametetr of main(argc, argv) globally 
  types::Type tyu_temp1(types::TY_UINT8);        // used as temp for argv
  types::PointerType ty_argv(&tyu_temp1, 2);     // used for parametetr of main(argc, argv) globally
  types::Type ty_return(types::TY_INT32);   // used for return type of main

  types::Type main_ty_argc(types::TY_INT32);  // used for parametetr of main(argc, argv) 
  types::Type tyu_temp2(types::TY_UINT8);     // used as temp for argv
  types::PointerType main_ty_argv(&tyu_temp2, 2);    // used for parametetr of main(argc, argv)
  

  types::Type ty_var1(types::TY_INT32);       // used for local variable x of main
  expr::VarExpr varex1("x", &ty_var1);     // used for varax x
  
  types::Type ty_lit(types::TY_FLOAT32);
  expr::LitExpr litexpr(10.5, &ty_lit);
  
  instr::AssignI assigni(&varex1, &litexpr); // used for AssignI
  
  
  object::CFGNodeEdge cfgned1();            // for edges b/w -1 and 0 block
  object::CFGNodeEdge cfgned2();            // for edges b/w -1 and 0 block
  object::CFGNodeIdEdges edges;             // for edges b/w -1 and 0 block  
  edges.push_back(make_pair(-1, make_pair(0, object::EdgeKind::UNCOND_EDGE)));

  char *c = "int x = 10.5;\n";
  string s(c);

  tunit::TUnit currTUnit(
    //name::
    "span.tests.test1",
    //desc::
    s,
    //VARS::
    {
      // all global and local variables go here
      {"v:main:argc", &ty_argc} ,
      {"v:main:argv", &ty_argv} ,
      {"v:main:x", &ty_var1}
      //make_pair("v:main:c":    types.Int),
      //make_pair("v:main:z":    types.Int),  
    }, // end allVars
    //Func
    {
      { "f:main", 
        object::Function( "f:main", 
                          types::FunctionType(  &ty_return, 
                                                {&main_ty_argc, &main_ty_argv}, 
                                                true
                                              ), 
                          {"v:main:argc", "v:main:argv"},
                          object::CFG( 
                                        //  first Map is CFGnode Map (node id, nodes)  
                                        {  {-1, object::CFGNode( &assigni)
                                          },
                                          { 0, {}
                                          }
                                        },
                                        // Second Map Edges b/w nodes.
                                        edges
                                      ),
                          true
                        )
      }
    }
  );

  std::vector<string> v = currTUnit.Ret_String();
  
  for(auto x : v)
  {
    cout<<x<<endl;
  }
  return 0;
}