/* OctaveGUI - A graphical user interface for Octave
 * Copyright (C) 2011 Jacob Dawid (jacob.dawid@googlemail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "octave-main-thread.h"
#include "octave-link.h"
#include <complex>

octave_main_thread::octave_main_thread () : QThread ()
{
}

void
octave_main_thread::run ()
{
  setlocale(LC_ALL, "en_US.UTF-8");
  int argc = 5;
  string_vector argv (argc);
         argv(0) = ">>";
         argv(1) = "-q";
         argv(2) = "--traditional";
	 argv(3) = "-i";
	 argv(4) = "--line-editing";
	 //argv(3) = "--no-gui";

  emit ready();
  octave_main (argc, (char **) argv.c_str_vec(), 0);


  //octave_initialize_interpreter (argc, (char **) argv.c_str_vec(), 0);
  //octave_initialize_interpreter (octave_cmdline_argc, octave_cmdline_argv, octave_embedded);

  //octave_execute_interpreter ();
}
