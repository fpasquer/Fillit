#include "../incs/TetrominoManager.hpp"

							TetrominoManager::TetrominoManager(std::string const &configFilePath) throw(GlobalException):
		m_file(configFilePath, std::fstream::in),
		m_tetrominos()
{
	if (this->m_file.is_open() == false)
		throw GlobalException(configFilePath + " is not a valid file");
	this->parseTetrominoManager();
}

							TetrominoManager::~TetrominoManager()
{
	if (this->m_file.is_open() == true)
		this->m_file.close();
}

std::list<Tetromino>		TetrominoManager::getTetrominos() const
{
	return this->m_tetrominos;
}

void						TetrominoManager::parseTetrominoManager() throw(GlobalException)
{
	unsigned int			i = 0;
	std::string				line;
	std::list<std::string>	tetrominoList;

	while (getline(this->m_file, line))
		if (line.empty() == true)
		{
			this->addTetromino(++i, tetrominoList);
			tetrominoList.clear();
		} else
			tetrominoList.push_back(line);
	this->addTetromino(i++, tetrominoList);
}

void						TetrominoManager::addTetromino(unsigned int const i, std::list<std::string> const &tetrominoList)
		throw(GlobalException)
{
	Tetromino				tetromino(tetrominoList, i);

	this->m_tetrominos.push_back(tetromino);
}
