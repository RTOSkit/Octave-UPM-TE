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

#ifndef OCTAVEEVENT_H
#define OCTAVEEVENT_H

#include <string>
#include "octave-link.h"
#include "octave/config.h"

#include "octave-event-observer.h"
#include <oct-env.h>
#include <parse.h>
#include <sstream>
#include <iostream>
#include <QString>
#include <QStringList>
#include <QFileInfo>

#include <readline/readline.h>
#include <ctime>

/**
  * \class octave_event
  * \brief Base class for an octave event.
  * In order to make communication with octave threadsafe, comunication is
  * implemented via events. An application may create events and post them,
  * however there is no guarantee events will be processed in a given time.
  *
  * In order to create an event, there must be an event observer. The event
  * observer will be given the opportunity to react on the event as soon as
  * it has been processed in the octave thread. Accepting and ignoring takes
  * places in the octave thread.
  */
class octave_event
{
  public:
    octave_event (octave_event_observer& o)
      : _octave_event_observer (o)
    { }

    virtual ~octave_event ()
    { }

    /** Performs what is necessary to make this event happen.
      * This code is thread-safe since it will be executed in the octave thread.
      * However, you should take care to keep this code as short as possible. */
    virtual bool perform () = 0;

    /**
      * Accepts this event. This allows the event observer to react properly
      * onto the event.
      */
    void accept ()
    { _octave_event_observer.event_accepted (this); }

    /**
      * Rejects this event. This allows the event observer to react properly
      * onto the event.
      */
    void reject ()
    { _octave_event_observer.event_reject (this); }


   static void finish_readline_event ()
   {
      rl_line_buffer[0] = '\0';
      rl_point = rl_end = 0;
      rl_done = 1;
      //rl_forced_update_display ();
    }


  protected:
    octave_value_list call_octave_function (std::string name,
                               const octave_value_list& args = octave_value_list (),
                               int nargout = 0)
    {
      try
      {

        return feval (name, args, nargout);
      } catch (...) {
	//std::cout << "% Exception! Command was: " << name << std::endl;
	return octave_value_list ();
      } // Ignore exceptions. Crashes without that.
    }


  private:
    octave_event_observer& _octave_event_observer;
};

class octave_update_history_event : public octave_event
{
  public:
    /** Creates a new octave_exit_event. */
    octave_update_history_event (octave_event_observer& o)
      : octave_event (o)
    { }

    bool perform ()
    { return true; /* Always grant. */ }
};

class octave_update_workspace_event : public octave_event
{
  public:
    /** Creates a new octave_exit_event. */
    octave_update_workspace_event (octave_event_observer& o, int scope_id = -1, bool force = false)
      : octave_event (o)
    {
      _scope_id = scope_id;
      _force = force;
    }

    bool perform ()
    { return true; /* Always grant. */ }

    int get_scope_id ()
    {
      return _scope_id;
    }

    bool force () {return _force;}

  private:
    int _scope_id;
    bool _force;

};

/** Implements an octave exit event. */
class octave_exit_event : public octave_event
{
  public:
    /** Creates a new octave_exit_event. */
    octave_exit_event (octave_event_observer& o)
      : octave_event (o)
    { }

    bool perform ()
    { clean_up_and_exit (0); return true; }
};

/** Implements a change directory events. */
class octave_change_directory_event : public octave_event
{
  public:
    /** Creates a new octave_change_directory_event. */
    octave_change_directory_event (octave_event_observer& o,
                                   std::string directory)
      : octave_event (o), _directory(directory)
    {}

    bool perform ()
    {

      std::string cmd="";
      try
      {
	int parse_status;

        cmd.append ("cd (\"");
        cmd.append (_directory);
        cmd.append ("\");");
        eval_string (cmd, false, parse_status);
        return true;
      } catch (...) {
	//std::cout << "% Exception! Command was: " << cmd << std::endl;
	return false;
      } // Ignore exceptions. Crashes without that.

      //return octave_env::chdir (_directory);

    }

  private:
    std::string _directory;
};

class octave_debug_step_into_event : public octave_event
{
  public:
    /** Creates a new octave_debug_step_into_event. */
    octave_debug_step_into_event (octave_event_observer& o)
      : octave_event (o) { }

    bool perform ()
    {
      octave_value_list args;
      args.append (octave_value ("in"));
      call_octave_function ("dbstep", args);
      finish_readline_event ();
      return true;
    }
};

