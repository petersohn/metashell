#ifndef METASHELL_PRAGMA_WITHOUT_ARGUMENTS_HPP
#define METASHELL_PRAGMA_WITHOUT_ARGUMENTS_HPP

// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2014, Abel Sinkovics (abel@sinkovics.hu)
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

#include <metashell/pragma_handler_interface.hpp>

#include <string>

namespace metashell
{
  class shell;

  class pragma_without_arguments : public pragma_handler_interface
  {
  public:
    pragma_without_arguments(shell& shell_, const std::string& name_);

    virtual std::string arguments() const;

    virtual void run(
      const command::iterator& args_begin_,
      const command::iterator& args_end_
    ) const;

    virtual void run() const = 0;

    shell& get_shell() const;
  private:
    shell& _shell;
    std::string _name;
  };
}

#endif

