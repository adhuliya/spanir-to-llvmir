#include <bits/stdc++.h>
#include <vector>
using namespace std;

#include "/home/zubair/MTP-2/spanir-to-llvmir-mtp-1/span/ir/Types (copy).h"
#include "/home/zubair/MTP-2/spanir-to-llvmir-mtp-1/span/ir/Objects (copy).h"
#include "/home/zubair/MTP-2/spanir-to-llvmir-mtp-1/span/ir/TUnit (copy).h"
#include "/home/zubair/MTP-2/spanir-to-llvmir-mtp-1/span/ir/Expr (copy).h"
#include "/home/zubair/MTP-2/spanir-to-llvmir-mtp-1/span/ir/Instr (copy).h"

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
  
  types::Type main_ty_argc(types::TY_INT32);  // used for parametetr of main(argc, argv) 
  types::Type tyu_temp2(types::TY_UINT8);   // used as temp for argv
  types::PointerType main_ty_argv(&tyu_temp2, 2);    // used for parametetr of main(argc, argv)
  
  types::Type ty_return(types::TY_INT32);   // used for return type of main
  

  types::Type ty_var1(types::TY_INT32);     // used for local variable a of main
  types::Type ty_var2(types::TY_INT32);     // used for local variable b of main
  types::Type ty_var3(types::TY_INT32);     // used for local variable x of main

  //        START::int a = 10;            //
  
  types::Type ty_var_a(types::TY_INT32);     // used for local variable b of main
  expr::VarExpr varex_a("main:a", &ty_var_a); // expr for varexpr b (int b = 10);

  types::Type ty_var_a_lit(types::TY_INT32);     // used for local variable a of main
  expr::LitExpr litexpr_a(10, &ty_var_a_lit);    // expr for litexpr of a (int a = 10);

  instr::AssignI assigni_a(&varex_a, &litexpr_a);  // for assign instr int a = 10;

  //        END::int a = 10;               //


  //        START::int b = 20;            //
  
  types::Type ty_var_b(types::TY_INT32);     // used for local variable b of main
  expr::VarExpr varex_b("main:b", &ty_var_b); // expr for varexpr b (int a = 10);

  types::Type ty_var_b_lit(types::TY_INT32);     // used for local variable b of main
  expr::LitExpr litexpr_b(20, &ty_var_b_lit);    // expr for litexpr of b (int b = 20);

  instr::AssignI assigni_b(&varex_b, &litexpr_b);  // for assign instr int b = 10;

  //        END::int b = 20;               //


  //        START::int x = a+30;            //
  
  types::Type ty_var_x(types::TY_INT32);     // used for local variable x of main
  expr::VarExpr varex_x("main:x", &ty_var_x); // expr for varexpr x (int x = a+30);

  types::Type ty_var_x_lit(types::TY_INT32);     // used for local variable b of main
  expr::LitExpr litexpr_x(30, &ty_var_x_lit);    // expr for litexpr of b (int b = 20);

  expr::BinaryExpr binaryexpr(&varex_a, BO_ADD_OC, &litexpr_x);    // expr for binaryexpr (a+30);

  instr::AssignI assigni_x(&varex_x, &binaryexpr);  // for assign instr int x = a+30;

  //        END::int x = a+30;               //

  
  //object::CFGNodeEdge cfgned1();            // for edges b/w -1 and 0 block
  //object::CFGNodeEdge cfgned2();            // for edges b/w -1 and 0 block
  object::CFGNodeIdEdges edges;             // for edges b/w -1 and 0 block  
  edges.push_back(make_pair(-1, make_pair(2, object::EdgeKind::UNCOND_EDGE)));
  edges.push_back(make_pair(2, make_pair(0, object::EdgeKind::UNCOND_EDGE)));

  char *c = "int a=10;\n"
            "int b=20;\n"
            "int x = a+10;\n"; 
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
      {"v:main:a", &ty_var1},
      {"v:main:b", &ty_var2},
      {"v:main:x", &ty_var3}
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
                                        {  {-1, object::CFGNode( &assigni_a)
                                          },
                                          
                                          { 2, object::CFGNode(&assigni_b)
                                          },
                                          
                                          { 0, object::CFGNode(&assigni_x)
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
