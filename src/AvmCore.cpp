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
	MutantStack<IInstruction const *>::iterator it;

	it = (this->_instruction).begin();
	while (it != (this->_instruction).end())
	{
		delete *it;
		it++;
	}

	MutantStack<IOperand const *>::iterator i;

	i = (this->_stack).begin();
	while (i != (this->_stack).end())
	{
		delete *i;
		i++;
	}

	return ;
}

MutantStack< IOperand const * >	&AvmCore::getStack(void)
{
	return (this->_stack);
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
void	AvmCore::printStack(void)
{
	MutantStack<IOperand const *>::iterator i;

	i = (this->_stack).begin();
	while (i != (this->_stack).end())
	{
		std::cout << (*i)->toString() << std::endl;
		i++;
	}
}

void	AvmCore::execute(void)
{
	MutantStack<IInstruction const *>::iterator it;

	it = (this->_instruction).begin();
	while (it != (this->_instruction).end())
	{
		(*it)->execute(*this);
		it++;
	}
}

const bool		AvmCore::_debug = 0;

AvmCore::StackTooSmall::~StackTooSmall(void) throw(){}
AvmCore::StackTooSmall::StackTooSmall(void) throw() :
	logic_error(this->_error),
	_error("Trying operate with a too small stack") {}
AvmCore::StackTooSmall::StackTooSmall(std::string s) throw() :
	logic_error(s),
	_error(s) { }
AvmCore::StackTooSmall::StackTooSmall(AvmCore::StackTooSmall const &src) throw() :
	logic_error(this->_error),
	_error(src._error)
	{ this->_error = src._error; }
const char	*AvmCore::StackTooSmall::what() const throw()
	{ return (this->_error.c_str()); }
