#ifndef INSTRUCTIONMUL_HPP
# define INSTRUCTIONMUL_HPP

#include "IInstruction.hpp"

class InstructionMul : public IInstruction {

public:

	InstructionMul(void);
	~InstructionMul(void);

	InstructionMul(InstructionMul const &src);
	InstructionMul		&operator=(InstructionMul const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;

	static const bool	_debug;
};

#endif
