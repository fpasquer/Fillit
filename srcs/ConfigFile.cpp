#include "../incs/ConfigFile.hpp"

							ConfigFile::ConfigFile(std::string const &configFilePath) :
		m_file(configFilePath, std::fstream::in)
{
	if (this->m_file.is_open() == false)
		throw GlobalException(configFilePath + " is not a valid file");
}

							ConfigFile::~ConfigFile()
{
	if (this->m_file.is_open() == true)
		this->m_file.close();
}
