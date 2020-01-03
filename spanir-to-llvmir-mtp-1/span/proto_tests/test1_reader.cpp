#include <iostream>
#include <fstream>
#include <string>
#include "spanir.pb.h"

using namespace std;

vector<span::spill::BB> bbList;

int main(int argc, char *argv[])
{
GOOGLE_PROTOBUF_VERIFY_VERSION;

//Basic blocks will be read in bb1 and bb2
span::spill::BB bb1,bb2;

if (argc != 2){
	cerr << "Usage: " << argv[0] << " SPAN_IR_FILE" << endl;
	return -1;
} 

fstream input(argv[1], ios::in| ios::binary);

//Reading basic block 1 from the binary file
if (!bb1.ParseFromIstream(&input)) {
	cerr << "Failed to deserialize basic block -1." << endl;
	return -1;
}

//Reading basic block 2 from the binary file
if (!bb2.ParseFromIstream(&input)) {
	cerr << "Failed to deserialize basic block 0." << endl;
	return -1;
}

//Checking whether the basic blocks are successfully read from the binary file
//Prints the id of basic block 1
cout<< "BB1 id: " << bb1.id() << endl;
//Prints the id of basic block 2
cout<< "BB2 id: " << bb2.id() << endl;
 google::protobuf::ShutdownProtobufLibrary();

return 0;
}
