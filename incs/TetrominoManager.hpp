#ifndef CONFIG_FILE_HPP
# define CONFIG_FILE_HPP

#include <iostream>



# include <fstream>
# include <string>
# include <list>
# include "GlobalException.hpp"
# include "Tetromino.hpp"

class TetrominoManager
{
	public:
							TetrominoManager(std::string const &configFilePath) throw(GlobalException);
							~TetrominoManager();
		std::list<Tetromino>
							getTetrominos() const;
	private:
		void				parseTetrominoManager() throw(GlobalException);
		void				addTetromino(unsigned int const i, std::list<std::string> const &tetrominoStr) throw(GlobalException);

		std::ifstream		m_file;
		std::list<Tetromino>
							m_tetrominos;
};

#endif
