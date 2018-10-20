#ifndef INSTRUCTIONPUSH_HPP
# define INSTRUCTIONPUSH_HPP

#include "IInstruction.hpp"
#include "IOperand.hpp"
#include <string>

class InstructionPush : public IInstruction {

public:

	InstructionPush(IOperand const *);
	~InstructionPush(void);

	InstructionPush(InstructionPush const &src);
	InstructionPush		&operator=(InstructionPush const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;
	IOperand const			*_value;

	InstructionPush(void);

	static const bool	_debug;
};

#endif
