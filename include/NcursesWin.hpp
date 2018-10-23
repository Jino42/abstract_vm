#ifndef NCURSESWIN_HPP
# define NCURSESWIN_HPP

#include <curses.h>
#include <vector>
#include "Vector2D.tpp"
#include "MutantStack.tpp"
#include "AInstruction.hpp"
#include "IOperand.hpp"
#include <vector>

class NcursesWin {

public:

	NcursesWin(Vector2D<int> const &position, Vector2D<int> const &percentSize);
	~NcursesWin(void);

	Vector2D<int>   getMapSize(void) const;
	Vector2D<int>   getPosition(void) const;
	Vector2D<int>   getWinSize(void) const;
	WINDOW			*getWin(void) const;

	void        printString(unsigned int index, std::string const &string);
	void		update(void);
	void		render(void);
	void		welcomeRender(void);

private:

	WINDOW						*_win;
	Vector2D<int>				_position;
	Vector2D<int>				_winSize;
	Vector2D<int>				_offset;
	Vector2D<int>				_mapSize;

	bool _inWin(Vector2D<int> const &renderPosition) const;

	NcursesWin(void);
	NcursesWin(NcursesWin const &src);
	NcursesWin		&operator=(NcursesWin const &rhs);

	static const bool	_debug;
};

#endif