class octave_debug_step_over_event : public octave_event
{
  public:
    /** Creates a new octave_debug_step_over_event. */
    octave_debug_step_over_event (octave_event_observer& o)
      : octave_event (o) { }

    bool perform ()
    {
      call_octave_function ("dbnext");
      finish_readline_event ();
      return true;
    }
};

class octave_debug_step_out_event : public octave_event
{
  public:
    /** Creates a new octave_debug_step_out_event. */
    octave_debug_step_out_event (octave_event_observer& o)
      : octave_event (o) { }

    bool perform ()
    {
      octave_value_list args;
      args.append (octave_value ("out"));
      call_octave_function ("dbstep", args);
      finish_readline_event ();
      return true;
    }
};

class octave_debug_continue_event : public octave_event
{
  public:
    /** Creates a new octave_debug_step_out_event. */
    octave_debug_continue_event (octave_event_observer& o)
      : octave_event (o) { }

    bool perform ()
    {
      call_octave_function ("dbcont");
      finish_readline_event ();
      return true;
    }
};

class octave_debug_quit_event : public octave_event
{
  public:
    /** Creates a new octave_debug_step_out_event. */
    octave_debug_quit_event (octave_event_observer& o)
      : octave_event (o) { }

    bool perform ()
    {
      call_octave_function ("dbquit");
      finish_readline_event ();
      return true;
    }
};

/** Implements a clear workspace event*/
class octave_clear_event : public octave_event
{
  public:
    /** Creates a new octave_change_directory_event. */
    octave_clear_event(octave_event_observer& o)
      : octave_event (o)
    {  }

    bool perform ()
    {
      call_octave_function ("clear");
      return true;
    }
};

/** Implements a save workspace event*/
class octave_save_event : public octave_event
{
  public:
    /** Creates a new octave_change_directory_event. */
    octave_save_event(octave_event_observer& o, std::string fn)
      : octave_event (o), _fn (fn)
    {}

    bool perform ()
    {
      std::string cmd = "";
      int parse_status;
      cmd.append("save  (\"-mat\",\"");
      cmd.append(_fn);
      cmd.append("\");");

      try {
	eval_string (cmd, false, parse_status, 0);
	return true;
      } catch (...) {
	  //std::cout << "% Exception! Command was: " << cmd << std::endl;
	  return false;
      }
    }

  private:
    std::string _fn;
};

/** Implements a load workspace event*/
class octave_load_event : public octave_event
{
  public:

    octave_load_event(octave_event_observer& o, std::string fn)
      : octave_event (o), _fn (fn)
    {}

    bool perform ()
    {
      std::string cmd = "";
      int parse_status;
      cmd.append("load  (\"-mat\",\"");
      cmd.append(_fn);
      cmd.append("\");");

      try {
	eval_string (cmd, false, parse_status, 0);
	eval_string ("\n", true, parse_status, 0);
	return true;
      } catch (...) {
	//std::cout << "% Exception! Command was: " << cmd << std::endl;
	return false;
      }

    }

  private:
    std::string _fn;
};

class octave_warning_event : public octave_event
{
  public:

    octave_warning_event(octave_event_observer& o, std::string cmd)
      : octave_event (o), _cmd (cmd)
    {}

    bool perform ()
    {
      octave_value_list args;
      args.append (octave_value (_cmd));
      // Capture stdout
      std::stringstream redirectStream;
      std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

      // Capture stderr
      std::stringstream errStreamIgn;
      std::streambuf*     oldErrBuf = std::cerr.rdbuf (errStreamIgn.rdbuf ());
      call_octave_function ("warning", args, 0);
      std::cout.rdbuf(oldbuf);
      std::cerr.rdbuf(oldErrBuf);

      //finish_readline_event ();
      return true;
    }

  private:
    std::string _cmd;
};

class octave_matlab_compatible_event : public octave_event
{
  public:

    octave_matlab_compatible_event(octave_event_observer& o, std::string cmd)
      : octave_event (o), _cmd (cmd)
    {}

    bool perform ()
    {
      octave_value_list args;
      args.append (octave_value (_cmd));
      args.append ("Octave:matlab-incompatible");

      // Capture stdout
      std::stringstream redirectStream;
      std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

      // Capture stderr
      std::stringstream errStreamIgn;
      std::streambuf*     oldErrBuf = std::cerr.rdbuf (errStreamIgn.rdbuf ());
      call_octave_function ("warning", args, 0);
      std::cout.rdbuf(oldbuf);
      std::cerr.rdbuf(oldErrBuf);

      //finish_readline_event ();
      return true;
    }

