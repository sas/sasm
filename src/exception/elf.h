#ifndef EXCEPTION_ELF_H_
# define EXCEPTION_ELF_H_

# include <exception>
# include <string>

namespace sasm { namespace exception {

struct elf : public std::exception
{
  elf(const char* path, const char* message);
  virtual ~elf() throw() {}

  virtual const char* what() const throw()
  {
    return this->_message.c_str();
  }

private:
  std::string _message;
};

}}

#endif /* !EXCEPTION_ELF_H_ */
