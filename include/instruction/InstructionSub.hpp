#ifndef INSTRUCTIONSUB_HPP
# define INSTRUCTIONSUB_HPP

#include "AInstruction.hpp"

class InstructionSub : public AInstruction {

public:

	InstructionSub(void);
	~InstructionSub(void);

	void				execute(AvmCore &avm) const;
private:
	InstructionSub(InstructionSub const &src);
	InstructionSub		&operator=(InstructionSub const &rhs);

	static const bool	_debug;
};

#endif
