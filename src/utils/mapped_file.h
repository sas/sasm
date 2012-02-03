#ifndef UTILS_MAPPED_FILE_H_
# define UTILS_MAPPED_FILE_H_

# include <string>

namespace sasm { namespace utils {

class mapped_file
{
public:
  mapped_file(const std::string& path);
  ~mapped_file();

  void map();
  void unmap();

  template<typename T> const T& read(int offset) const { return *((T*) (this->_begin + offset)); }
  char operator[](int offset) const { return this->read<char>(offset); }

  const char* get_path() const;

private:
  const std::string&  _path;
  bool                _is_mapped;
  const char*         _begin;
  uint64              _size;
};

}}

#endif /* !UTILS_MAPPED_FILE_H_ */
