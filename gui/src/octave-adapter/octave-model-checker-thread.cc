/* OctaveGUI - A graphical user interface for Octave
 * Copyright (C) 2012 Israel Herraiz <isra@herraiz.org>
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

#include "octave-model-checker-thread.h"

octave_model_checker_thread::octave_model_checker_thread(): QThread(),
						octave_event_observer(),
						_exit (false),
						_model(NULL),
						_view(NULL),
						_fresh_table(false)
{

}

octave_model_checker_thread::~octave_model_checker_thread()
{
  _my_symbol_table.clear();
  _symbol_information.clear();
  _symbol_information_backup.clear();
}


void
octave_model_checker_thread::run()
{
  while (!_exit)
  {
    check_model();
    octave_link::instance()->post_event (new octave_dummy_event(*this));
    this->msleep(500);
  }
}

void
octave_model_checker_thread::set_model(workspace_model* m)
{
  _model = m;
}

void octave_model_checker_thread::set_view(workspace_view* v)
{
  _view = v;
}


void octave_model_checker_thread::check_model()
{

  if (!_fresh_table || _view->isHidden())
    return;

  _symbol_information_backup = _symbol_information;
  _symbol_information.clear();

  bool two_tables_equal = true;

  int i = 0;
  int n = _symbol_information_backup.size ();
  for (std::list < symbol_table::symbol_record > ::iterator iterator = _my_symbol_table.begin ();
    iterator != _my_symbol_table.end (); ++iterator)
    {
      symbol_information symbolInformation;
      symbolInformation.from_symbol_record (*iterator);
      _symbol_information.push_back (symbolInformation);
      if (i < n && _symbol_information_backup.at(i).hash() != symbolInformation.hash())
	two_tables_equal = false;
      i++;
    }
  if (!two_tables_equal || i != n)
    _model->update_model(_symbol_information);

  _fresh_table = false;
}

void octave_model_checker_thread::quitting()
{
  _exit = true;
}

void octave_model_checker_thread::event_accepted(octave_event* e)
{

  if (_view->isHidden())
    return;


  if (octave_interpreter_ready && !_exit)
  {
    _my_symbol_table.clear ();

    std::stringstream redirectStream;
    std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

    // Capture stderr
    std::stringstream errStreamIgn;
    std::streambuf*     oldErrBuf = std::cerr.rdbuf (errStreamIgn.rdbuf ());
    if (_model->get_current_scope() <= 0)
	_my_symbol_table = symbol_table::all_variables ();
    else
	_my_symbol_table = symbol_table::all_variables (_model->get_current_scope());

    std::cout.rdbuf(oldbuf);
    std::cerr.rdbuf(oldErrBuf);

    _fresh_table = true;
  }

  delete e;
}

void octave_model_checker_thread::event_reject(octave_event* e)
{
  _my_symbol_table.clear ();
  delete e;
}

void octave_model_checker_thread::restart()
{
  _exit = false;
  run();
}

