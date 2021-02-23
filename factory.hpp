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
					char operationPow = *input[i+1];		
					if (strlen(input[i]) == 2) {
						value = *input[i];
						cout << value;
                               		} 
					else if (operation == '+' || operation == '-' || operation == '/' || operation == '*') {
                                        	expression.push_back(value);
                                        	value = operation;
						cout << value;
					//	cout << "operation: " << value << endl;
					//	if (operation == '*' && operationPow == '*') {
					//		value += "*";
					//		cout << "updated operator: " << value << endl;
					//	}
                                       		expression.push_back(value);
                                        	value = "";
					}
                                }					
			}
			return expression;
		}

		Base* parse(char** input, int length) {
			vector<string> expression = ParseHelper(input, length);
		
			for(int i = 0; i < expression.size(); ++i) {
				cout << expression.at(i) << " ";
			}
	

			for(int i = 0; i < expression.size(); ++i) {
				if(expression.at(i) == "+") {
					double val1 = stod(expression.at(i-1));
					double val2 = stod(expression.at(i+1));
					Base* op1 = new Op(val1);
					Base* op2 = new Op(val2);
					return new Add(op1, op2);
				}
				else if(expression.at(i) == "-") {
                                        double val1 = stod(expression.at(i-1));
                                        double val2 = stod(expression.at(i+1));
                                        Base* op1 = new Op(val1);
                                        Base* op2 = new Op(val2);
                                        return new Sub(op1, op2);
                                }
				else if(expression.at(i) == "/") {
                                        double val1 = stod(expression.at(i-1));
                                        double val2 = stod(expression.at(i+1));
                                        Base* op1 = new Op(val1);
                                        Base* op2 = new Op(val2);
                                        return new Div(op1, op2);
                                }
				else if(expression.at(i) == "**") {
                                      	double val1 = stod(expression.at(i-1));
                                        double val2 = stod(expression.at(i+1));
                                 	Base* op1 = new Op(val1);
                                        Base* op2 = new Op(val2);
					return new Pow(op1, op2);
				}
				else if(expression.at(i) == "*") {
                       	                double val1 = stod(expression.at(i-1));
                               	        double val2 = stod(expression.at(i+1));
                                        Base* op1 = new Op(val1);
                                  	Base* op2 = new Op(val2);
                                        return new Mult(op1, op2);
				}	
			}		
			return nullptr;		
		}
	
		

};

#endif 
