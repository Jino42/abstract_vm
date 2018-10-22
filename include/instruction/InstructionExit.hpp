#ifndef INSTRUCTIONEXIT_HPP
# define INSTRUCTIONEXIT_HPP

#include "AInstruction.hpp"

class InstructionExit : public AInstruction {

public:

	InstructionExit(void);
	~InstructionExit(void);

	void				execute(AvmCore &avm) const;
private:

	InstructionExit(InstructionExit const &src);
	InstructionExit		&operator=(InstructionExit const &rhs);

	static const bool	_debug;
};

#endif