  private:
    std::string _cmd;
};

class octave_graphics_toolkit_event : public octave_event
{
  public:

    octave_graphics_toolkit_event(octave_event_observer& o, std::string toolkit)
      : octave_event (o), _toolkit(toolkit)
    {}

    bool perform ()
    {
      octave_value_list args;
      args.append (_toolkit);

      // Capture stdout
      std::stringstream redirectStream;
      std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

      // Capture stderr
      std::stringstream errStreamIgn;
      std::streambuf*     oldErrBuf = std::cerr.rdbuf (errStreamIgn.rdbuf ());
      call_octave_function ("graphics_toolkit", args, 0);
      std::cout.rdbuf(oldbuf);
      std::cerr.rdbuf(oldErrBuf);

      //finish_readline_event ();
      return true;
    }

  private:
    std::string _toolkit;
};

class octave_available_toolkits_event : public octave_event
{
public:
    octave_available_toolkits_event(octave_event_observer& o) : octave_event (o)
    { _toolkits.clear(); }

    bool perform ()
    {
      // Capture stdout
      std::stringstream redirectStream;
      std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

      // Capture stderr
      std::stringstream errStreamIgn;
      std::streambuf*     oldErrBuf = std::cerr.rdbuf (errStreamIgn.rdbuf ());

      octave_value_list available_toolkits = call_octave_function ("available_graphics_toolkits", octave_value_list (), 1);
      octave_value_list current_toolkit = call_octave_function ("graphics_toolkit", octave_value_list (), 1);

      std::cout.rdbuf(oldbuf);
      std::cerr.rdbuf(oldErrBuf);

      if (available_toolkits.length() > 0)
      {
	octave_value toolkits = available_toolkits(0);
	octave_value mytoolkit = current_toolkit (0);

	_current_toolkit = QString("%1").arg (mytoolkit.string_value ().c_str ());

	octave_value_list z = toolkits.list_value();

	for (int j=0; j < z.length (); j++)
	{
	  octave_value w = z(j);
	  QString s = QString ("%1").arg (w.string_value ().c_str());

	  _toolkits.append (s);
	}

	if (!_toolkits.contains(_current_toolkit))
	{
	  _current_toolkit = QString("gnuplot");
	}
      }

      finish_readline_event ();
      return true;
    }

    QStringList get_toolkits () { return _toolkits;}
    QString     get_current_toolkit () { return _current_toolkit;}

private:
  QStringList _toolkits;
  QString     _current_toolkit;
};

class octave_clear_history_event : public octave_event
{
  public:
    /** Creates a new octave_clear_history_event. */
    octave_clear_history_event (octave_event_observer& o,
				int n)
      : octave_event (o), _nCommands(n)
    {}

    bool perform ()
    {
      octave_value_list args;
      args.append (octave_value (_nCommands));
      // Capture stdout
      std::stringstream redirectStream;
      std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

      // Capture stderr
      std::stringstream errStreamIgn;
      std::streambuf*     oldErrBuf = std::cerr.rdbuf (errStreamIgn.rdbuf ());
      call_octave_function ("history_size", args, 0);
      std::cout.rdbuf(oldbuf);
      std::cerr.rdbuf(oldErrBuf);

      //finish_readline_event ();

      return true;
    }
private:

  int _nCommands;
};

class octave_add_breakpoint_event : public octave_event
{
  public:
    octave_add_breakpoint_event (octave_event_observer& o,
                                 std::string path,
                                 std::string function_name,
                                 int line)
      : octave_event (o), _path (path), _function_name(function_name), _line(line)
    {}

    bool perform ()
    {
      try {
	bp_table::intmap intmap;
	intmap[0] = _line + 1;

	std::string previous_directory = octave_env::get_current_directory ();
	octave_env::chdir (_path);
	intmap = bp_table::add_breakpoint (_function_name, intmap);
	octave_env::chdir (previous_directory);
	return intmap.size () > 0;
	} catch (...) {
	  //std::cout << "% Exception! Command was: add_breakpoint\n";
	  return false;
	}
    }


    std::string get_path ()
    {
      return _path;
    }

    std::string get_function_name ()
    {
      return _function_name;
    }

    int get_line ()
    {
      return _line;
    }

  private:
    std::string _path;
    std::string _function_name;
    int _line;
};


