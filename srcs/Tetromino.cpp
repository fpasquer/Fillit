#include "../incs/Tetromino.hpp"

unsigned int				Tetromino::NUMBER_ROW = 4;
unsigned int				Tetromino::NUMBER_COL = 4;
char						Tetromino::EMPTY = '.';
char						Tetromino::CHARACTER = '#';

							Tetromino::Tetromino(std::list<std::string> const &tetrominoList, unsigned int const i) :
		m_tetromino(),
		m_i(i)

{
	t_coordinate			coordStart;

	this->checkTetrominoRowCol(tetrominoList);
	coordStart = this->initTetromino(tetrominoList);
	if (this->isValid(coordStart) == false)
		throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": does not exist");
}

void						Tetromino::checkTetrominoRowCol(std::list<std::string> const &tetrominoList) const
{
	if (tetrominoList.size() != Tetromino::NUMBER_ROW)
		throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": One tetromino must be composed by " + std::to_string(Tetromino::NUMBER_ROW) + " row(s)");
	for (std::string rowTetromino : tetrominoList)
		if (rowTetromino.length() != Tetromino::NUMBER_COL)
			throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": Each tetromino's row must be composed by " + std::to_string(Tetromino::NUMBER_COL) + " characters");
}


Tetromino::t_coordinate const
							Tetromino::initTetromino(std::list<std::string> const &tetrominoList)
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
			if (c == Tetromino::CHARACTER)
			{
				coordStart.y = coordStart.y == 0xFFFFFFFF ? coord.y : coordStart.y;
				coordStart.x = coordStart.x == 0xFFFFFFFF ? coord.x : coordStart.x;
				count++;
			}
			else if (c != Tetromino::EMPTY)
				throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": Not available");
			row.push_back(c);
			coord.x++;
		}
		coord.y++;
		this->m_tetromino.push_back(row);
	}
	if (count != 4)
		throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": Must be composed of 4 '" + std::to_string(Tetromino::CHARACTER) + "'");
	return coordStart;
}

bool						Tetromino::isValid(t_coordinate const &coordStart) const
{
	Tetromino::t_checker const
							checkers[] = {
		{&Tetromino::isSquare},
		//{&Tetromino::isS},
		//{&Tetromino::isLTop},
	};
	for (t_checker const &checker : checkers)
		if ((*(this).*checker.f)(coordStart) == true)
			return true;
	return false;
}



bool						Tetromino::isSquare(t_coordinate const &coordStart) const
{
	t_coordinate const		square[] = {
		{coordStart.x, coordStart.y},
		{coordStart.x + 1, coordStart.y},
		{coordStart.x, coordStart.y + 1},
		{coordStart.x + 1, coordStart.y + 1}
	};

	for (t_coordinate const &checker : square)
		if (!(checker.y < Tetromino::NUMBER_ROW &&
				checker.x < Tetromino::NUMBER_COL &&
				this->m_tetromino[checker.y][checker.x] == Tetromino::CHARACTER))
			return false;
	return true;
}

std::ostream &operator		<<(std::ostream &out, Tetromino const &tetromino)
{
	for (std::vector<char> rowTetromino : tetromino.getTetromino())
	{
		for (char c : rowTetromino)
			out << c;
		out << std::endl;
	}
    return out;
}


std::vector<std::vector<char>>
							Tetromino::getTetromino(void) const
{
	return this->m_tetromino;
}
