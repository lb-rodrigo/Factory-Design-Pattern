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
		~Factory() {}

		vector<string> ParseHelper(char** input, int length) {
			vector<string> expression;
			string value = ""; 
			bool first = true;
			for (unsigned i = 1; i < length; i++) {
				char* digit = input[i];
 				if(isdigit(*digit) == true) {

					value += input[i];
				//	cout << value << " ";
					if(i == length-1) {
						expression.push_back(value);
					}
					first = false;
				}
				else {		
					char operation = *input[i];
					if(strlen(input[i]) > 1) {
						expression.push_back(value);
						value = input[i];
						expression.push_back(value);
				//		cout << value << " ";
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

		void Resize(vector<string>& expression) {
			size_t k = 0; 
			for (size_t i = 0; i < expression.size(); i++) {
				if(expression.at(i) != "") {
					expression.at(k) = expression.at(i);
					k++;
				}	
			}
			expression.resize(k);
		}

		bool check(vector<string> dirty) {
			if (dirty.size() == 0) {
                         //       cout << "Vector Empty" << endl;
                                return true;
                        }
                        if (dirty.at(0) == "+" || dirty.at(0) == "-" || dirty.at(0) == "*" || dirty.at(0) == "**" || dirty.at(0) == "/") {
                        //        cout << "Invalid Input" << endl;
                                return true;
                        }
                        if (dirty.at(dirty.size()-1) == "+" || dirty.at(dirty.size()-1) == "-" || dirty.at(dirty.size()-1) == "*" || dirty.at(dirty.size()-1) == "**" || dirty.at(dirty.size()-1) == "/") {
                               // cout << "Invalid Input" << endl;
                                return true;
                        }
			return false;
		}
	
		Base* parse(char** input, int length) {
			vector<string> expression = ParseHelper(input, length);
			Resize(expression);
			if(check(expression) == true) {
				return nullptr;
			}		

			Base* product = nullptr;

			//print expression
			cout << "{";
			for(int i = 0; i < expression.size(); ++i) {
				cout <<  expression.at(i) << ",";
			}
			cout << "}" << endl;
			
			for(int i = 0; i < expression.size(); ++i) {
				if(expression.at(i) == "+") {
					cout << expression.at(i-1);
					double val1 = stod(expression.at(i-1));
					if(product != nullptr){
					val1 = product->evaluate();
					double val2 = stod(expression.at(i+1));
					Base* op1 = new Op(val1);
					Base* op2 = new Op(val2);
	//				delete op1, op2;
					product = new Add(op1, op2);
					}
					else {
					double val2 = stod(expression.at(i+1));
                                        Base* op1 = new Op(val1);
                                        Base* op2 = new Op(val2);
                                        product = new Add(op1, op2);
					}
				}
				else if(expression.at(i) == "-") {
					double val1 = stod(expression.at(i-1));
                                        if(product != nullptr){
                                        val1 = product->evaluate();
                                        double val2 = stod(expression.at(i+1));
                                        Base* op1 = new Op(val1);
                                        Base* op2 = new Op(val2);
                                        product = new Sub(op1, op2);
                                        }
                                        else {
                                        double val2 = stod(expression.at(i+1));
                                        Base* op1 = new Op(val1);
                                        Base* op2 = new Op(val2);
                                        product = new Sub(op1, op2);
                                        }
                                }
				else if(expression.at(i) == "/") {
					double val1 = stod(expression.at(i-1));
                                        if(product != nullptr){
                                        val1 = product->evaluate();
                                        double val2 = stod(expression.at(i+1));
                                        Base* op1 = new Op(val1);
                                        Base* op2 = new Op(val2);
                                        product = new Div(op1, op2);
                                        }
                                        else {
                                        double val2 = stod(expression.at(i+1));
                                        Base* op1 = new Op(val1);
                                        Base* op2 = new Op(val2);
                                        product = new Div(op1, op2);
                                        }
                                }
				else if(expression.at(i) == "**") {
					double val1 = stod(expression.at(i-1));
                                        if(product != nullptr){
                                        val1 = product->evaluate();
                                        double val2 = stod(expression.at(i+1));
                                        Base* op1 = new Op(val1);
                                        Base* op2 = new Op(val2);
                                        product = new Pow(op1, op2);
                                        }
                                        else {
                                        double val2 = stod(expression.at(i+1));
                                        Base* op1 = new Op(val1);
                                        Base* op2 = new Op(val2);
                                        product = new Pow(op1, op2);
                                        }
				}
				else if(expression.at(i) == "*") {
					double val1 = stod(expression.at(i-1));
                                        if(product != nullptr){
                                        val1 = product->evaluate();
                                        double val2 = stod(expression.at(i+1));
                                        Base* op1 = new Op(val1);
                                        Base* op2 = new Op(val2);
                                        product = new Mult(op1, op2);
                                        }
                                        else {
                                        double val2 = stod(expression.at(i+1));
                                        Base* op1 = new Op(val1);
                                        Base* op2 = new Op(val2);
                                        product = new Mult(op1, op2);
                                        }
				} 	
			}

			return product;		
	}
};

#endif 
