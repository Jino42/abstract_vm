#ifndef INSTRUCTIONSUB_HPP
# define INSTRUCTIONSUB_HPP

#include "IInstruction.hpp"

class InstructionSub : public IInstruction {

public:

	InstructionSub(void);
	~InstructionSub(void);

	InstructionSub(InstructionSub const &src);
	InstructionSub		&operator=(InstructionSub const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;

	static const bool	_debug;
};

#endif
