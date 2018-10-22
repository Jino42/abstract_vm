#ifndef INSTRUCTIONMUL_HPP
# define INSTRUCTIONMUL_HPP

#include "AInstruction.hpp"

class InstructionMul : public AInstruction {

public:

	InstructionMul(void);
	~InstructionMul(void);

	void				execute(AvmCore &avm) const;
private:

	InstructionMul(InstructionMul const &src);
	InstructionMul		&operator=(InstructionMul const &rhs);

	static const bool	_debug;
};

#endif
