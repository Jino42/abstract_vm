#include <iostream>
#include "AvmCore.hpp"


AvmCore::AvmCore(std::string const &path) :
_parser(this->_instruction),
_path(path)
{
	if (AvmCore::_debug)
		std::cout << "AvmCore:: Default constructor called." << std::endl;
	this->_parser._parse(this->_path);
	return ;
}

AvmCore::~AvmCore(void)
{
	if (AvmCore::_debug)
		std::cout << "AvmCore:: Destructor called." << std::endl;
	return ;
}

void	AvmCore::printInstruction(void)
{
	MutantStack<IInstruction const *>::iterator i;

	i = (this->_instruction).begin();
	while (i != (this->_instruction).end())
	{
		std::cout << AvmParser::stringByEinstruction.at((*i)->getType()) << std::endl;
		i++;
	}
}


const bool		AvmCore::_debug = 0;
