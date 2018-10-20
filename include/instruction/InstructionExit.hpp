#ifndef INSTRUCTIONEXIT_HPP
# define INSTRUCTIONEXIT_HPP

#include "IInstruction.hpp"

class InstructionExit : public IInstruction {

public:

	InstructionExit(void);
	~InstructionExit(void);

	InstructionExit(InstructionExit const &src);
	InstructionExit		&operator=(InstructionExit const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;

	static const bool	_debug;
};

#endif
