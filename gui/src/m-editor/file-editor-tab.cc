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

#include "file-editor-tab.h"
#include "file-editor.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include "octave-link.h"
#include "QsciOctUPM/qscistyle.h"

int file_editor_tab::_num_files_created = 0;

file_editor_tab::file_editor_tab(file_editor *fileEditor)
  : QWidget ((QWidget*)fileEditor)
{

  QSettings *settings = resource_manager::instance ()->get_settings ();
  _file_editor = fileEditor;
  _file_name = "";
  _edit_area = new QsciScintilla (this);
  _edit_area->setLexer (fileEditor->lexer ());

  // markers
  _edit_area->setMarginType (1, QsciScintilla::SymbolMargin);
  _edit_area->setMarginSensitivity (1, true);
  _edit_area->markerDefine (QsciScintilla::RightTriangle, bookmark);
  _edit_area->markerDefine (QPixmap (":/actions/icons/redled.png"), breakpoint);
  _edit_area->markerDefine (QPixmap (":/actions/icons/arrow_right.png"), debugger_position);

  connect (_edit_area, SIGNAL (marginClicked (int, int, Qt::KeyboardModifiers)),
           this, SLOT (handle_margin_clicked (int, int, Qt::KeyboardModifiers)));

  // line numbers
  _edit_area->setMarginsForegroundColor(QColor(96,96,96));
  _edit_area->setMarginsBackgroundColor(QColor(232,232,220));
  if (settings->value ("editor/showLineNumbers",true).toBool ())
    {
      QFont marginFont( settings->value ("editor/fontName","Consolas").toString () ,
                        settings->value ("editor/fontSize",10).toInt () );
      _edit_area->setMarginsFont( marginFont );
      QFontMetrics metrics(marginFont);
      _edit_area->setMarginType (2, QsciScintilla::TextMargin);
      _edit_area->setMarginWidth(2, metrics.width("999"));
      _edit_area->setMarginLineNumbers(2, true);
    }

  // code folding
  _edit_area->setMarginType (3, QsciScintilla::SymbolMargin);
  _edit_area->setFolding (QsciScintilla::BoxedTreeFoldStyle , 3);

  // other features
  if (settings->value ("editor/highlightCurrentLine",true).toBool ())
    {
      _edit_area->setCaretLineVisible(true);
      _edit_area->setCaretLineBackgroundColor(QColor(245,245,245));
    }
  _edit_area->setBraceMatching (QsciScintilla::StrictBraceMatch);
  _edit_area->setAutoIndent (true);
  _edit_area->setIndentationWidth (2);
  _edit_area->setIndentationsUseTabs (false);
  if (settings->value ("editor/codeCompletion",true).toBool ())
    {
      _edit_area->autoCompleteFromAll ();
      _edit_area->setAutoCompletionSource(QsciScintilla::AcsAll);
      _edit_area->setAutoCompletionThreshold (1);
    }
  _edit_area->setUtf8 (true);

  _edit_area->setAutoIndent (true);

  _edit_area->setIndentationGuides (true);
  //_edit_area->setWhitespaceVisibility (QsciScintilla::WsVisibleAfterIndent);

  _long_title = settings->value ("editor/longWindowTitle", false).toBool();

  QVBoxLayout *layout = new QVBoxLayout ();
  layout->addWidget (_edit_area);
  layout->setMargin (0);
  setLayout (layout);

  // connect modified signal
  connect (_edit_area, SIGNAL (modificationChanged (bool)),
           this, SLOT (new_title (bool)));
  connect (_edit_area, SIGNAL (copyAvailable (bool)),
           this, SLOT (handle_copy_available (bool)));
  //connect (&_file_system_watcher, SIGNAL (fileChanged (QString)),
  //         this, SLOT (file_has_changed (QString)));

  _file_name = "";
  new_title (false);

  connect (&_autosave_timer, SIGNAL (timeout()), this, SLOT (save_backup()));

  //_autosave_timer.setSingleShot (true);
  //_autosave_timer.setInterval (1000);
  //_autosave_timer.start ();

  notice_settings ();
}

