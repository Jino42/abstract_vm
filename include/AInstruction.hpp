#ifndef AINSTRUCTION_HPP
# define AINSTRUCTION_HPP

enum eInstructionType { Push, Pop, Dump, Assert, Add, Sub, Mul, Div, Mod, Print, Exit };

class AvmCore;

class AInstruction {

public:
	AInstruction(std::string const &instruction, eInstructionType type);
	virtual void				execute(AvmCore &avm) const = 0;
	virtual eInstructionType	getType(void) const;
	virtual std::string			toString(void) const;
	virtual ~AInstruction(void);
protected:
	std::string				_instruction;
	eInstructionType const	_type;

private:
	AInstruction(AInstruction const &src);
	AInstruction		&operator=(AInstruction const &rhs);
	AInstruction(void);
};

#endif
