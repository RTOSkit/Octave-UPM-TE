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


#ifndef OCTAVE_PLOT_PROPERTIES_H
#define OCTAVE_PLOT_PROPERTIES_H
#include <vector>
#include <string>

#include "octave-adapter/octave-link.h"
#include <octave-event.h>

class plot_line
{
public:
    plot_line (const octave_value& id);


    const octave_value& get_id () { return _id;}
    const int* get_color () {return _color;}

    void set_id (const octave_value & s) {_id = s;};
    void set_color (int r, int g, int  b) {
      _color[0] = r;
      _color[1] = g;
      _color[2] = b;
    };

    double get_width () { return _width;};
    void set_width (double w) { _width = w;};

    int get_type () { return _type;};
    void set_type (int t) { _type = t;};

    int get_marker () { return _marker;};
    void set_marker (int m) { _marker = m;};

    int get_marker_size () {return _marker_size;};
    void set_marker_size (int s) { _marker_size = s;};

private:

  octave_value _id;
  int _color [3];
  double _width;
  int _type;
  int _marker;
  int _marker_size;
};

class octave_plot_properties
{

public:
    octave_plot_properties ();
    ~octave_plot_properties ();

    bool is_2d_plot ();

    void read_from_octave ();
    void set_in_octave ();
    void regenerate_legend ();

    void toggle_grid (bool minor);

    const double& get_axis_width () { return _axiswidth;};
    void set_axis_wdith (const double &d) {_axiswidth = d;};
    const int& get_axis_fontsize () { return _axisfont;};
    void set_axis_fontsize (const int &f) {_axisfont = f;};
    const std::string& get_axis_fontweight () { return _axisweight;};
    void set_axis_fontweight (const std::string &s) { _axisweight=s;};
    const int* get_xcolor () {return _xcolor;};
    void set_xcolor (const int& r, const int& g, const int& b);
    const int *get_ycolor () {return _ycolor;};
    void set_ycolor (const int& r, const int &g, const int& b);

    const std::vector<plot_line*>& get_plot_lines () {return _plot_lines;};

    void update_plot_color (const size_t& k, const int& r, const int& g, const int& b);

    const bool& is_visible () { return _visible;};
    void set_visible (const bool& v);

    /*
    std::vector<std::string> get_legend_labels () { return _legend_labels;};
    void set_legend_labels (std::vector<std::string> l) { _legend_labels = l;};
    int get_legend_font () { return _legendfont;};
    void set_legend_font (int f) {_legendfont = f;};
    std::string get_legend_weight () { return _legendweight;};
    void set_legend_weight (std::string w) { _legendweight = w;};
    size_t get_legend_location () { return _legendlocation;};
    void set_legend_location (size_t n) { _legendlocation = n;};
    bool get_show_legendbox () { return _show_legendbox;};
    void set_show_legendbox (bool b) { _show_legendbox = b;};

    void update_legend_props ();

    void legend_has_changed () { _legend_has_changed = true;};
    */

private:

    const octave_value get_octave_value (const std::string& cmd);


    int curves_position_in_props (const octave_value_list& children_prop);

    /*
    std::vector<std::string> _legend_labels;
    int _legendfont;
    std::string _legendweight;
    size_t _legendlocation;
    bool _show_legendbox;
    bool _legend_has_changed;
    */
    octave_value _legend_handle;

    /*
    static const size_t _n_legend_locations = 8;
    static const std::string _legend_locations [_n_legend_locations];
    */

    bool _visible;

    int _xcolor [3];
    int _ycolor [3];
    std::vector<plot_line*> _plot_lines;
    double _axiswidth;
    int _axisfont;
    std::string _axisweight;

    static const size_t _n_line_types = 5;
    static const std::string _line_types [_n_line_types];

    static const size_t _n_marker_types = 12;
    static const std::string _marker_types [_n_marker_types];
};


#endif // OCTAVE_PLOT_PROPERTIES_H
