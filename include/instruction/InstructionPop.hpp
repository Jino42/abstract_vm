#ifndef INSTRUCTIONPOP_HPP
# define INSTRUCTIONPOP_HPP

#include "IInstruction.hpp"

class InstructionPop : public IInstruction {

public:

	InstructionPop(void);
	~InstructionPop(void);

	InstructionPop(InstructionPop const &src);
	InstructionPop		&operator=(InstructionPop const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;

	static const bool	_debug;
};

#endif
