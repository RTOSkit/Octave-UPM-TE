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

#include "resource-manager.h"
#include "settings-dialog.h"
#include "ui_settings-dialog.h"
#include <QSettings>

settings_dialog::settings_dialog (QWidget * parent):
QDialog (parent), ui (new Ui::settings_dialog)
{
  ui->setupUi (this);
  ui->tabWidget->setCurrentIndex (0);

  connect (ui->okButton,	SIGNAL (pressed()),
	   this,		SLOT (write_settings()));

  connect (ui->cancelButton,	SIGNAL (pressed()),
	   this,		SLOT (close()));
}

void
settings_dialog::write_settings ()
{
  QSettings *settings = resource_manager::instance ()->get_settings ();
  //settings->setValue ("useCustomFileEditor", ui->useCustomFileEditor->isChecked ());
  //settings->setValue ("customFileEditor", ui->customFileEditor->text ());
  settings->setValue ("editor/showLineNumbers", ui->editor_showLineNumbers->isChecked ());
  settings->setValue ("editor/highlightCurrentLine", ui->editor_highlightCurrentLine->isChecked ());
  settings->setValue ("editor/codeCompletion", ui->editor_codeCompletion->isChecked ());
  settings->setValue ("editor/fontName", ui->editor_fontName->currentFont().family());
  settings->setValue ("editor/fontSize", ui->editor_fontSize->value());
  settings->setValue ("editor/longWindowTitle", ui->editor_longWindowTitle->isChecked());
  settings->setValue ("editor/autosave", ui->autosaveFiles->isChecked());
  settings->setValue ("editor/autosavePeriod", ui->autosavePeriod->value());


  settings->setValue ("terminal/fontSize", ui->terminal_fontSize->value());
  settings->setValue ("terminal/fontName", ui->terminal_fontName->currentFont().family());
  settings->setValue ("terminal/supressWarnings", ui->supressWarnings->isChecked ());
  settings->setValue ("terminal/matlabCompatible", ui->matlabCompatible->isChecked ());
  settings->setValue ("terminal/broadcasting", ui->broadcastingOption->currentIndex ());
  settings->setValue ("showFilenames", ui->showFilenames->isChecked ());
  settings->setValue ("showFileSize", ui->showFileSize->isChecked ());
  settings->setValue ("showFileType", ui->showFileType->isChecked ());
  settings->setValue ("showLastModified", ui->showLastModified->isChecked ());
  //settings->setValue ("showHiddenFiles", ui->showHiddenFiles->isChecked ());
  settings->setValue ("useAlternatingRowColors", ui->useAlternatingRowColors->isChecked ());
  //settings->setValue ("saveBookmark", ui->saveBookmark->isChecked());
  //settings->setValue ("saveBreakpoint", ui->saveBreakpoint->isChecked());
  settings->setValue ("filebrowser/fontName", ui->file_fontName->currentFont().family());
  settings->setValue ("filebrowser/fontSize", ui->file_fontSize->value ());
  settings->setValue ("filebrowser/defaultFont", ui->file_defaultFont->isChecked());
  settings->setValue ("workspace/fontName", ui->workspace_fontName->currentFont().family());
  settings->setValue ("workspace/fontSize", ui->workspace_fontSize->value ());
  settings->setValue ("workspace/defaultFont", ui->workspace_defaultFont->isChecked());
  settings->setValue ("history/fontName", ui->history_fontName->currentFont().family ());
  settings->setValue ("history/fontSize", ui->history_fontSize->value ());
  settings->setValue ("history/defaultFont", ui->history_defaultFont->isChecked());
  settings->setValue ("history/numCommands", ui->history_numberCommands->value ());

  settings->setValue ("graphics", ui->toolkit_cb->currentText ());

  settings->setValue ("language", ui->languageComboBox->currentIndex());

  /*
  settings->setValue ("useProxyServer", ui->useProxyServer->isChecked ());
  settings->setValue ("proxyType", ui->proxyType->currentText ());
  settings->setValue ("proxyHostName", ui->proxyHostName->text ());
  settings->setValue ("proxyPort", ui->proxyPort->text ());
  settings->setValue ("proxyUserName", ui->proxyUserName->text ());
  settings->setValue ("proxyPassword", ui->proxyPassword->text ());
  */

  //settings->setValue ("language", ui->toolkit_cb->la);

  QDialog::accept();
}

