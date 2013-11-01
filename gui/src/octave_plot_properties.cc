/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2013  Israel Herraiz <isra@herraiz.org>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "octave_plot_properties.h"

std::string const octave_plot_properties::_line_types[octave_plot_properties::_n_line_types] = {std::string("-"), std::string("--"), std::string(":"), std::string("-."), std::string("none")};

/*
std::string const octave_plot_properties::_legend_locations[octave_plot_properties::_n_legend_locations] = {
  std::string("north"),
  std::string("south"),
  std::string("east"),
  std::string("west"),
  std::string("northeast"),
  std::string("northwest"),
  std::string("southeast"),
  std::string("southwest")
};*/

std::string const octave_plot_properties::_marker_types[octave_plot_properties::_n_marker_types] = {
  std::string("none"),
  std::string("+"),
  std::string("*"),
  std::string("o"),
  std::string("x"),
  std::string("^"),
  std::string("."),
  std::string("s"),
  std::string("d"),
  std::string("v"),
  std::string("p"),
  std::string("h")};

octave_plot_properties::octave_plot_properties() :
/*				      _legend_labels(std::vector<std::string>()),
			              _legendfont(10),
			              _legendweight("normal"),
			              _legendlocation(4),
			              _show_legendbox(true),
			              _legend_has_changed(false),*/
			              _legend_handle(octave_value()),
			              _visible(false),
  			              _plot_lines(std::vector<plot_line*>()),
			              _axiswidth(0.5),
			              _axisfont(0),
			              _axisweight("")
{
  _xcolor [0] = 0;
  _xcolor [1] = 0;
  _xcolor [2] = 0;

  _ycolor [0] = 0;
  _ycolor [1] = 0;
  _ycolor [2] = 0;
}

octave_plot_properties::~octave_plot_properties()
{

}

void octave_plot_properties::read_from_octave()
{
  // Background color

  octave_value_list gcal = feval("gca", octave_value_list(), 1);

  octave_value_list getargs;
  octave_value_list vl;
  octave_value v;

  vl.clear ();
  getargs.clear ();
  getargs.append(gcal (0));
  getargs.append("xcolor");
  vl = feval("get",getargs,1);

  v = vl(0);
  _xcolor[0] = 255*v.matrix_value().elem (0);
  _xcolor[1] = 255*v.matrix_value().elem (1);
  _xcolor[2] = 255*v.matrix_value().elem (2);

  vl.clear ();
  getargs.clear ();
  getargs.append(gcal (0));
  getargs.append("ycolor");
  vl = feval("get",getargs,1);

  v = vl(0);

  _ycolor[0] = 255*v.matrix_value().elem (0);
  _ycolor[1] = 255*v.matrix_value().elem (1);
  _ycolor[2] = 255*v.matrix_value().elem (2);

  vl.clear ();
  getargs.clear ();
  getargs.append(gcal (0));
  getargs.append("fontsize");
  vl = feval("get",getargs,1);

  v = vl(0);
  _axisfont = v.int_value ();

  vl.clear ();
  getargs.clear ();
  getargs.append(gcal (0));
  getargs.append("fontweight");
  vl = feval("get",getargs,1);

  v = vl(0);
  _axisweight = v.string_value ();

  vl.clear ();
  getargs.clear ();
  getargs.append(gcal (0));
  getargs.append("linewidth");
  vl = feval("get",getargs,1);

  v = vl(0);
  _axiswidth = v.double_value ();

    // Plot lines colors
  octave_value_list children1args;
  octave_value_list gcf = feval("gcf", octave_value_list(), 1);

  if (gcf.length() == 0)
    return;

  children1args.append(gcf(0));
  children1args.append("children");

  octave_value_list children2 = feval("get", children1args, 1);

  octave_value_list children2args;
  int curves_position = curves_position_in_props(children2);
  children2args.append (children2(0).matrix_value ().elem (curves_position));
  children2args.append ("children");

  vl.clear ();
  vl = feval("get",children2args, 2);

  if (vl.length() == 0)
    return;

  // Clear all the pointers in vector
  for (size_t i = 0; i < _plot_lines.size (); i++)
  {
    delete _plot_lines.back ();
    _plot_lines.pop_back ();
  }

  _plot_lines.clear ();



  //std::string cmd;
  //cmd.append("get(get(gcf,'children'),'children');");

  //v = get_octave_value (cmd);
  v = vl(0);

  for (int i=0; i < v.numel(); i++)
  {
    plot_line *p = new plot_line(v.matrix_value ().elem (i));

    // read color
    octave_value_list l;
    l.append(p->get_id ());
    l.append("color");

    octave_value_list v_line = feval ("get",l,1);

    octave_value x = v_line(0);

    int r = 255*x.matrix_value ().elem (0);
    int g = 255*x.matrix_value ().elem (1);
    int b = 255*x.matrix_value ().elem (2);

    p->set_color (r, g, b);

    l.clear ();
    l.append (p->get_id ());
    l.append ("linewidth");

    v_line = feval("get",l,1);

    x = v_line(0);
    p->set_width (x.matrix_value().elem (0));


    l.clear ();
    l.append (p->get_id ());
    l.append ("linestyle");

    v_line.clear ();
    v_line = feval("get",l,1);
    x = v_line(0);

    std::string s = x.string_value ();

    for(size_t i = 0; i < _n_line_types; i++)
    {
      if (_line_types[i] == s)
      {
	p->set_type (i);
	break;
      }
    }

    l.clear ();
    l.append (p->get_id ());
    l.append ("marker");

    v_line.clear ();
    v_line = feval("get",l,1);
    x = v_line(0);

    s = x.string_value ();

    for(size_t i = 0; i < _n_marker_types; i++)
    {
      if (_marker_types[i] == s)
      {
	p->set_marker (i);
	break;
      }
    }

    l.clear ();
    l.append (p->get_id ());
    l.append ("markersize");

    v_line.clear ();
    v_line = feval("get",l,1);
    x = v_line(0);

    p->set_marker_size (x.int_value ());

    _plot_lines.insert (_plot_lines.end (), p);
  }

}

