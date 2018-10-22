#ifndef INSTRUCTIONPUSH_HPP
# define INSTRUCTIONPUSH_HPP

#include "AInstruction.hpp"
#include "IOperand.hpp"
#include <string>

class InstructionPush : public AInstruction {

public:

	InstructionPush(std::string const &, IOperand const *);
	~InstructionPush(void);

	void				execute(AvmCore &avm) const;
private:
	IOperand const			*_value;

	InstructionPush(void);
	InstructionPush(InstructionPush const &src);
	InstructionPush		&operator=(InstructionPush const &rhs);

	static const bool	_debug;
};

#endif
