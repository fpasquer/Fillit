#include "../incs/TetrominoChecker.hpp"

unsigned int const			TetrominoChecker::NUMBER_ROW = 4;
unsigned int const			TetrominoChecker::NUMBER_COL = 4;
char const					TetrominoChecker::EMPTY = '.';
char const					TetrominoChecker::CHARACTER = '#';

							TetrominoChecker::TetrominoChecker(std::list<std::string> const &tetrominoList, unsigned int const i) :
		m_tetromino(),
		m_i(i)

{
	t_coordinate			coordStart;

	this->checkTetrominoRowCol(tetrominoList);
	coordStart = this->initTetromino(tetrominoList);
	if (this->isValid(coordStart) == false)
		throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": does not exist");
}

void						TetrominoChecker::checkTetrominoRowCol(std::list<std::string> const &tetrominoList) const
{
	if (tetrominoList.size() != TetrominoChecker::NUMBER_ROW)
		throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": One tetromino must be composed by " + std::to_string(TetrominoChecker::NUMBER_ROW) + " row(s)");
	for (std::string rowTetromino : tetrominoList)
		if (rowTetromino.length() != TetrominoChecker::NUMBER_COL)
			throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": Each tetromino's row must be composed by " + std::to_string(TetrominoChecker::NUMBER_COL) + " characters");
}


TetrominoChecker::t_coordinate const
							TetrominoChecker::initTetromino(std::list<std::string> const &tetrominoList)
{
	std::vector<char>		row;
	t_coordinate			coordStart = {0xFFFFFFFF, 0xFFFFFFFF}, coord = {0, 0};
	unsigned int			count = 0;

	for (std::string const &tetrominoRow : tetrominoList)
	{
		row.clear();
		coord.x = 0;
		for (char const &c : tetrominoRow)
		{
			if (c == TetrominoChecker::CHARACTER)
			{
				coordStart.y = coordStart.y == 0xFFFFFFFF ? coord.y : coordStart.y;
				coordStart.x = coordStart.x == 0xFFFFFFFF ? coord.x : coordStart.x;
				count++;
			}
			else if (c != TetrominoChecker::EMPTY)
				throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": Not available");
			row.push_back(c);
			coord.x++;
		}
		coord.y++;
		this->m_tetromino.push_back(row);
	}
	if (count != 4)
		throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": Must be composed of 4 '" + std::to_string(TetrominoChecker::CHARACTER) + "'");
	return coordStart;
}

bool						TetrominoChecker::isValid(t_coordinate const &coordStart) const
{
	TetrominoChecker::t_checker const
							checkers[] = {
		{&TetrominoChecker::isSquare},
		{&TetrominoChecker::isSHorizontally},
		{&TetrominoChecker::isSVetically},
		{&TetrominoChecker::isLTop},
		{&TetrominoChecker::isLRight},
		{&TetrominoChecker::isLBottom},
		{&TetrominoChecker::isLLeft},
		{&TetrominoChecker::isLineHorizontally},
		{&TetrominoChecker::isLineVertically},
	};
	for (t_checker const &checker : checkers)
		if ((*(this).*checker.f)(coordStart) == true)
			return true;
	return false;
}

bool						TetrominoChecker::checkerFunction(std::vector<t_coordinate> const & coordExpected) const
{
	for (t_coordinate const checker : coordExpected)
		if (!(checker.y < TetrominoChecker::NUMBER_ROW &&
				checker.x < TetrominoChecker::NUMBER_COL &&
				this->m_tetromino[checker.y][checker.x] == TetrominoChecker::CHARACTER))
			return false;
	return true;
}

bool						TetrominoChecker::isSquare(t_coordinate const &coordStart) const
/**
 * ##..
 * ##..
 * ....
 * ....
 * */
{
	std::vector<t_coordinate>
							square = {
		{coordStart.x, coordStart.y},
		{coordStart.x + 1, coordStart.y},
		{coordStart.x, coordStart.y + 1},
		{coordStart.x + 1, coordStart.y + 1}
	};
	return this->checkerFunction(square);
}

