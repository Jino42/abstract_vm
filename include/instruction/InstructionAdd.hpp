#ifndef INSTRUCTIONADD_HPP
# define INSTRUCTIONADD_HPP

#include "IInstruction.hpp"

class InstructionAdd : public IInstruction {

public:

	InstructionAdd(void);
	~InstructionAdd(void);

	InstructionAdd(InstructionAdd const &src);
	InstructionAdd		&operator=(InstructionAdd const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;

	static const bool	_debug;
};

#endif
