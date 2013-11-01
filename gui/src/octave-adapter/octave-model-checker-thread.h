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

#ifndef OCTAVEMODELCHECKER_H
#define OCTAVEMODELCHECKER_H

#include <QThread>
#include "workspace-model.h"
#include "workspace-view.h"

/**
  * \class octave_model_checker_thread
  * \brief This class represents a thread checking the workspace model to detect possible changes.
  * \author Israel Herraiz
  */
class octave_model_checker_thread : public QThread, octave_event_observer
{
  Q_OBJECT
public:
  octave_model_checker_thread ();
  virtual ~octave_model_checker_thread();
  void set_model (workspace_model* m);
  void set_view (workspace_view* v);
  void quitting ();

  void event_accepted (octave_event *e);
  void event_reject (octave_event *e);

  void restart ();

protected:

  void run ();
  void check_model ();

private:

  bool              _exit;
  workspace_model*  _model;
  workspace_view*   _view;

  std::list < symbol_table::symbol_record > _my_symbol_table;
  QList <symbol_information> _symbol_information;
  QList <symbol_information> _symbol_information_backup;

  bool _fresh_table;
};

#endif // OCTAVEMODELCHECKER_H
