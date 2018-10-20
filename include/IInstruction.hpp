#ifndef IINSTRUCTION_HPP
# define IINSTRUCTION_HPP

enum eInstructionType { Push, Pop, Dump, Assert, Add, Sub, Mul, Div, Mod, Print, Exit };

class AvmCore;

class IInstruction {

public:

	virtual void				execute(AvmCore &avm) const = 0;
	virtual eInstructionType	getType(void) const = 0;

private:

};

#endif
