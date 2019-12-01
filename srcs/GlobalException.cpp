#include "../incs/GlobalException.hpp"

							GlobalException::GlobalException(std::string const &error) throw():
		m_error(error)
{
}


							GlobalException::~GlobalException() throw()
{
}

const char					*GlobalException::what() const throw()
{
	return this->m_error.c_str();
}
