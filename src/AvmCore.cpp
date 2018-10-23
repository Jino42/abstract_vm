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
	if (this->_ncurses)
		this->_ncurses->addException(str);
	else
		std::cerr << "\x1b[31m" << str << "\x1b[0m" << std::endl;
}

void	AvmCore::execute(void)
{
	MutantStack<AInstruction const *>::iterator	it;

	it = (this->_instruction).begin();

	if (this->_ncurses)
	{
		this->_ncurses->welcomeRender();
		this->_ncurses->update();
	}

	while (!this->_exit && it != (this->_instruction).end())
	{
		try
		{
			(*it)->execute(*this);
			if (this->_ncurses)
				this->_ncurses->addInstruction((*it)->toString());
		}
		catch (InstructionException::AssertFailed const &e)
		{
			this->_printError(std::string("InstructionException::AssertFailed : ") + e.what());
		}
		catch (InstructionException::DivByZero const &e)
		{
			this->_printError(std::string("InstructionException::DivByZero : ") + e.what());
		}
		catch (InstructionException::StackTooSmall const &e)
		{
			this->_printError(std::string("InstructionException::StackTooSmall : ") + e.what());
		}
		catch (InstructionException::Underflow const &e)
		{
			this->_printError(std::string("InstructionException::Underflow : ") + e.what());
		}
		catch (InstructionException::Overflow const &e)
		{
			this->_printError(std::string("InstructionException::Overflow : ") + e.what());
		}
		catch (AvmCore::NoExitInstruction const &e)
		{
			this->_printError(std::string("AvmCore::NoExitInstruction: ") + e.what());
		}
		catch (std::exception const &e)
		{
			this->_printError(std::string("std::exception : ") + e.what());
		}
		it++;
		if (this->_ncurses)
		{
			this->_ncurses->render(this->_stack);
			this->_ncurses->update();
		}
	}
	if (!this->_exit)
		throw(AvmCore::NoExitInstruction());
	if (this->_ncurses)
	{
		this->_ncurses->addInstruction("");
		this->_ncurses->addInstruction("");
		this->_ncurses->addInstruction("");
		this->_ncurses->addInstruction("Press ESC for exit");
		this->_ncurses->render(this->_stack);
		while (!this->_ncurses->exit())
		{
			this->_ncurses->update();
			this->_ncurses->render(this->_stack);
		}
	}
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
