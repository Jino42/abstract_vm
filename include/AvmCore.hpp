#ifndef AVMCORE_HPP
# define AVMCORE_HPP

#include "MutantStack.tpp"
#include "IOperand.hpp"
#include "AvmParser.hpp"

class AvmCore {

public:

	AvmCore(std::string const &path);
	~AvmCore(void);
	void	printInstruction(void);

private:
	AvmParser							_parser;
	MutantStack< IInstruction const * >	_instruction;
	MutantStack< IOperand * >			_stack;
	std::string const					_path;

	AvmCore(void);
	AvmCore(AvmCore const &src);
	AvmCore		&operator=(AvmCore const &rhs);

	static const bool	_debug;
};

#endif