void octave_plot_properties::set_in_octave ()
{
  // Background

  RowVector c(3);
  octave_value_list lbg;
  octave_value_list gca = feval("gca", octave_value_list(), 1);

  c(0) = double(_xcolor[0])/255;
  c(1) = double(_xcolor[1])/255;
  c(2) = double(_xcolor[2])/255;
  lbg.clear();
  lbg.append(gca(0));
  lbg.append("xcolor");
  lbg.append(c);
  feval("set",lbg,0);

  c(0) = double(_ycolor[0])/255;
  c(1) = double(_ycolor[1])/255;
  c(2) = double(_ycolor[2])/255;
  lbg.clear();
  lbg.append(gca(0));
  lbg.append("ycolor");
  lbg.append(c);
  feval("set",lbg,0);

  lbg.clear();
  lbg.append(gca(0));
  lbg.append("fontsize");
  lbg.append(_axisfont);
  feval("set",lbg,0);


  lbg.clear();
  lbg.append(gca(0));
  lbg.append("fontweight");
  lbg.append(_axisweight);
  feval("set",lbg,0);

  lbg.clear();
  lbg.append(gca(0));
  lbg.append("linewidth");
  lbg.append(_axiswidth);
  feval("set",lbg,0);


  // Plot lines

  size_t n = _plot_lines.size ();
  for(size_t i=0; i < n; i++)
  {
    plot_line *p = _plot_lines.at (i);
    octave_value_list l;
    l.append(p->get_id ());
    l.append("color");
    RowVector v(3);
    const int* color = p->get_color ();
    double r = double(color[0]);
    double g = double(color[1]);
    double b = double(color[2]);

    v(0) = (r/255);
    v(1) = (g/255);
    v(2) = (b/255);
    l.append (v);

    feval("set",l,0);


    l.clear ();
    l.append (p->get_id ());
    l.append ("linewidth");
    l.append (p->get_width ());

    feval("set",l,0);

    l.clear ();
    l.append (p->get_id ());
    l.append ("linestyle");
    l.append(_line_types [p->get_type ()]);

    feval("set",l,0);


    l.clear ();
    l.append (p->get_id ());
    l.append ("marker");
    l.append(_marker_types [p->get_marker ()]);

    feval("set",l,0);

    l.clear ();
    l.append (p->get_id ());
    l.append ("markersize");
    l.append(p->get_marker_size ());

    feval("set",l,0);


  }
/*
  if (_legend_has_changed)
  {
    _legend_has_changed = false;

    octave_value_list legend_args;
    legend_args.append(_legend_handle);
    legend_args.append("location");
    legend_args.append(_legend_locations[_legendlocation]);
    feval("set", legend_args, 1);

    return;

    for (size_t k = 0; k<_legend_labels.size(); k++)
    {
      legend_args.append(_legend_labels.at(k));
    }
    legend_args.append("location");
    legend_args.append(_legend_locations[_legendlocation]);
    //legend_handle = feval("legend", legend_args, 1)(0);



    legend_args.clear();
    legend_args.append(_legend_handle);
    legend_args.append("box");
    if (_show_legendbox)
      legend_args.append("on");
    else
      legend_args.append("off");
    feval("set", legend_args, 0);

    legend_args.clear();
    legend_args.append(_legend_handle);
    legend_args.append("fontsize");
    legend_args.append(_legendfont);
    feval("set", legend_args, 0);

    legend_args.clear();
    legend_args.append(_legend_handle);
    legend_args.append("fontweight");
    legend_args.append(_legendweight);
    feval("set", legend_args, 0);

  }
*/
}

const octave_value octave_plot_properties::get_octave_value(const std::string& cmd)
{
  int parse_status;

  octave_value v = eval_string (cmd, false, parse_status);
  octave_event::finish_readline_event ();

  return v;
}