class octave_remove_breakpoint_event : public octave_event
{
  public:
    octave_remove_breakpoint_event (octave_event_observer& o,
			            std::string path,
			            std::string function_name,
			            int line)
      : octave_event (o), _path (path), _function_name(function_name), _line(line)
    {
    }

    bool perform ()
    {
      try {
	bp_table::intmap intmap;
	intmap[0] = _line;

	std::string previous_directory = octave_env::get_current_directory ();
	octave_env::chdir (_path);
	bp_table::remove_breakpoint (_function_name, intmap);
	octave_env::chdir (previous_directory);
	return true; // TODO: Check result.
      }
      catch (...) {
	//std::cout << "% Exception! Command was: remove_breakpoint" << std::endl;
	return false;
      }
    }

    std::string get_path ()
    {
      return _path;
    }

    std::string get_function_name ()
    {
      return _function_name;
    }

    int get_line ()
    {
      return _line;
    }

  private:
    std::string _path;
    std::string _function_name;
    int _line;
};

class octave_remove_all_breakpoints_event : public octave_event
{
  public:
    octave_remove_all_breakpoints_event (octave_event_observer& o,
			                 std::string path,
			                 std::string function_name)
      : octave_event (o), _path(path), _function_name(function_name)
    {}

    bool perform ()
    {
      try {
	bp_table::intmap intmap;
	std::string previous_directory = octave_env::get_current_directory ();
	octave_env::chdir (_path);
	intmap = bp_table::remove_all_breakpoints_in_file (_function_name, true);
	octave_env::chdir (previous_directory);
	return intmap.size() > 0;
      } catch (...) {
	//std::cout << "% Exception! Command was: remove_all_breakpoints_in_file" << std::endl;
	return false;
      }
    }

    std::string get_path ()
    {
      return _path;
    }

    std::string get_function_name ()
    {
      return _function_name;
    }

  private:
    std::string _path;
    std::string _function_name;
};

class octave_highlight_debug_event : public octave_event
{
  public:
    octave_highlight_debug_event(octave_event_observer& o)
    : octave_event (o), _path (QFileInfo()), _line(0), _current_scope(0), _names(), _scopes()
    {}

    bool perform ()
    {
      // Get names and scopes

      // Disable more for dbstack and dbwhere
      octave_value_list a;
      a.append("off");
      call_octave_function("more", a, 0);
      octave_value_list x = call_octave_function ("dbstack", octave_value_list (), 1);

      if (x.length() > 0)
      {
	octave_value y = x(0);
	octave_map z = y.map_value();
	Cell names = z.getfield("name");
	Cell scopes = z.getfield("scope");

	for (int j=0; j < names.length(); j++)
	{
	  _names.append (QString (names.cellstr_value ()(j).c_str ()));
	  _scopes.append ((symbol_table::scope_id) scopes(j).int_value ());
	}


	_current_scope = symbol_table::current_scope();

      }


      // Get current pos and file

      // Capture stdout
      std::stringstream redirectStream;
      std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

      // Capture stderr
      std::stringstream errStreamIgn;
      std::streambuf*     oldErrBuf = std::cerr.rdbuf (errStreamIgn.rdbuf ());
      try {
        call_octave_function ("dbwhere", octave_value_list (), 0);
      } catch (...)
      {
          std::cout.rdbuf(oldbuf);
          std::cerr.rdbuf(oldErrBuf);
	  a.clear();
	  a.append("on");
	  call_octave_function("more", a, 0);

          return false;
      }


      std::cout.rdbuf(oldbuf);
      std::cerr.rdbuf(oldErrBuf);
      a.clear();
      a.append("on");
      call_octave_function("more", a, 0);



      QString o(redirectStream.str ().c_str ());
      if (o.contains("stopped in") && o.contains ("line"))
      {
        QStringList ol = o.split("in ");
        _path = QFileInfo(ol.at(1).split(" at").at(0).trimmed());
        ol = o.split("line ").at(1).trimmed().split("\n");
        _line = ol.at(0).trimmed().toInt();
        return true;
      }

      //finish_readline_event ();

      return false;
    }

    QFileInfo get_path ()
    {
      return _path;
    }

    int get_line ()
    {
      return _line;
    }

    QList<symbol_table::scope_id> get_scopes ()
    {
      return _scopes;
    }

    QStringList get_names ()
    {
      return _names;
    }

    symbol_table::scope_id get_current_scope ()
    {
      return _current_scope;
    }

  private:
    QFileInfo _path;
    int _line;
    symbol_table::scope_id _current_scope;
    QStringList _names;
    QList<symbol_table::scope_id> _scopes;
};

