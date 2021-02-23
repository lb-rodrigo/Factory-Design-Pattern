#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add  : public Base {
    private:
        Base* val1;
        Base* val2;
    public:
        Add(Base* num1, Base* num2) : Base() {
                val1 = num1;
                val2 = num2;
        }
        virtual double evaluate() {
                return val1->evaluate() + val2->evaluate();
        }
        virtual std::string stringify() {
                return "(" +  std::to_string(val1->evaluate()) + " + " +  std::to_string(val2->evaluate()) + ")";
        }
};

#endif //__ADD_HPP__