void
file_editor_tab::notice_settings()
{
  QSettings *settings = resource_manager::instance ()->get_settings();

  QFont mainFont( settings->value ("editor/fontName","Consolas").toString () ,
                        settings->value ("editor/fontSize",10).toInt () );
  _edit_area->setFont (mainFont);
  _edit_area->setLexer (_file_editor->lexer ());
  _edit_area->lexer()->setFont(mainFont);
  mainFont.setBold(true);
  _edit_area->lexer()->setFont(mainFont,QsciLexerMatlab::Keyword);
  mainFont.setBold(false);
  mainFont.setItalic(true);
  _edit_area->lexer()->setFont(mainFont,QsciLexerMatlab::Comment);
  _edit_area->lexer()->setFont(mainFont,QsciLexerMatlab::OctaveComment);
  //_edit_area->lexer()->setFont(mainFont,4);
  //_edit_area->lexer()->setFont(mainFont,2);


  //_edit_area->setBraceMatching(QsciScintilla::NoBraceMatch);
  _edit_area->setUnmatchedBraceForegroundColor(QColor(255,0,0));
  _edit_area->setMatchedBraceForegroundColor(QColor(0,0,255));
  _edit_area->setMatchedBraceBackgroundColor(QColor(169,226,243));
  _edit_area->setUnmatchedBraceBackgroundColor(QColor(245,245,169));


  if (settings->value ("editor/showLineNumbers",true).toBool ())
    {
      QFont marginFont( settings->value ("editor/fontName","Consolas").toString () ,
                        settings->value ("editor/fontSize",10).toInt () );
      _edit_area->setMarginsFont( marginFont );
      QFontMetrics metrics(marginFont);
      _edit_area->setMarginType (2, QsciScintilla::TextMargin);
      _edit_area->setMarginWidth(2, metrics.width("99999"));
      _edit_area->setMarginLineNumbers(2, true);
    }
    else
    {
      _edit_area->setMarginWidth(2, 0);
      _edit_area->setMarginLineNumbers(2, false);
    }

   if (settings->value ("editor/highlightCurrentLine",true).toBool ())
    {
      _edit_area->setCaretLineVisible(true);
      _edit_area->setCaretLineBackgroundColor(QColor(245,245,245));
    }
  else
    {
      _edit_area->setCaretLineVisible (false);
    }

  if (settings->value ("editor/codeCompletion",true).toBool ())
    {
      _edit_area->autoCompleteFromAll ();
      _edit_area->setAutoCompletionSource(QsciScintilla::AcsAll);
      _edit_area->setAutoCompletionThreshold (1);

    }
  else
  {
    _edit_area->setAutoCompletionSource(QsciScintilla::AcsNone);
    _edit_area->setAutoCompletionThreshold(-1);
  }

  _long_title = settings->value ("editor/longWindowTitle", false).toBool();

  new_title (true);
  set_modified (is_modified ());


  bool autosave = true;
  if (settings->contains ("editor/autosave"))
    autosave = settings->value ("editor/autosave").toBool ();

  int autosavePeriod = 2;
  if (settings->contains ("editor/autosavePeriod"))
    autosavePeriod = settings->value ("editor/autosavePeriod").toInt ();

  set_autosave (autosave, autosavePeriod);
}

bool
file_editor_tab::copy_available ()
{
  return _copy_available;
}

void
file_editor_tab::event_accepted (octave_event *e)
{
  if (octave_add_breakpoint_event *abe
      = dynamic_cast<octave_add_breakpoint_event*> (e))
    {
      // TODO: Check file.
      _edit_area->markerAdd (abe->get_line (), breakpoint);
    }

  if (octave_remove_breakpoint_event *rbe
      = dynamic_cast<octave_remove_breakpoint_event*> (e))
    {
      // TODO: Check file.
      _edit_area->markerDelete (rbe->get_line (), breakpoint);
    }

  if (octave_remove_all_breakpoints_event *rabe
      = dynamic_cast<octave_remove_all_breakpoints_event*> (e))
    {
      Q_UNUSED (rabe);
      _edit_area->markerDeleteAll (breakpoint);
    }

  delete e;
}

void
file_editor_tab::event_reject (octave_event *e)
{
  delete e;
}


void
file_editor_tab::closeEvent (QCloseEvent *event)
{
  if (_file_editor->mainWindow ()->is_closing ())
    {
      // close whole application: save file or not if modified
      event->accept ();
    }
  else
    {
      // ignore close event if file is not saved and user cancels closing this window
      if (is_modified() && !attempt_save ())
          event->ignore ();
      else
          event->accept();
    }
}

void
file_editor_tab::set_file_name (QString fileName)
{
  _file_name = fileName;
  _backup_filename = fileName + ".bak";
}

