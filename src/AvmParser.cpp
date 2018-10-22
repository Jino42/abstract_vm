#include <iostream>
#include "AvmParser.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "FactoryOperand.hpp"
#include <iomanip>
#include "InstructionException.hpp"

AvmParser::AvmParser(MutantStack< AInstruction const * > &instruction) :
_isValidInstruction(std::regex("([a-z]+)\\s+([a-z0-9]+)\\((-?([0-9]+)|([0-9]+\\.[0-9]+))\\)")),

_instruction(instruction)
{
	if (AvmParser::_debug)
		std::cout << "AvmParser:: Default constructor called." << std::endl;
	return ;
}

AvmParser::~AvmParser(void)
{
	if (AvmParser::_debug)
		std::cout << "AvmParser:: Destructor called." << std::endl;
	return ;
}

bool				AvmParser::_isEmptyString(std::string const &line)
{
	if (line.empty() || std::regex_match(line.c_str(), std::regex("^(\\s*;).*")))
		return (true);
	return (false);
}
std::string			AvmParser::_getInstructionFromString(std::string const &line)
{
	std::stringstream	ss(line);
	std::string			instruction;

	if (!line.find(" \t"))
		return (line);
	ss >> instruction;
	return (instruction);
}

IOperand const		*AvmParser::_parseOperandInstruction(std::string const &line)
{
	eOperandType		eoperand;
	std::cmatch			cm;
	std::string			instruction;


	std::size_t			found;
	if ((found = line.find(")")) == std::string::npos)
		throw(AvmParser::InvalidInstruction(line + " -> is not a complet Instruction"));
	instruction = line.substr(0, found + 1);

	if (!AvmParser::_isEmptyString(line.substr(found + 1)))
		throw(AvmParser::InvalidInstruction(line.substr(found + 1) + " -> after instruction"));

	std::regex_match(instruction.c_str(), cm, this->_isValidInstruction, std::regex_constants::match_default);

	if (cm.size() != 6)
		throw(AvmParser::InvalidInstruction(instruction + " -> is not a complet Instruction"));

	eoperand = AvmParser::eoperandByString.at(cm[2]);
	if ((eoperand == Float || eoperand == Double)
		&& !std::regex_match(std::string(cm[3]), std::regex("([0-9]+\\.[0-9]+)")))
		throw(AvmParser::InvalidInstruction(instruction + " -> is not a complet Instruction"));
	if ((eoperand != Float && eoperand != Double)
		&& !std::regex_match(std::string(cm[3]), std::regex("^([0-9]+)$")))
		throw(AvmParser::InvalidInstruction(instruction + " -> is not a complet Instruction"));
	return (FactoryOperand::getInstance()->createOperand(eoperand, cm[3], FactoryOperand::getStringPrecision(cm[3])));
}

AInstruction const	*AvmParser::_parseInstruction(std::string const &line, std::string const &instruction)
{
	eInstructionType	einstruction;

	try
	{
		einstruction = AvmParser::einstructionByString.at(instruction);
		if (einstruction == Assert || einstruction == Push)
		{
			std::size_t			found;
			if ((found = line.find(")")) == std::string::npos)
				throw(AvmParser::InvalidInstruction(line + " -> is not a complet Instruction"));
			return (this->_factoryInstruction.createInstruction(line.substr(0, found + 1), einstruction, this->_parseOperandInstruction(line)));
		}
		else
			return (this->_factoryInstruction.createInstruction(einstruction));
	}
	catch (std::out_of_range const &e)
	{
		throw(AvmParser::InvalidInstruction(line + " -> is not an Instruction"));
	}
	catch (std::exception const &e)
	{
		throw;
	}
}

void				AvmParser::_parse(std::string const &path)
{
	std::ifstream	ifs(path);
	std::string		line;

	if (!ifs.is_open())
		throw(std::invalid_argument("Cannot open your file"));
	while (getline(ifs, line))
	{
		if (!AvmParser::_isEmptyString(line))
		{
			try
			{
				this->_instruction.push(this->_parseInstruction(line, AvmParser::_getInstructionFromString(line)));
			}
			catch (InstructionException::Underflow const &e)
			{
				std::cerr << "InstructionException::Underflow : \x1b[31m" << e.what() << "\x1b[0m" << std::endl;
			}
			catch (InstructionException::Overflow const &e)
			{
				std::cerr << "InstructionException::Overflow : \x1b[31m" << e.what() << "\x1b[0m" << std::endl;
			}
			catch (std::exception const &e)
			{
				std::cerr << "std::exception : \x1b[31m" << e.what() << "\x1b[0m" << std::endl;
			}
		}
	}
}

void				AvmParser::_parse(void)
{
	std::string		line;

	while (getline(std::cin, line) && line != ";;")
	{
		if (!AvmParser::_isEmptyString(line))
		{
			try
			{
				this->_instruction.push(this->_parseInstruction(line, AvmParser::_getInstructionFromString(line)));
			}
			catch (InstructionException::Underflow const &e)
			{
				std::cerr << "\x1b[31m" << e.what() << "\x1b[0m" << std::endl;
			}
			catch (std::exception const &e)
			{
				std::cerr << "\x1b[31m" << e.what() << "\x1b[0m" << std::endl;
			}
		}
	}
}

const bool		AvmParser::_debug = 0;

std::map<std::string, eInstructionType>			AvmParser::einstructionByString = {
	{"pop", Pop},
	{"dump", Dump},
	{"add", Add},
	{"sub", Sub},
	{"mul", Mul},
	{"div", Div},
	{"mod", Mod},
	{"print", Print},
	{"assert", Assert},
	{"push", Push},
	{"exit", Exit}
};
std::map<eInstructionType, std::string>			AvmParser::stringByEinstruction = {
	{Pop, "pop"},
	{Dump, "dump"},
	{Add, "add"},
	{Sub, "sub"},
	{Mul, "mul"},
	{Div, "div"},
	{Mod, "mod"},
	{Print, "print"},
	{Assert, "assert"},
	{Push, "push"},
	{Exit, "exit"}
};

std::map<std::string, eOperandType>			AvmParser::eoperandByString = {
	{"int8", Int8},
	{"int16", Int16},
	{"int32", Int32},
	{"float", Float},
	{"double", Double},
};

AvmParser::InvalidInstruction::~InvalidInstruction(void) throw() {}
AvmParser::InvalidInstruction::InvalidInstruction(void) throw() :
	invalid_argument(this->_error),
	_error("InvalidInstruction Error") { }
AvmParser::InvalidInstruction::InvalidInstruction(std::string s) throw() :
	invalid_argument(this->_error),
	_error(s) { }
AvmParser::InvalidInstruction::InvalidInstruction(AvmParser::InvalidInstruction const &src) throw() :
	invalid_argument(this->_error)
	{ this->_error = src._error; }
const char	*AvmParser::InvalidInstruction::what() const throw()
	{ return (this->_error.c_str()); }
