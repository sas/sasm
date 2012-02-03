#ifndef UTILS_ARG_PARSE_H_
# define UTILS_ARG_PARSE_H_

# include <ostream>
# include <string>
# include <vector>

namespace sasm { namespace utils {

class arg_parse
{
private:
  struct option
  {
    bool        set;
    char        flag;
    bool        has_arg;
    std::string description;
    bool        mandatory;
  };

  class options_proxy
  {
  public:
    options_proxy(std::vector<option>& options) : _options(options) {}
    options_proxy& operator()(char flag, bool has_arg, const std::string& description, bool mandatory = false);
  private:
    std::vector<option>& _options;
  };

public:
  struct arg
  {
    bool        matched;
    std::string arg;
  };

  arg_parse();

  options_proxy& add_options();
  void add_option(char flag, bool has_arg, const std::string& description, bool mandatory = false);

  void print_usage(std::ostream& out) const;
  void parse(int argc, char **argv);
  const std::vector<arg>& get_results() const;

private:
  std::vector<option> _options;
  std::vector<arg>    _args;
  options_proxy       _proxy;
};

}}

#endif /* !UTILS_ARG_PARSE_H_ */