class octave_run_command_event : public octave_event
{
  public:

	octave_run_command_event (octave_event_observer& o, std::string cmd, bool profiling = false, bool eval = true)
		: octave_event (o), _cmd (cmd), _profiling (profiling), _eval (eval)
	{};

    bool perform ()
    {
	    if (_eval)
	    {
		    int parse_status;
		    eval_string (_cmd, true, parse_status);
	    }
	    else
	    {
		    if (_profiling)
		    {
			    octave_value_list o;
			    o.append(octave_value("on"));
			    feval("profile", o, 0);
		    }


		    feval (_cmd, octave_value_list (), 0);
		    
		    if (_profiling)
		    {
			    octave_value_list o;
			    o.append(octave_value("off"));
			    feval("profile", o, 0);
			    
			    octave_value_list a;
			    a.append ("info");
			    octave_value_list s = feval ("profile", a, 1);
			    if (s(0).is_map ())
				    _profile_info = s(0).map_value ();
			    else
				    _profile_info = octave_map ();
		    }
	    }
      finish_readline_event ();

      return true;
    };

    bool is_profiling () {return _profiling;};
    octave_map get_profile_info () {return _profile_info;};
    std::string get_cmd_timestamp () {
	    time_t now = time(NULL);
	    struct tm * ptm = localtime(&now);
	    char buffer[32];
	    // Format: Mo, 15.06.2009 20:20:00
	    strftime (buffer, 32, "%Y-%m-%d %H:%M:%S", ptm);
	    std::string stime = buffer;
	    return _cmd + " @ " + stime;
    }
							    
  private:
    std::string _cmd;
    bool _profiling;
    bool _eval;
    octave_map _profile_info;
};

class octave_broadcasting_event : public octave_event
{
  public:

    octave_broadcasting_event(octave_event_observer& o, std::string cmd)
      : octave_event (o), _cmd(cmd)
    {}

    bool perform ()
    {
      octave_value_list args;
      args.append (octave_value (_cmd));
      args.append ("Octave:broadcast");

      // Capture stdout
      std::stringstream redirectStream;
      std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

      // Capture stderr
      std::stringstream errStreamIgn;
      std::streambuf*     oldErrBuf = std::cerr.rdbuf (errStreamIgn.rdbuf ());
      call_octave_function ("warning", args, 0);
      std::cout.rdbuf(oldbuf);
      std::cerr.rdbuf(oldErrBuf);

      //finish_readline_event ();
      return true;
    }

  private:
    std::string _cmd;
};

class octave_dummy_event : public octave_event
{
public:
    octave_dummy_event(octave_event_observer& o):octave_event(o)
    {}

    bool perform() {return true;};
};

class octave_more_event : public octave_event
{
public:
    octave_more_event(octave_event_observer& o, bool m) : octave_event(o), _m(m)
    {}

    bool perform ()
    {
      return true;

      octave_value_list args;
      if (_m)
	args.append ("on");
      else
	args.append ("off");

      // Capture stdout
      std::stringstream redirectStream;
      std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

      // Capture stderr
      std::stringstream errStreamIgn;
      std::streambuf*     oldErrBuf = std::cerr.rdbuf (errStreamIgn.rdbuf ());
      call_octave_function ("more", args, 0);
      std::cout.rdbuf(oldbuf);
      std::cerr.rdbuf(oldErrBuf);

      //finish_readline_event ();
      return true;
    };

private:
  bool  _m;
};

class octave_plot_event : public octave_event
{
  public:

    octave_plot_event(octave_event_observer& o, std::string func, octave_value_list args = octave_value_list ())
      : octave_event (o), _func(func), _args(args)
    {}

    bool perform ()
    {
      call_octave_function (_func, _args, 0);
      return true;
    }

  private:
    std::string _func;
    octave_value_list _args;
};

class octave_infofile_event : public octave_event
{
public:
	octave_infofile_event (octave_event_observer& o, std::string f) : octave_event (o), _field (f), _infofile ("")	{}

	bool perform ()
	{		
		octave_map config = feval ("octave_config_info", octave_value_list (), 0)(0).map_value ();
		octave_value infofilev = config.getfield("infofile");
		_infofile = infofilev.string_value ();

		return true;
	}

	std::string get_infofile () { return _infofile;}

private:

	std::string _field;
	std::string _infofile;
};

#endif // OCTAVEEVENT_H
