#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <string>
# include <exception>


class GlobalException: public std::exception
{
	public:
							GlobalException(std::string const &error) throw();
							~GlobalException() throw();
		virtual const char*	what() const throw();
	private:
		std::string			m_error;
};

#endif