void
file_editor_tab::handle_margin_clicked(int margin, int line, Qt::KeyboardModifiers state)
{
    Q_UNUSED (state);
  if (margin == 1)
    {
      unsigned int mask = _edit_area->markersAtLine (line);

      if (state & Qt::ControlModifier)
        {
          if (mask && (1 << bookmark))
            _edit_area->markerDelete(line,bookmark);
          else
            _edit_area->markerAdd(line,bookmark);
        }
      else
        {
          if (mask && (1 << breakpoint))
            {
              request_remove_breakpoint (line);
            }
          else
            {
              request_add_breakpoint (line);
            }
        }
    }
}

void
file_editor_tab::request_add_breakpoint (int line)
{
  QFileInfo file_info (_file_name);
  QString path = file_info.absolutePath ();
  QString function_name = file_info.fileName ();

  // We have to cut off the suffix, because octave appends it.
  function_name.chop (file_info.suffix ().length () + 1);

  octave_link::instance ()->post_event
      (new octave_add_breakpoint_event (*this,
                                        path.toStdString (),
                                        function_name.toStdString (),
                                        line));
}

void
file_editor_tab::request_remove_breakpoint (int line)
{
  QFileInfo file_info (_file_name);
  QString path = file_info.absolutePath ();
  QString function_name = file_info.fileName ();

  // We have to cut off the suffix, because octave appends it.
  function_name.chop (file_info.suffix ().length () + 1);

  octave_link::instance ()->post_event
      (new octave_remove_breakpoint_event (*this,
                                           path.toStdString (),
                                           function_name.toStdString (),
                                           line));
}


void
file_editor_tab::comment_selected_text ()
{
  do_comment_selected_text (true);
}

void
file_editor_tab::uncomment_selected_text ()
{
  do_comment_selected_text (false);
}

void
file_editor_tab::do_comment_selected_text (bool comment)
{
  if ( _edit_area->hasSelectedText() )
    {
      int lineFrom, lineTo, colFrom, colTo, i;
      _edit_area->getSelection (&lineFrom,&colFrom,&lineTo,&colTo);
      if ( colTo == 0 )  // the beginning of last line is not selected
        lineTo--;        // stop at line above
      _edit_area->beginUndoAction ();
      for ( i=lineFrom; i<=lineTo; i++ )
        {
          if ( comment )
            _edit_area->insertAt("%",i,0);
          else
            {
              QString line(_edit_area->text(i));
              if ( line.startsWith("%") )
                {
                  _edit_area->setSelection(i,0,i,1);
                  _edit_area->removeSelectedText();
                }
            }
        }
      _edit_area->endUndoAction ();
    }
}

void
file_editor_tab::new_title(bool modified)
{
  QString title(_file_name);
  if ( !_long_title )
    {
      QFileInfo file(_file_name);
      title = file.fileName();
    }

  if ( modified )
    {
      emit file_name_changed (title.prepend("* "));
    }
  else
    emit file_name_changed (title);

  emit editor_state_changed ();
}

void
file_editor_tab::handle_copy_available(bool enableCopy)
{
  _copy_available = enableCopy;
  emit editor_state_changed ();
}

bool
file_editor_tab::check_file_modified (QString msg)
{
  int answer = false;
  if (_edit_area->isModified ())
    {
      // file is modified but not saved, aks user what to do
      int decision = QMessageBox::warning (this,
                                       msg,
                                       tr ("The file %1\n"
                                           "has been modified. Do you want to save the changes?").
                                       arg (_file_name),
                                       QMessageBox::Save, QMessageBox::Discard, QMessageBox::Cancel );
      if (decision == QMessageBox::Save)
      {
          save_file ();
	  answer = true;
	  if (is_modified())
	    answer = false;
     }

     if (decision == QMessageBox::Discard)
     {
       answer = true;
       remove_backup_file ();
     }
    }
  return answer;
}

void
file_editor_tab::remove_bookmark ()
{
  _edit_area->markerDeleteAll(bookmark);
}

void
file_editor_tab::toggle_bookmark ()
{
  int line,cur;
  _edit_area->getCursorPosition(&line,&cur);
  if ( _edit_area->markersAtLine (line) && (1 << bookmark) )
    _edit_area->markerDelete(line,bookmark);
  else
    _edit_area->markerAdd(line,bookmark);
}

void
file_editor_tab::next_bookmark ()
{
  int line,cur,nextline;
  _edit_area->getCursorPosition(&line,&cur);
  if ( _edit_area->markersAtLine(line) && (1 << bookmark) )
    line++; // we have a bookmark here, so start search from next line
  nextline = _edit_area->markerFindNext(line,(1 << bookmark));
  _edit_area->setCursorPosition(nextline,0);
}