void
settings_dialog::read_settings()
{
  QSettings *settings = resource_manager::instance ()->get_settings ();
  //ui->useCustomFileEditor->setChecked (settings->value ("useCustomFileEditor").toBool ());
  //ui->customFileEditor->setText (settings->value ("customFileEditor").toString ());
  ui->editor_showLineNumbers->setChecked (settings->value ("editor/showLineNumbers",true).toBool () );
  ui->editor_highlightCurrentLine->setChecked (settings->value ("editor/highlightCurrentLine",true).toBool () );
  ui->editor_codeCompletion->setChecked (settings->value ("editor/codeCompletion",true).toBool () );
  ui->editor_fontName->setCurrentFont (QFont (settings->value ("editor/fontName","Courier").toString()) );
  ui->editor_fontSize->setValue (settings->value ("editor/fontSize",10).toInt ());
  ui->editor_longWindowTitle->setChecked (settings->value ("editor/longWindowTitle",false).toBool ());
  ui->autosaveFiles->setChecked (settings->value ("editor/autosave", true).toBool ());
  ui->autosavePeriod->setValue (settings->value ("editor/autosavePeriod", 2).toInt ());

  ui->terminal_fontName->setCurrentFont (QFont (settings->value ("terminal/fontName","Lucida Console").toString()) );
  ui->terminal_fontSize->setValue (settings->value ("terminal/fontSize",10).toInt ());
  ui->supressWarnings->setChecked (settings->value ("terminal/supressWarnings", true).toBool ());
  ui->matlabCompatible->setChecked (settings->value ("terminal/matlabCompatible", false).toBool ());
  ui->broadcastingOption->setCurrentIndex (settings->value ("terminal/broadcasting", 2).toInt());
  ui->showFilenames->setChecked (settings->value ("showFilenames", true).toBool());
  ui->showFileSize->setChecked (settings->value ("showFileSize", true).toBool());
  ui->showFileType->setChecked (settings->value ("showFileType", false).toBool());
  ui->showLastModified->setChecked (settings->value ("showLastModified", false).toBool());
  //ui->showHiddenFiles->setChecked (settings->value ("showHiddenFiles", false).toBool());
  ui->useAlternatingRowColors->setChecked (settings->value ("useAlternatingRowColors", true).toBool());
  //ui->saveBookmark->setChecked (settings->value ("saveBookmark",true).toBool ());
  //ui->saveBreakpoint->setChecked (settings->value ("saveBreakpoint",true).toBool ());
  ui->file_fontName->setCurrentFont (QFont (settings->value("filebrowser/fontName",qApp->font().family()).toString ()));
  ui->file_fontSize->setValue (settings->value ("filebrowser/fontSize",qApp->font().pointSize()).toInt());
  ui->file_defaultFont->setChecked (settings->value ("filebrowser/defaultFont",true).toBool());
  ui->workspace_fontName->setCurrentFont (QFont (settings->value("workspace/fontName",qApp->font().family()).toString ()));
  ui->workspace_fontSize->setValue (settings->value ("workspace/fontSize",qApp->font().pointSize()).toInt());
  ui->workspace_defaultFont->setChecked (settings->value ("workspace/defaultFont", true).toBool());
  ui->history_fontName->setCurrentFont (QFont (settings->value("history/fontName",qApp->font().family()).toString ()));
  ui->history_fontSize->setValue (settings->value ("history/fontSize",qApp->font().pointSize()).toInt());
  ui->history_defaultFont->setChecked (settings->value ("history/defaultFont", true).toBool());
  ui->history_numberCommands->setValue (settings->value ("history/numCommands", 128).toInt());

  ui->toolkit_cb->setCurrentIndex(_graphics_toolkits.indexOf(settings->value ("graphics","gnuplot").toString()));

  ui->languageComboBox->setCurrentIndex(settings->value ("language",0).toInt());


  //ui->useProxyServer->setChecked (settings->value ("useProxyServer").toBool ());
  //ui->proxyHostName->setText (settings->value ("proxyHostName").toString ());

  /*
  int currentIndex = 0;
  QString proxyTypeString = settings->value ("proxyType").toString ();
  while ( (currentIndex < ui->proxyType->count ()) && (ui->proxyType->currentText () != proxyTypeString))
    {
      currentIndex++;
      ui->proxyType->setCurrentIndex (currentIndex);
    }

  ui->proxyPort->setText (settings->value ("proxyPort").toString ());
  ui->proxyUserName->setText (settings->value ("proxyUserName").toString ());
  ui->proxyPassword->setText (settings->value ("proxyPassword").toString ());
  */
}

void
settings_dialog::populate_combobox(QStringList options, QString current)
{
  _graphics_toolkits = options;
  QSettings *settings = resource_manager::instance ()->get_settings ();
  settings->setValue ("graphics", current);
  ui->toolkit_cb->clear();
  ui->toolkit_cb->addItems (options);
  ui->toolkit_cb->setCurrentIndex(options.indexOf(current));
}


