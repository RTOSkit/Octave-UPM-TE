# OctaveGUI - A graphical user interface for Octave
# Copyright (C) 2011 Jacob Dawid (jacob.dawid@googlemail.com)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

# Basic settings:
QT                  += core gui webkit network	    # Qt modules
TEMPLATE            = app                           # Build as application
TARGET              = octave-upm                    # Name of the target binary

DESTDIR             = ./bin                           # Destination of the output

TRANSLATIONS        += languages/generic.ts \
                       languages/de-de.ts \
                       languages/pt-br.ts \
                       languages/es-es.ts \
                       languages/ru-ru.ts \
                       languages/uk-ua.ts           # Available translations

win32-msvc*: include(msvc.pri)

include(../qtsingleapplication/src/qtsingleapplication.pri)

LIBS                += -lreadline -lqscintilla2_octave_upm  \
                       -L../qterminal/libqterminal/$$LIBDIR_SUFFIX -lqterminal \
                        $$system(mkoctfile -p LIBS) \
                        $$system(mkoctfile -p OCTAVE_LIBS)  \
                          -L../qscintilla/Qt4Qt5



mac {
    CONFIG -= app_bundle
}

# Includepaths and libraries to link against:
INCLUDEPATH         += . ../qscintilla/Qt4Qt5  octave-adapter m-editor ../qterminal/libqterminal /usr/include/qt4 \
                       $$system(mkoctfile -p INCFLAGS)  /usr/include/octave-3.6.2/

INCFLAGS            += $$system(mkoctfile -p INCFLAGS)

win32-msvc* {
  INCLUDEPATH += "C:/build/QScintilla-gpl-2.6.1/Qt4" "C:/GnuWin32/src/zlib/1.2.3/zlib-1.2.3" \
                "C:/build/readline/include"

  LIBS += -L"C:/build/QScintilla-gpl-2.6.1/qscintilla-build-desktop-Qt_4_8_1_for_Desktop_-_MSVC2010__Qt_SDK__Release/release" \
          $$system(mkoctfile -p LFLAGS)
}

mac {
    INCFLAGS += -I/opt/local/include
}

QMAKE_LIBDIR        += $$system(octave-config -p OCTLIBDIR)
unix {
    QMAKE_RPATHDIR += $$system(octave-config -p OCTLIBDIR)
}

mac {
    LFLAGS += -L/opt/local/lib
}

unix {
    LIBS += -lutil
}

win32-g++ {
    QMAKE_LFLAGS += --enable-auto-import
}

win32-msvc* {
    DEFINES += QSCINTILLA_DLL
    QMAKE_CXXFLAGS += -wd4244
}

QMAKE_LFLAGS        += $$LFLAGS $$system(mkoctfile -p RLD_FLAG)
QMAKE_CXXFLAGS      += $$INCFLAGS
   
CONFIG += debug

# Files associated with the project:
SOURCES +=\
    octave-adapter/octave-link.cc \
    octave-adapter/octave-main-thread.cc \
    m-editor/file-editor.cc \
    m-editor/file-editor-tab.cc \
    m-editor/find-dialog.cc \
    symbol-information.cc \
    main-window.cc \
    workspace-view.cc \
    workspace-model.cc \
    history-dockwidget.cc \
    files-dockwidget.cc \
    settings-dialog.cc \
    preview-dialog.cc \
    graphics-editor.cc \
    octave-gui.cc \
    resource-manager.cc \
    welcome-wizard.cc \
    terminal-dockwidget.cc \
    octave-qt-event-listener.cc \
    octave-adapter/octave-model-checker-thread.cc \
    octave_plot_properties.cc \
    profile_display.cc \
    doc_viewer.cc \
    doc-viewer/webinfo.cpp \
    doc-viewer/parser.cpp    

HEADERS += \
    octave-adapter/octave-link.h \
    octave-adapter/octave-main-thread.h \
    octave-adapter/octave-event.h \
    octave-adapter/octave-event-observer.h \
    octave-adapter/octave-event-listener.h \
    m-editor/file-editor.h \
    m-editor/file-editor-interface.h \
    m-editor/file-editor-tab.h \
    m-editor/find-dialog.h \
    symbol-information.h \
    main-window.h \
    workspace-view.h \
    workspace-model.h \
    history-dockwidget.h \
    files-dockwidget.h \
    settings-dialog.h \
    preview-dialog.h \
    graphics-editor.h \
    resource-manager.h \
    welcome-wizard.h \
    terminal-dockwidget.h \
    octave-qt-event-listener.h \
    octave-adapter/octave-model-checker-thread.h \
    octave_plot_properties.h \
    profile_display.h \
    doc_viewer.h \
    doc-viewer/parser.h \
    doc-viewer/webinfo.h
    

FORMS += \
    settings-dialog.ui \
    welcome-wizard.ui \
    export-plot.ui \
    graphics-editor.ui 

RESOURCES += \
    octaveupm.qrc \
    doc-viewer/images.qrc

win32:RC_FILE += \
    mainicon.rc
