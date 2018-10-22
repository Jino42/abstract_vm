#include <iostream>
#include "AvmCore.hpp"
#include <iomanip>

AvmCore::AvmCore(std::string const &path) :
_exit(false),
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

void	AvmCore::setExit(bool v) { this->_exit = v; }


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
		std::cout << std::fixed << std::setprecision((*i)->getPrecision()) << std::stof((*i)->toString()) << std::endl;
		i++;
	}
}

void	AvmCore::execute(void)
{
	MutantStack<IInstruction const *>::iterator it;

	it = (this->_instruction).begin();
	while (!this->_exit && it != (this->_instruction).end())
	{
		(*it)->execute(*this);
		it++;
	}
	if (!this->_exit)
		throw(AvmCore::NoExitInstruction());
}

const bool		AvmCore::_debug = 0;


AvmCore::NoExitInstruction::~NoExitInstruction(void) throw(){}
AvmCore::NoExitInstruction::NoExitInstruction(void) throw() :
	runtime_error(this->_error),
	_error("Your program miss the 'exit' instruction") {}
AvmCore::NoExitInstruction::NoExitInstruction(std::string s) throw() :
	runtime_error(s),
	_error(s) { }
AvmCore::NoExitInstruction::NoExitInstruction(AvmCore::NoExitInstruction const &src) throw() :
	runtime_error(this->_error),
	_error(src._error)
	{ this->_error = src._error; }
const char	*AvmCore::NoExitInstruction::what() const throw()
	{ return (this->_error.c_str()); }
