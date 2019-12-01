#ifndef CONFIG_FILE_HPP
# define CONFIG_FILE_HPP

# include <fstream>
# include <string>
# include "GlobalException.hpp"

class ConfigFile
{
	public:
							ConfigFile(std::string const &configFilePath);
							~ConfigFile();
	private:
		std::fstream		m_file;
};

#endif
