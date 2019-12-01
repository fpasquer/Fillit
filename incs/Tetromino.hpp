#ifndef TETROMINO_HPP
#define TETROMINO_HPP

# include <string>

class Tetromino
{
	public:
							Tetromino(std::string const &tetrominoStr);
		std::string			getTetromino() const;
	private:
		std::string			m_tetrominoStr;
};

#endif
