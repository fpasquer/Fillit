#ifndef CONFIG_FILE_HPP
# define CONFIG_FILE_HPP

#include <iostream>



# include <fstream>
# include <string>
# include <list>
# include "GlobalException.hpp"
# include "Tetromino.hpp"

class ConfigFile
{
	public:
							ConfigFile(std::string const &configFilePath) throw(GlobalException);
							~ConfigFile();
		std::list<Tetromino>
							getTetrominos() const;
	private:
		void				parseConfigFile() throw(GlobalException);
		void				addTetromino(unsigned int const i, std::list<std::string> const &tetrominoStr) throw(GlobalException);

		std::ifstream		m_file;
		std::list<Tetromino>
							m_tetrominos;
};

#endif
