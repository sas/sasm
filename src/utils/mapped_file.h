#ifndef MAPPED_FILE_HH_
# define MAPPED_FILE_HH_

# include <cstdint>

namespace sasm { namespace utils {

class mapped_file
{
public:
  mapped_file(const char* path);
  ~mapped_file();

  void map();
  void unmap();

  template<typename T>
  const T& read(int offset) const
  {
    return *((T*) (this->_begin + offset));
  }

  std::uint8_t operator[](int offset) const
  {
    return this->read<std::uint8_t>(offset);
  }

private:
  const char* _path;
  bool _is_mapped;
  const char* _begin;
  int _size;
};

}}

#endif /* !MAPPED_FILE_HH_ */
