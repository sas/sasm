#include "mapped_file.h"

#include <exception/os.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

namespace sasm { namespace utils {

mapped_file::mapped_file(const char* path)
  : _path(path), _is_mapped(false)
{
}

mapped_file::~mapped_file()
{
  if (this->_is_mapped)
    this->unmap();
}

void mapped_file::map()
{
  int fd;
  struct stat buf;
  char* begin;
  
  if ((fd = open(this->_path, O_RDONLY)) == -1)
    throw sasm::exception::os("open", this->_path);

  if (fstat(fd, &buf) == -1)
    throw sasm::exception::os("fstat");

  if ((begin = (char*) mmap(NULL, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
    throw sasm::exception::os("mmap");

  close(fd);

  this->_is_mapped = true;
  this->_begin = begin;
  this->_size = buf.st_size;
}

void mapped_file::unmap()
{
  if (munmap((void*) this->_begin, this->_size) == -1)
    throw sasm::exception::os("munmap");

  this->_is_mapped = false;
}

}}
