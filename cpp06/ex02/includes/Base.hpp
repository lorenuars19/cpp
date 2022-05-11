#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <iostream>

class Base
{
public:
	virtual ~Base(){}; // Destructor
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base *generate();
void identify(Base *p);
void identify(Base &p);

#endif /* BASE_HPP */
