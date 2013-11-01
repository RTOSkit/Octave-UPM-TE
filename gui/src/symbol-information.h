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

#ifndef SYMBOLINFORMATION_H
#define SYMBOLINFORMATION_H

#include <QString>
#include <QHash>

// Octave includes
#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION
#undef PACKAGE_URL
#include "octave/config.h"
#include "octave/cmd-edit.h"
#include "octave/error.h"
#include "octave/file-io.h"
#include "octave/input.h"
#include "octave/lex.h"
#include "octave/load-path.h"
#include "octave/octave.h"
#include "octave/oct-hist.h"
#include "octave/oct-map.h"
#include "octave/oct-obj.h"
#include "octave/ops.h"
#include "octave/ov.h"
#include "octave/ov-usr-fcn.h"
#include "octave/symtab.h"
#include "octave/pt.h"
#include "octave/pt-eval.h"
#include "octave/config.h"
#include "octave/Range.h"
#include "octave/toplev.h"
#include "octave/procstream.h"
#include "octave/sighandlers.h"
#include "octave/debug.h"
#include "octave/sysdep.h"
#include "octave/ov.h"
#include "octave/unwind-prot.h"
#include "octave/utils.h"
#include "octave/variables.h"

/**
  * \class symbol_information
  * \brief Meta-information over a symbol-table entry.
  * \author Israel Herraiz
  * This struct is used to store meta information over a symbol entry.
  * It reduces memory consumption, since it only stores relevant data
  * about a symbol-table entry that will be used in the model for the
  * graphical user interface.
  */
class symbol_information
{
public:  
  symbol_information ();
  
  QString getSymbol () const {return _symbol;};
  QString getType () const {return _type;};
  QString getValue () const {return _value;};
  bool isHidden () const {return _hidden;};
  bool isEditable () const {return _editable;};
  
  
  /** Hashes the symbol information for quickly comparing it. */
  int  hash () const;
 
  /** Extracts meta information from a given symbol record. */
  bool from_symbol_record (const symbol_table::symbol_record& sr);
  
private:

  QString _symbol;
  QString _type;
  QString _value;
  bool _hidden;
  bool _editable;
  
};

#endif // SYMBOLINFORMATION_H