void octave_plot_properties::update_plot_color(const size_t& k, const int& r, const int& g, const int& b)
{
  plot_line *p = _plot_lines.at (k);
  p->set_color (r,g,b);
}

void octave_plot_properties::set_visible(const bool& v)
{
  octave_value_list gcf = feval("gcf", octave_value_list(), 1);

  _visible = v;

  // Disable visibility
  octave_value_list visl;
  visl.append(gcf(0));
  visl.append("visible");

  if (v)
    visl.append ("on");
  else
    visl.append("off");

  feval("set",visl,0);

}

bool octave_plot_properties::is_2d_plot()
{
  octave_value_list gca = feval("gca",octave_value_list(),1);
  octave_value_list args;
  args.append(gca(0));
  args.append("view");
  octave_value_list view = feval("get",args,1);

  octave_value v = view(0);

  if (v.matrix_value ().elem(0) == 0 && v.matrix_value ().elem(1) == 90)
    return true;

  return false;
}

void octave_plot_properties::toggle_grid(bool minor)
{

  octave_value_list args;
  if(minor)
    args.append("minor");

  feval("grid", args, 0);
}

void octave_plot_properties::set_xcolor(const int& r, const int& g, const int& b)
{
  _xcolor[0] = r;
  _xcolor[1] = g;
  _xcolor[2] = b;
}

void octave_plot_properties::set_ycolor(const int& r, const int& g, const int& b)
{
  _ycolor[0] = r;
  _ycolor[1] = g;
  _ycolor[2] = b;
}

int octave_plot_properties::curves_position_in_props(const octave_value_list& children_prop)
{
  octave_value children2v = children_prop(0);

  int curves_position = -1;

  //_legend_labels.clear();

  for (int i = 0; i < children2v.numel (); i++)
  {

    octave_value_list tag_args;
    tag_args.append(children2v.matrix_value ().elem(i));
    tag_args.append("tag");
    octave_value_list tag = feval("get", tag_args, 1);

    std::string tags = tag(0).string_value ();

    if (tags != "legend")
      curves_position = i;
    else
    {
      _legend_handle = children2v.matrix_value(). elem (i);
/*
      octave_value_list l_args;
      l_args.append(_legend_handle);
      l_args.append("userdata");
      octave_value_list l_list = feval("get", l_args, 1);
      octave_value l = l_list(0);
      octave_value_list lm_handle_args;
      lm_handle_args.append(l.map_value ());
      lm_handle_args.append("handle");
      octave_value_list lm_handle = feval("getfield", lm_handle_args, 1);
      octave_value handle = lm_handle(0);

      octave_value_list l_children_args;
      l_children_args.append(handle);
      l_children_args.append("children");
      octave_value l_children = feval("get", l_children_args, 1)(0);

      for (int k = 0; k < l_children.numel (); k++)
      {
	octave_value_list s_args;
	s_args.append(l_children.matrix_value(). elem(k));
	s_args.append("displayname");
	octave_value s = feval("get", s_args, 1)(0);
	_legend_labels.push_back (s.string_value ());
      }

      octave_value fontsize_l;
      octave_value_list fontsize_args;
      fontsize_args.append(_legend_handle);
      fontsize_args.append("fontsize");
      fontsize_l = feval("get", fontsize_args, 1)(0);
      _legendfont = fontsize_l.int_value ();

      octave_value location_l;
      octave_value_list location_args;
      location_args.append(_legend_handle);
      location_args.append("location");
      location_l = feval("get", location_args, 1)(0);
      std::string location = location_l.string_value ();
      for (size_t j = 0; j < _n_legend_locations; j++)
      {
	if (_legend_locations[j] == location)
	{
	  _legendlocation = j;
	  break;
	}
      }

      octave_value weight_l;
      octave_value_list weight_args;
      weight_args.append(_legend_handle);
      weight_args.append("fontweight");
      weight_l = feval("get", weight_args, 1)(0);
      _legendweight = weight_l.string_value ();

      octave_value box_l;
      octave_value_list box_args;
      box_args.append(_legend_handle);
      box_args.append("box");
      box_l = feval("get", box_args, 1)(0);

      std::string box = box_l.string_value ();
      _show_legendbox = box == "on";
*/
    }
  }

  return curves_position;
}

/*
void octave_plot_properties::update_legend_props()
{


   // Plot lines colors
  octave_value_list children1args;
  octave_value_list gcf = feval("gcf", octave_value_list(), 1);

  if (gcf.length() == 0)
    return;

  children1args.append(gcf(0));
  children1args.append("children");

  octave_value_list children2 = feval("get", children1args, 1);

  curves_position_in_props(children2);
}
*/


plot_line::plot_line(const octave_value& id) : _id(id), _color(), _width(0.00), _type(0), _marker(0), _marker_size(0)
{
}

