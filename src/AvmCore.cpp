#include <iostream>
#include "AvmCore.hpp"
#include <iomanip>
#include "InstructionException.hpp"

AvmCore::AvmCore(std::string const &path, Ncurses *ncurses) :
_ncurses(ncurses),
_exit(false),
_parser(this->_instruction),
_path(path)
{
	if (AvmCore::_debug)
		std::cout << "AvmCore:: Default constructor called." << std::endl;
	this->_parser._parse(this->_path);
	return ;
}
AvmCore::AvmCore(Ncurses *ncurses) :
_ncurses(ncurses),
_exit(false),
_parser(this->_instruction)
{
	if (AvmCore::_debug)
		std::cout << "AvmCore:: Default constructor called." << std::endl;
	this->_parser._parse();
	return ;
}

AvmCore::~AvmCore(void)
{
	if (AvmCore::_debug)
		std::cout << "AvmCore:: Destructor called." << std::endl;
	if (this->_ncurses)
		delete this->_ncurses;
	MutantStack<AInstruction const *>::iterator it;

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
	if (this->_ncurses)
		return ;
	MutantStack<AInstruction const *>::iterator i;

	i = (this->_instruction).begin();
	while (i != (this->_instruction).end())
	{
		std::cout << AvmParser::stringByEinstruction.at((*i)->getType()) << std::endl;
		i++;
	}
}
void	AvmCore::printStack(void)
{
	if (this->_ncurses)
		return ;
	MutantStack<IOperand const *>::iterator i;

	i = (this->_stack).begin();
	while (i != (this->_stack).end())
	{
		std::cout << std::fixed << std::setprecision((*i)->getPrecision()) << std::stof((*i)->toString()) << std::endl;
		i++;
	}
}
void	AvmCore::_printError(std::string const &str)
{
	std::cerr << str << std::endl;
}

void	AvmCore::execute(void)
{
	unsigned int								i;
	MutantStack<AInstruction const *>::iterator	it;

	it = (this->_instruction).begin();
	i = 0;
	while (!this->_exit && it != (this->_instruction).end())
	{
		if (this->_ncurses)
		{
			this->_ncurses->render(this->_instruction, this->_stack, i);
			this->_ncurses->update();
		}
		try
		{
			(*it)->execute(*this);
		}
		catch (InstructionException::AssertFailed const &e)
		{
			AvmCore::_printError(std::string("InstructionException::AssertFailed : \x1b[31m") + e.what() + "\x1b[0m");
		}
		catch (InstructionException::DivByZero const &e)
		{
			AvmCore::_printError(std::string("InstructionException::DivByZero : \x1b[31m") + e.what() + "\x1b[0m");
		}
		catch (InstructionException::StackTooSmall const &e)
		{
			AvmCore::_printError(std::string("InstructionException::StackTooSmall : \x1b[31m") + e.what() + "\x1b[0m");
		}
		catch (InstructionException::Underflow const &e)
		{
			AvmCore::_printError(std::string("InstructionException::Underflow : \x1b[31m") + e.what() + "\x1b[0m");
		}
		catch (InstructionException::Overflow const &e)
		{
			AvmCore::_printError(std::string("InstructionException::Overflow : \x1b[31m") + e.what() + "\x1b[0m");
		}
		catch (AvmCore::NoExitInstruction const &e)
		{
			AvmCore::_printError(std::string("AvmCore::NoExitInstruction: \x1b[31m") + e.what() + "\x1b[0m");
		}
		catch (std::exception const &e)
		{
			AvmCore::_printError(std::string("std::exception : \x1b[31m") + e.what() + "\x1b[0m");
		}
		it++;
		i++;
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
