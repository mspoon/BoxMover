#ifndef arcadia_Component_h
#define arcadia_Component_h

#include <iostream>

class Component {
	public:
	virtual ~Component() {};
	virtual void print() { std::cout << "\t\tComponent" << std::endl; };
};

#endif
