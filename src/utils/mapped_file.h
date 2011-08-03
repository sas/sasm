#ifndef MAPPED_FILE_H_
# define MAPPED_FILE_H_

namespace sasm { namespace utils {

class mapped_file
{
public:
  mapped_file(const char* path);
  ~mapped_file();

  void map();
  void unmap();

  template<typename T> const T& read(int offset) const { return *((T*) (this->_begin + offset)); }
  char operator[](int offset) const { return this->read<char>(offset); }

private:
  const char*             _path;
  bool                    _is_mapped;
  const char*             _begin;
  unsigned long long int  _size;
};

}}

#endif /* !MAPPED_FILE_H_ */
