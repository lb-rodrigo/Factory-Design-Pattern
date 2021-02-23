#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include <string>
#include <cmath>

class Mult : public Base{
	private:
	Base* object1;
	Base* object2;
    public:
	Mult(Base* a, Base* b): Base(){object1 = a; object2 = b;}
	virtual double evaluate(){
		if(isinf(object1->evaluate() * object2->evaluate())){
			return std::nan("");
		}
	return (object1->evaluate() * object2->evaluate());
    }
	virtual std::string stringify(){
	return ("("+ std::to_string(object1->evaluate()) + " * "+ std::to_string(object2->evaluate())+")");
    }
};
#endif //__MULT_HPP__
