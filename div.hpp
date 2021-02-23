#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <string>
#include <cmath>

class Div: public Base{
	private:
	Base* object1;
	Base* object2;
     public:
	Div(Base* one, Base* two): Base(){  object1 = one; object2 = two;}

	virtual double evaluate(){
	if(object2->evaluate() == 0 ){
		return (std::nan(""));
	}
	return object1->evaluate() /object2->evaluate();
	}

	virtual std::string stringify(){
	return ("(" + std::to_string(object1->evaluate()) + " / " + std::to_string(object2->evaluate()) +")");
	}
};
#endif // __DIV_HPP__