bool						TetrominoChecker::isSHorizontally(t_coordinate const &coordStart) const
/**
 * .##.
 * ##..
 * ....
 * ....
 * */
{
	std::vector<t_coordinate>
							sHorizontally = {
		{coordStart.x, coordStart.y},
		{coordStart.x + 1, coordStart.y},
		{coordStart.x - 1, coordStart.y + 1},
		{coordStart.x, coordStart.y + 1}
	};
	return this->checkerFunction(sHorizontally);
}

bool						TetrominoChecker::isSVetically(t_coordinate const &coordStart) const
/**
 * #...
 * ##..
 * .#..
 * ....
 * */
{
	std::vector<t_coordinate>
							sVertically = {
		{coordStart.x, coordStart.y},
		{coordStart.x, coordStart.y + 1},
		{coordStart.x + 1, coordStart.y + 1},
		{coordStart.x + 1, coordStart.y + 2}
	};
	return this->checkerFunction(sVertically);
}

bool						TetrominoChecker::isLTop(t_coordinate const &coordStart) const
/**
 * ..#.
 * ###.
 * ....
 * ....
 * */
{
	std::vector<t_coordinate>
							sHorizontally = {
		{coordStart.x, coordStart.y},
		{coordStart.x, coordStart.y + 1},
		{coordStart.x - 1, coordStart.y + 1},
		{coordStart.x - 2, coordStart.y + 1}
	};
	return this->checkerFunction(sHorizontally);
}

bool						TetrominoChecker::isLRight(t_coordinate const &coordStart) const
/**
 * #...
 * #...
 * ##..
 * ....
 * */
{
	std::vector<t_coordinate>
							sRight = {
		{coordStart.x, coordStart.y},
		{coordStart.x, coordStart.y + 1},
		{coordStart.x, coordStart.y + 2},
		{coordStart.x + 1, coordStart.y + 2}
	};
	return this->checkerFunction(sRight);
}

bool						TetrominoChecker::isLBottom(t_coordinate const &coordStart) const
/**
 * ###.
 * #...
 * ....
 * ....
 * */
{
	std::vector<t_coordinate>
							sBottom = {
		{coordStart.x, coordStart.y},
		{coordStart.x + 1, coordStart.y},
		{coordStart.x + 2, coordStart.y},
		{coordStart.x, coordStart.y + 1}
	};
	return this->checkerFunction(sBottom);
}

bool						TetrominoChecker::isLLeft(t_coordinate const &coordStart) const
/**
 * ##..
 * .#..
 * .#..
 * ....
 * */
{
	std::vector<t_coordinate>
							sLeft = {
		{coordStart.x, coordStart.y},
		{coordStart.x + 1, coordStart.y},
		{coordStart.x + 1, coordStart.y + 1},
		{coordStart.x + 1, coordStart.y + 2}
	};
	return this->checkerFunction(sLeft);
}

bool						TetrominoChecker::isLineVertically(t_coordinate const &coordStart) const
/**
 * #...
 * #...
 * #...
 * #...
 * */
{
	std::vector<t_coordinate>
							sLeft = {
		{coordStart.x, coordStart.y},
		{coordStart.x, coordStart.y + 1},
		{coordStart.x, coordStart.y + 2},
		{coordStart.x, coordStart.y + 3}
	};
	return this->checkerFunction(sLeft);
}

bool						TetrominoChecker::isLineHorizontally(t_coordinate const &coordStart) const
/**
 * ####
 * ....
 * ....
 * ....
 * */
{
	std::vector<t_coordinate>
							sLeft = {
		{coordStart.x, coordStart.y},
		{coordStart.x + 1, coordStart.y},
		{coordStart.x + 2, coordStart.y},
		{coordStart.x + 3, coordStart.y}
	};
	return this->checkerFunction(sLeft);
}
