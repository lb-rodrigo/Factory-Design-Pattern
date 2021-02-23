#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "base.hpp"
#include "div.hpp"
#include <vector> 
#include <string> 
#include <cstring>

using namespace std;

class Factory {

	public: 
		vector<string> ParseHelper(char** input, int length) {
			vector<string> expression;
			string value = ""; 
			for (unsigned i = 1; i < length; i++) {
 				if(isdigit(*input[i]) == true) {
					value += input[i];
					cout << value << endl;
					if(i == length-1) {
						expression.push_back(value);
					}
				}
				else {
					char operation = *input[i];
					if(strlen(input[i]) == 2) {
						expression.push_back(value);
						value = input[i];
						expression.push_back(value);
						cout << value << endl;
						value = "";
					}
					else if(operation == '+' || operation == '*' || operation == '/' || operation == '-') {
						expression.push_back(value);
						value = operation;
						cout << value << endl;
                                       		expression.push_back(value);
                                        	value = "";
					}
                                }					
			}
			return expression;
		}

		Base* parse(char** input, int length) {
			vector<string> expression = ParseHelper(input, length);
			
			//print expression 
			for(int i = 0; i < expression.size(); ++i) {
				cout << expression.at(i) << " ";
			}
	
			return cash;		
		}
};

#endif 
