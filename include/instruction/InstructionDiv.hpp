#ifndef INSTRUCTIONDIV_HPP
# define INSTRUCTIONDIV_HPP

#include "AInstruction.hpp"

class InstructionDiv : public AInstruction {

public:

	InstructionDiv(void);
	~InstructionDiv(void);

	void				execute(AvmCore &avm) const;
private:

	InstructionDiv(InstructionDiv const &src);
	InstructionDiv		&operator=(InstructionDiv const &rhs);

	static const bool	_debug;
};

#endif
