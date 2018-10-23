#include <iostream>
#include "NcursesWin.hpp"

NcursesWin::NcursesWin(Vector2D<int> const &position, Vector2D<int> const &percentSize)
{
	if (NcursesWin::_debug)
		std::cout << "NcursesWin:: Default constructor called." << std::endl;
	this->_position = Vector2D<int>(COLS * position.getX() / 100,
			LINES * position.getY() / 100);

	this->_winSize  = Vector2D<int>(COLS * percentSize.getX() / 100,
			LINES * percentSize.getY() / 100);
	this->_offset  = Vector2D<int>(1, 1);
	this->_mapSize = Vector2D<int>(this->_winSize.getX() - 2, this->_winSize.getY() - 2);

	this->_win = newwin(this->_winSize.getY(), this->_winSize.getX(), this->_position.getY(),
			this->_position.getX());
	box(this->_win, 0, 0);
	return ;
}

NcursesWin::~NcursesWin(void)
{
	delwin(this->_win);
	if (NcursesWin::_debug)
		std::cout << "NcursesWin:: Destructor called." << std::endl;
	return ;
}

Vector2D<int>       NcursesWin::getMapSize(void) const
{
    return (this->_mapSize);
}

Vector2D<int>       NcursesWin::getPosition(void) const
{
    return (this->_position);
}

Vector2D<int>       NcursesWin::getWinSize(void) const
{
    return (this->_winSize);
}

WINDOW              *NcursesWin::getWin(void) const
{
    return (this->_win);
}

void NcursesWin::update(void)
{
	werase(this->_win);
}
void NcursesWin::render(void)
{
	box(this->_win, 0, 0);
	wrefresh(this->_win);
}

void NcursesWin::printString(Vector2D<int> position, std::string const &string)
{
	if (this->_inWin(position))
	{
    	mvwprintw(this->_win, position.getY() + this->_offset.getY(),
			position.getX() + this->_offset.getX(), string.c_str());
  	}
}

bool NcursesWin::_inWin(Vector2D<int> const &renderPosition) const {
    if (renderPosition.getY() >= 0 &&
      renderPosition.getY() <= this->_winSize.getY() &&
      renderPosition.getX() >= 0 &&
      renderPosition.getX() <= this->_winSize.getX())
    {
        return (true);
    }
    return (false);
}

const bool		NcursesWin::_debug = 0;
