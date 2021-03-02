#include <iostream>
#include "factory.hpp"

using namespace std;

int main(int argc, char**argv) {

    Factory* expressionTree = new Factory();
    
    for (unsigned i = 0; i < argc; i++) {
	 cout << argv[i] << " ";
    }
	cout << endl;

    Base* result = expressionTree->parse(argv, argc);

    if(!result) {
	cout << "invalid expression Tree" << endl;
    } 
    else {
	cout << result->stringify() << " = " << result->evaluate() << endl;
    }
	
	
//	delete[] expressionTree;
//	delete[] result; 
//	delete[] argv;
	return 0;
}