void
file_editor_tab::previous_bookmark ()
{
  int line,cur,prevline;
  _edit_area->getCursorPosition(&line,&cur);
  if ( _edit_area->markersAtLine(line) && (1 << bookmark) )
    line--; // we have a bookmark here, so start search from prev line
  prevline = _edit_area->markerFindPrevious(line,(1 << bookmark));
  _edit_area->setCursorPosition(prevline,0);
}

void
file_editor_tab::remove_all_breakpoints ()
{
  QFileInfo file_info (_file_name);
  QString path = file_info.absolutePath ();
  QString function_name = file_info.fileName ();

  // We have to cut off the suffix, because octave appends it.
  function_name.chop (file_info.suffix ().length () + 1);

  octave_link::instance ()->post_event
      (new octave_remove_all_breakpoints_event (*this,
                                                path.toStdString (),
                                                function_name.toStdString ()));
}

void
file_editor_tab::toggle_breakpoint ()
{
  int line, cur;
  _edit_area->getCursorPosition (&line, &cur);
  if ( _edit_area->markersAtLine (line) && (1 << breakpoint) )
    request_remove_breakpoint (line);
  else
    request_add_breakpoint (line);
}

void
file_editor_tab::next_breakpoint ()
{
  int line, cur, nextline;
  _edit_area->getCursorPosition (&line, &cur);
  if ( _edit_area->markersAtLine (line) && (1 << breakpoint) )
    line++; // we have a breakpoint here, so start search from next line
  nextline = _edit_area->markerFindNext (line, (1 << breakpoint));
  _edit_area->setCursorPosition (nextline, 0);
}

void
file_editor_tab::previous_breakpoint ()
{
  int line, cur, prevline;
  _edit_area->getCursorPosition (&line, &cur);
  if ( _edit_area->markersAtLine (line) && (1 << breakpoint) )
    line--; // we have a breakpoint here, so start search from prev line
  prevline = _edit_area->markerFindPrevious (line, (1 << breakpoint));
  _edit_area->setCursorPosition (prevline, 0);
}


void
file_editor_tab::cut ()
{
  _edit_area->cut ();
}

void
file_editor_tab::copy ()
{
  _edit_area->copy ();
}

void
file_editor_tab::paste ()
{
  _edit_area->paste ();
}

void
file_editor_tab::find()
{
  find_dialog dialog (_edit_area);
  dialog.exec ();
}


void
file_editor_tab::undo ()
{
  _edit_area->undo ();
}

void
file_editor_tab::redo ()
{
  _edit_area->redo ();
}


void
file_editor_tab::set_debugger_position (int line)
{
  _edit_area->markerDeleteAll (debugger_position);

  if (line > 0)
    {
      _edit_area->markerAdd (line-1, debugger_position);
      _edit_area->ensureLineVisible (line - 1);
    }

  _file_editor->release_lock ();
}



void
file_editor_tab::set_modified (bool modified)
{
  _edit_area->setModified (modified);
}

void
file_editor_tab::load_file (QString fileName)
{

 check_backup_file(fileName);

  QFile file (fileName);
  if (!file.exists() || !file.open (QFile::ReadOnly))
    {
      QMessageBox::warning (this, tr ("Octave Editor"),
                            tr ("Could not open file %1 for read:\n%2.").arg (fileName).
                            arg (file.errorString ()));
      close();
      return;
    }

  if (!_file_editor->isVisible ())
    {
      _file_editor->show ();
    }

  QTextStream in (&file);
  QApplication::setOverrideCursor (Qt::WaitCursor);
  _edit_area->setText (in.readAll ());
  QApplication::restoreOverrideCursor ();

  set_file_name (fileName);

  new_title (false); // window title (no modification)
  _is_unnamed = false;
  set_modified (false); // loaded file is not modified yet
  if (_autosave)
    _autosave_timer.start ();
}

void
file_editor_tab::check_backup_file(QString fn)
{
  QFile f(fn + ".bak");

  if(!f.exists())
    return;

  QMessageBox msgBox;
  msgBox.setText(tr ("The file %1 has unsaved changes. Do you want to recover them?").arg(fn));
  msgBox.setInformativeText(tr ("Last changes date: %1").arg(QFileInfo(f).lastModified().toString()));
  QPushButton *yes = msgBox.addButton (tr ("Recover"), QMessageBox::AcceptRole);
  msgBox.addButton (tr ("Ignore unsaved changes"), QMessageBox::AcceptRole);
  QPushButton *newfile = msgBox.addButton (tr ("Open changes as new file"), QMessageBox::AcceptRole);
  msgBox.setDefaultButton (newfile);

  msgBox.exec();

  if (msgBox.clickedButton() == yes)
  {
      QFile::remove(fn);
      QFile::copy(fn + ".bak", fn);
      QFile::remove(fn + ".bak");
  }
  else if (msgBox.clickedButton() == newfile)
  {
      QString nfn (fn.split(".m").at(0) + "-recovered.m");
      QFile::copy (fn + ".bak", nfn);
      _file_editor->request_open_file (nfn);
  }
}


