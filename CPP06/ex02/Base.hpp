#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    public:
        virtual ~Base();

};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);