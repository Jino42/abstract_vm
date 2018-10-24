#ifndef AVMPARSER_HPP
# define AVMPARSER_HPP

#include "FactoryInstruction.hpp"
#include <string>
#include <map>
#include "MutantStack.tpp"
#include <regex>

class AvmCore;

class AvmParser {

public:

	class InvalidInstruction : public std::invalid_argument {
	public:
		InvalidInstruction(void) throw();
		InvalidInstruction(std::string) throw();
		virtual const char* what() const throw();
		~InvalidInstruction(void) throw();
		InvalidInstruction(InvalidInstruction const &src) throw();
	private:
		InvalidInstruction &operator=(InvalidInstruction const &rhs) throw();
		std::string			_error;
	};

	AvmParser(MutantStack< AInstruction const * > &instruction);
	~AvmParser(void);

	void					_parse(AvmCore &avmCore, std::string const &);
	void					_parse(AvmCore &avmCore);

	static std::map<std::string, eInstructionType>			einstructionByString;
	static std::map<eInstructionType, std::string>			stringByEinstruction;
	static std::map<std::string, eOperandType>				eoperandByString;

private:
	std::regex							_isValidInstruction;
	MutantStack< AInstruction const * >	&_instruction;
	FactoryInstruction const			_factoryInstruction;


	void					_parseTryGetInstruction(AvmCore &avmCore, std::string &line);
	AInstruction const		*_parseInstruction(std::string const &line, std::string const &instruction);
	IOperand const			*_parseOperandArgInstruction(std::string const &line);
	static bool				_isEmptyString(std::string const &line);
	static std::string		_getInstructionFromString(std::string const &line);
	static std::string 		_removeFirstBlank(std::string const &line);

	AvmParser(void);
	AvmParser(AvmParser const &src);
	AvmParser		&operator=(AvmParser const &rhs);

	static const bool										_debug;
};

#endif
