#ifndef EXCEPTION_OS_HH_
# define EXCEPTION_OS_HH_

# include <exception>
# include <string>

namespace sasm { namespace exception {

struct os : public std::exception
{
  os(const char* syscall);
  os(const char* syscall, const char* message);
  virtual ~os() throw() {}

  virtual const char* what() const throw()
  {
    return this->_message.c_str();
  }

private:
  std::string _message;
};

}}

#endif /* !EXCEPTION_OS_HH_ */
