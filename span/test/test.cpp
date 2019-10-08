#include <bits/stdc++.h>
#include <vector>
using namespace std;

#include "/home/zubair/MTP-1/spanir-to-llvmir/span/ir/Types (copy).h"
#include "/home/zubair/MTP-1/spanir-to-llvmir/span/ir/Objects (copy).h"
#include "/home/zubair/MTP-1/spanir-to-llvmir/span/ir/TUnit (copy).h"
#include "/home/zubair/MTP-1/spanir-to-llvmir/span/ir/Expr (copy).h"
#include "/home/zubair/MTP-1/spanir-to-llvmir/span/ir/Instr (copy).h"
using namespace span::ir;


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
  types::Type ty1(types::TY_INT32);
  types::Type ty2(types::TY_INT32);
  types::Type ty3(types::TY_INT32);
  types::Type ty4(types::TY_INT32);
  types::Type ty5(types::TY_INT32);
  types::Type ty6(types::TY_INT32);
  types::Type tyu1(types::TY_UINT8);
  types::Type tyu2(types::TY_UINT8);
  expr::VarExpr varex1("x", &ty4);
  expr::VarExpr varax2("y", &ty5);
  instr::AssignI assigni(&varex1, &varax2);
  types::PointerType pt1(&tyu1, 2);
  types::PointerType pt2(&tyu2, 2);
  object::CFGNodeEdge cfgned1();
  object::CFGNodeEdge cfgned2();
  object::CFGNodeIdEdges edges;
  edges.push_back(make_pair(-1, make_pair(0, object::EdgeKind::UNCOND_EDGE)));

  tunit::TUnit currTUnit(
    //name::
    "span.tests.test1",
    //desc::
    "A simple sequential program. 1. x = y; ",
    //VARS::
    {
      // all global and local variables go here
      {"v:main:argc", &ty1} ,
      {"v:main:argv", &pt1} ,
      {"v:main:x", &ty2}
      //make_pair("v:main:c":    types.Int),
      //make_pair("v:main:z":    types.Int),  
    }, // end allVars
    //Func
    {
      { "f:main", 
        object::Function( "f:main", 
                          types::FunctionType(  &ty3, 
                                                {&ty6, &pt2}, 
                                                true
                                              ), 
                          {"v:main:argc", "v:main:argv"},
                          object::CFG( {  {-1, object::CFGNode( &assigni)
                                          },
                                          { 0, {}
                                          }
                                        },
                                        edges
                                      ),
                          true
                        )
      }
    }
  );

  std::vector<string> v = currTUnit.Ret_String();
  //cout<<currTUnit.Ret_String()<<endl;
  for(auto x : v)
  {
    cout<<x<<endl;
  }
  return 0;
}
