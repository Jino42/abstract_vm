#ifndef INSTRUCTIONASSERT_HPP
# define INSTRUCTIONASSERT_HPP

#include "AInstruction.hpp"
#include "IOperand.hpp"
#include <string>

class InstructionAssert : public AInstruction {

public:

	InstructionAssert(std::string const &, IOperand const *);
	~InstructionAssert(void);

	void				execute(AvmCore &avm) const;
private:
	IOperand const			*_value;

	InstructionAssert(InstructionAssert const &src);
	InstructionAssert		&operator=(InstructionAssert const &rhs);
	InstructionAssert(void);

	static const bool	_debug;
};

#endif
