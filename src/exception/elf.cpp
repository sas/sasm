#include "elf.h"

#include <cstring>
#include <cerrno>

namespace sasm { namespace exception {

elf::elf(const char* path, const char* message)
  : std::exception()
{
  this->_message
    .append(path)
    .append(": ")
    .append(message);
}

}}