void
file_editor_tab::new_file ()
{
  if (!_file_editor->isVisible ())
    {
      _file_editor->show ();
    }

  _num_files_created++;
  QString fn = UNNAMED_FILE + QString::number(_num_files_created) + ".m";
  set_file_name (fn);
  _is_unnamed = true;
  new_title (false); // window title (no modification)
  _edit_area->setText ("");
  _edit_area->setModified (false); // new file is not modified yet
  if (_autosave)
    _autosave_timer.start ();
}

bool file_editor_tab::save_file()
{
  if (!is_modified ())
    return true;

  return save_file (_file_name);
}

bool
file_editor_tab::save_file (QString saveFileName)
{
  // it is a new file with the name "<unnamed>" -> call saveFielAs
  if (_is_unnamed || saveFileName.isEmpty ())
    {
      return save_file_as();
    }

  // open the file for writing
  QFile file (saveFileName);
  if (!file.open (QFile::WriteOnly))
    {
      QMessageBox::warning (this, tr ("Octave Editor"),
                            tr ("Could not open file %1 for write:\n%2.").
                            arg (saveFileName).arg (file.errorString ()));
      return false;
    }

  // save the contents into the file
  QTextStream out (&file);
  QApplication::setOverrideCursor (Qt::WaitCursor);
  out << _edit_area->text ();
  QApplication::restoreOverrideCursor ();
  set_file_name (saveFileName);  // save file name for later use
  new_title (false);      // set the window title to actual file name (not modified)
  set_modified (false); // files is save -> not modified


  remove_backup_file ();
  if(_autosave)
    _autosave_timer.start ();

  return true;
}

bool
file_editor_tab::save_file_as ()
{
  QString saveFileName(_file_name);
  QFileDialog fileDialog(this);
  if (_is_unnamed || saveFileName.isEmpty ())
    {
      saveFileName = _file_editor->get_current_directory ();
      fileDialog.setDirectory (saveFileName);
      fileDialog.selectFile (_file_name);
    }
  else
    {
      fileDialog.selectFile (saveFileName);
    }
  fileDialog.setNameFilter (SAVE_FILE_FILTER);
  fileDialog.setDefaultSuffix ("m");
  fileDialog.setAcceptMode (QFileDialog::AcceptSave);
  fileDialog.setViewMode (QFileDialog::Detail);

  if (fileDialog.exec ())
    {
      saveFileName = fileDialog.selectedFiles ().at (0);
      if (saveFileName.isEmpty ())
        return false;

      _is_unnamed = false;
      return save_file (saveFileName);
    }

  return false;
}

QString
file_editor_tab::run_file ()
{
  if (_edit_area->isModified ())
    save_file(_file_name);

  return _file_name;
}


bool
file_editor_tab::attempt_save()
{
  if (is_modified())
    return check_file_modified ("Save file");
  else
    return save_file ();
}

void
file_editor_tab::save_backup()
{
  if (!_autosave)
    return;

  if (!is_modified())
  {
    remove_backup_file();
    if (_autosave)
      _autosave_timer.start ();
    return;
  }

    // open the file for writing
  QFile file (_backup_filename);
  if (!file.open (QFile::WriteOnly))
  {
    if (_autosave)
      _autosave_timer.start ();
    return;
  }

  // save the contents into the file
  QTextStream out (&file);
  QApplication::setOverrideCursor (Qt::WaitCursor);
  out << _edit_area->text ();
  QApplication::restoreOverrideCursor ();
  file.close ();

  if (_autosave)
    _autosave_timer.start ();
}

void
file_editor_tab::remove_backup_file()
{
  if (QFile(_backup_filename).exists())
    QFile::remove (_backup_filename);
}

void file_editor_tab::set_autosave(bool active, int period)
{
  _autosave = active;

  if (active)
  {
    _autosave_timer.setInterval (period*1000);
    _autosave_timer.setSingleShot (true);
    _autosave_timer.start ();
  }
  else
    _autosave_timer.stop ();

}

