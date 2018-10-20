#include <iostream>
#include "AvmCore.hpp"

AvmCore::AvmCore(void)
{
	if (AvmCore::_debug)
		std::cout << "AvmCore:: Default constructor called." << std::endl;
	return ;
}

AvmCore::~AvmCore(void)
{
	if (AvmCore::_debug)
		std::cout << "AvmCore:: Destructor called." << std::endl;
	return ;
}

void		AvmCore::parse(std::string const &path)
{
	(void)path;
}


const bool		AvmCore::_debug = 0;
