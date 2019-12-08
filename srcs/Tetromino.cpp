#include "../incs/Tetromino.hpp"

							Tetromino::Tetromino(std::list<std::string> const &tetrominoList, unsigned int const i) :
		TetrominoChecker(tetrominoList, i)
{
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
