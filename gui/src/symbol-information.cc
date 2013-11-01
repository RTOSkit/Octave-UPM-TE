/* OctaveUPM - A graphical user interface for Octave
 * Copyright (C) 2013 Israel Herraiz <isra@herraiz.org>
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

#include "symbol-information.h"

symbol_information::symbol_information() : _symbol(""), _type(""), _hidden(true), _editable(false)
{}

int symbol_information::hash () const
{
  return qHash (_symbol) + qHash (_type) + qHash (_value) + qHash (_hidden);
}

bool symbol_information::from_symbol_record(const symbol_table::symbol_record& sr)
{
    _hidden = sr.is_hidden();

    _symbol = QString (sr.name ().c_str ());
    try {
      _type   = QString (sr.varval ().class_name ().c_str ());
    }
    catch (...) {
      _type   = QString("???");
    }

    octave_value ov = sr.varval ();

    // For every type, convert to a human readable string.
    if (ov.is_sq_string ())
    {
      _value = QString ("\'%1\'").arg (ov.string_value ().c_str ());
      _editable = true;
    }
    else if (ov.is_dq_string ())
    {
      _value = QString ("\"%1\"").arg (ov.string_value ().c_str ());
      _editable = true;
    }
    else if (ov.is_real_matrix () || (ov.is_matrix_type () && !ov.is_complex_matrix ()))
    {
      // Check number of dimensions
      size_t ndims = ov.ndims();

      int rows = ov.rows ();
      int columns = ov.columns ();
      int nElements = rows*columns;

      if (ndims > 2)
      {
	  _value = QString ("");
	  const dim_vector dims = ov.array_value ().dims();
	  for (size_t i = 0; i < ndims; i++)
	  {
	    _value += QString("%1").arg(dims (i));
	    if (i<ndims-1)
	      _value += QString("x");
	  }

	  _value += QString(" array");
	  _editable = false;

      }
      else if (nElements > 20)
      {

	_value = QString ("%1x%2 matrix")
          .arg (rows)
          .arg (columns);

	_editable = false;
      }
      else if (ndims<=2)
      {
	QString output = "[";
	for (int i=0; i < rows; i ++)
	{
	  for (int j=0; j < columns; j++)
	  {
	    output += QString("%1").arg (ov.matrix_value ().elem (i,j));
	    if (j<columns-1)
	      output += QString(" ");
	  }
	  if (i<rows-1)
	    output += QString("; ");
	  else
	    output += "]";
	}

	if (rows == 0 && columns == 0)
	  _value = "[]";
	else
	  _value = output;

	_editable = true;
      }
    }
    else if (ov.is_complex_matrix ())
    {
      _value = QString ("%1x%2 matrix (complex)").arg (ov.rows ())
                                .arg (ov.columns ());
      _editable = false;
    }

    else if (ov.is_real_scalar ())
    {
      _value = QString ("%1").arg (ov.scalar_value ());
      _editable = true;
    }
    else if (ov.is_complex_scalar ())
    {
      _value = QString ("%1 + %2i").arg (ov.scalar_value ())
                                   .arg (ov.complex_value ().imag ());
      _editable = true;
    }
    else if (ov.is_integer_type ())
      _value = QString ("%1").arg (ov.scalar_value ());
    else if (ov.is_range ())
      _value =  QString ("%1 : %2 : %3").arg (ov.range_value ().base ())
                                        .arg (ov.range_value ().inc ())
                                        .arg (ov.range_value ().limit ());
    else
      _value = QString ("<Type not recognized>");

    return true;
}