#include "os.h"

#include <cstring>
#include <cerrno>

namespace sasm { namespace exception {

os::os(const char* syscall)
  : std::exception()
{
  this->_message
    .append(syscall)
    .append("(): ")
    .append(strerror(errno));
}

os::os(const char* syscall, const char* message)
  : std::exception()
{
  this->_message
    .append(syscall)
    .append("(): ")
    .append(message)
    .append(": ")
    .append(strerror(errno));
}

}}
