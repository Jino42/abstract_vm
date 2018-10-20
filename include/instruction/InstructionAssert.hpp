#ifndef INSTRUCTIONASSERT_HPP
# define INSTRUCTIONASSERT_HPP

#include "IInstruction.hpp"
#include <string>

class InstructionAssert : public IInstruction {

public:

	InstructionAssert(std::string const &);
	~InstructionAssert(void);

	InstructionAssert(InstructionAssert const &src);
	InstructionAssert		&operator=(InstructionAssert const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;
	std::string const		_value;

	InstructionAssert(void);

	static const bool	_debug;
};

#endif
