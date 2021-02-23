#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
class Op : public Base {
    private: 
	      double val;
    public:
        Op(double value) : Base() { val = value; }
        virtual double evaluate() { return val; }
        virtual std::string stringify() { return std::to_string(val);}
};

#endif //__OP_HPP__
