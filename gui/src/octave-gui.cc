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

//#include <QtGui/QApplication>
#include <QtSingleApplication>
#include <QTranslator>
#include <QSettings>
#include "welcome-wizard.h"
#include "resource-manager.h"
#include "main-window.h"

int
main (int argc, char *argv[])
{
  QtSingleApplication application (argc, argv);

  if (application.isRunning () && argc > 1)
  {
	  QString o  = QString(argv[1]);
	  application.sendMessage (o);
	  return 0;
  }

  
  //application.addLibraryPath(QCoreApplication::applicationDirPath ()+"/plugins");
  while (true)
    {
      QSettings *settings = resource_manager::instance ()->get_settings ();
      if (resource_manager::instance ()->is_first_run ())
        {
          welcome_wizard welcomeWizard;
          int returnCode = welcomeWizard.exec ();


          settings->setValue ("connectOnStartup", true);
          settings->setValue ("showMessageOfTheDay", true);
          settings->setValue ("showTopic", true);
          settings->setValue ("autoIdentification", false);
          settings->setValue ("nickServPassword", "");
          settings->setValue ("useCustomFileEditor", false);
          settings->setValue ("customFileEditor", "emacs");
          settings->setValue ("editor/showLineNumbers", true);
          settings->setValue ("editor/highlightCurrentLine", true);
          settings->setValue ("editor/codeCompletion", true);
          settings->setValue ("editor/fontName", "Consolas");
          settings->setValue ("editor/fontSize", 10);
          settings->setValue ("editor/longWindowTitle", false);
	  settings->setValue ("editor/autosave", true);
	  settings->setValue ("editor/autosavePeriod", 2);

          settings->setValue ("showFilenames", true);
          settings->setValue ("showFileSize", false);
          settings->setValue ("showFileType", false);
          settings->setValue ("showLastModified", false);
          //settings->setValue ("showHiddenFiles", false);
          settings->setValue ("useAlternatingRowColors", true);
	  settings->setValue ("saveBookmark", true);
	  settings->setValue ("saveBreakpoint", true);
	  settings->setValue ("filebrowser/defaultFont", true);
	  settings->setValue ("workspace/defaultFont", true);
	  settings->setValue ("history/defaultFont", true);
	  settings->setValue ("history/numCommands", 128);
          /*
	  settings->setValue ("useProxyServer", false);
          settings->setValue ("proxyType", "Sock5Proxy");
          settings->setValue ("proxyHostName", "none");
          settings->setValue ("proxyPort", 8080);
          settings->setValue ("proxyUserName", "");
          settings->setValue ("proxyPassword", "");
          */
	  settings->setValue ("terminal/fontName","Lucida Console");
	  settings->setValue ("terminal/fontSize",10);
	  settings->setValue ("terminal/supressWarnings", true);
	  settings->setValue ("terminal/matlabCompatible", false);
	  settings->setValue ("terminal/broadcasting", 2);

	  settings->setValue ("lastDirectory", QDir::homePath ());

	  settings->setValue ("language", 0);

          settings->sync ();
          resource_manager::instance ()->reload_settings ();

          application.quit ();
          // We are in an infinite loop, so everything else than a return
          // will cause the application to restart from the very beginning.
          if (returnCode == QDialog::Rejected)
            return 0;
        }
      else
        {
          //QSettings *settings = resource_manager::instance ()->get_settings ();
          //QString language = settings->value ("language").toString ();
	  //QString language = QString("es_ES");

          //QString translatorFile = ResourceManager::instance ()->findTranslatorFile (language);
          QTranslator translator;

          //translator.load (translatorFile);
	  int lang = settings->value("language",0).toInt();

	  if (lang == 0)
	    translator.load("/usr/share/octave-upm/languages/en-en");
	  else
	    translator.load ("/usr/share/octave-upm/languages/es-es");

          application.installTranslator (&translator);

          //resource_manager::instance ()->update_network_settings ();
          resource_manager::instance ()->load_icons ();

	  QString o;
	  if (argc > 1)
		  o  = QString(argv[1]);

	  main_window w(o);
	  application.setActivationWindow (&w);
          w.show ();
          w.activateWindow();

	  QObject::connect(&application, SIGNAL(messageReceived(const QString&)),
			   &w, SLOT(open_file (const QString&)));
	  
          return application.exec ();
        }
    }
}
