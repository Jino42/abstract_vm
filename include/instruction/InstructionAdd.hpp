#ifndef INSTRUCTIONADD_HPP
# define INSTRUCTIONADD_HPP

#include "AInstruction.hpp"

class InstructionAdd : public AInstruction {

public:

	InstructionAdd(void);
	~InstructionAdd(void);

	void				execute(AvmCore &avm) const;
private:

	InstructionAdd(InstructionAdd const &src);
	InstructionAdd		&operator=(InstructionAdd const &rhs);

	static const bool	_debug;
};

#endif
