#ifndef READLINE_ENVIRONMENT_HPP
#define READLINE_ENVIRONMENT_HPP

// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2014, Andras Kucsma (andras.kucsma@gmail.com)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <metashell/readline_completion_function.hpp>

#include <string>

#include <boost/optional.hpp>

#ifdef USE_EDITLINE
#  include <editline/readline.h>
#else
#  include <readline/readline.h>
#  include <readline/history.h>
#endif

namespace metashell {

class readline_environment {
public:
  readline_environment();
  ~readline_environment();

  boost::optional<std::string> readline(const std::string& prompt);
  std::string get_edited_text();
  void add_history(const std::string& line);
  void set_rl_attempted_completion_function(readline_completion_function func);
  unsigned int width() const;

private:
  readline_completion_function *last_rl_attempted_completion_function;
};

}

#endif
