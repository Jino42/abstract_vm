#ifndef AVMPARSER_HPP
# define AVMPARSER_HPP

#include "FactoryInstruction.hpp"
#include <string>
#include <map>
#include "MutantStack.tpp"

class AvmParser {

public:

	class InvalidInstruction : public std::exception {
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

	AvmParser(MutantStack< IInstruction const * > &instruction);
	~AvmParser(void);

	void					_parse(std::string const &);
	IInstruction const		*_parseInstruction(std::string const &line, std::string const &instruction);
	static bool				_isEmptyString(std::string const &line);
	static std::string		_getInstructionFromString(std::string const &line);

	static std::map<std::string, eInstructionType>			einstructionByString;
	static std::map<eInstructionType, std::string>			stringByEinstruction;
private:
	MutantStack< IInstruction const * >	&_instruction;
	FactoryInstruction const			_factoryInstruction;

	AvmParser(void);
	AvmParser(AvmParser const &src);
	AvmParser		&operator=(AvmParser const &rhs);

	static const bool										_debug;
};

#endif
