#include <iostream>
#include "AvmParser.hpp"
#include <fstream>
#include <sstream>
#include <regex>
#include <stdexcept>

AvmParser::AvmParser(MutantStack< IInstruction const * > &instruction) :
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
	if (line.empty() || regex_match(line.c_str(), std::regex("^\\s*;")))
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

IInstruction const	*AvmParser::_parseInstruction(std::string const &line, std::string const &instruction)
{
	eInstructionType einstruction;
	(void)line;
	try
	{
		einstruction = AvmParser::einstructionByString.at(instruction);
		if (einstruction == Assert || einstruction == Push)
			return (this->_factoryInstruction.createInstruction(einstruction, "LOL"));
		else
			return (this->_factoryInstruction.createInstruction(einstruction));
	}
	catch (std::out_of_range const &e)
	{
		throw(AvmParser::InvalidInstruction(instruction + " is not an Instruction"));
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
			std::cout << line << "Instruction : [" << AvmParser::_getInstructionFromString(line) << "]" << std::endl;
			try {
				this->_instruction.push(this->_parseInstruction(line, AvmParser::_getInstructionFromString(line)));
			} catch (std::exception const &e) {
				std::cerr << e.what() << std::endl;
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
	{"dif", Div},
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
	{Div, "dif"},
	{Mod, "mod"},
	{Print, "print"},
	{Assert, "assert"},
	{Push, "push"},
	{Exit, "exit"}
};

AvmParser::InvalidInstruction::~InvalidInstruction(void) throw() {}
AvmParser::InvalidInstruction::InvalidInstruction(void) throw() :
	_error("InvalidInstruction Error") { }
AvmParser::InvalidInstruction::InvalidInstruction(std::string s) throw() :
	_error(s) { }
AvmParser::InvalidInstruction::InvalidInstruction(AvmParser::InvalidInstruction const &src) throw()
	{ this->_error = src._error; }
const char	*AvmParser::InvalidInstruction::what() const throw()
	{ return (this->_error.c_str()); }
