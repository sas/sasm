#include "arg_parse.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>

extern char* __progname; /* From crt0.o */

namespace sasm { namespace utils {

auto arg_parse::options_proxy::operator()(
    char flag,
    bool has_arg,
    const std::string& description,
    bool mandatory
  ) -> options_proxy&
{
  _options[flag] = { true, flag, has_arg, description, mandatory };
  return *this;
}

arg_parse::arg_parse()
  : _proxy(_options)
{
  _options.resize(256, { false, 0, false, "", false });
}

auto arg_parse::add_options() -> options_proxy&
{
  return _proxy;
}

void arg_parse::add_option(char flag, bool has_arg, const std::string& description, bool mandatory)
{
  _proxy(flag, has_arg, description, mandatory);
}

void arg_parse::print_usage(std::ostream& out) const
{
  out << "usage: " << __progname << " [options]" << std::endl;
  out << "  where [options] can be any combination of:" << std::endl;

  for (auto i = _options.begin(); i != _options.end(); ++i)
  {
    if (i->set)
    {
      out << "    -" << i->flag;
      out << (i->has_arg ? " arg: " : ":     ");
      out << i->description;
      if (i->mandatory)
        out << " (mandatory)";
      out << std::endl;
    }
  }
}

void arg_parse::parse(int argc, char **argv)
{
#define die() do { print_usage(std::cerr); exit(EXIT_FAILURE); } while (0)
#define help_exit() do { print_usage(std::cout); exit(EXIT_SUCCESS); } while (0)

  ++argv; --argc;

  _args.resize(256, { false, "" });

  for (int i = 0; i < argc; ++i)
  {
    char matched_flag;

    if (argv[i][0] != '-')
      die();

    matched_flag = argv[i][1];

    if (matched_flag == 'h')
      help_exit();

    if (!_options[matched_flag].set)
      die();

    _args[matched_flag].matched = true;

    if (_options[matched_flag].has_arg)
    {
      if (argv[i][2] != 0)
      {
        _args[matched_flag].arg = std::string(&argv[i][2]);
      }
      else
      {
        if (i + 1 >= argc)
          die();

        _args[matched_flag].arg = std::string(argv[++i]);
      }
    }
  }

  /* Check if all mandatory arguments have been specified. */
  for (auto i = _options.begin(); i != _options.end(); ++i)
  {
    if (i->set && i->mandatory && !_args[i->flag].matched)
      die();
  }

#undef help_exit
#undef die
}

auto arg_parse::get_results() const -> const std::vector<arg>&
{
  return _args;
}

}}
