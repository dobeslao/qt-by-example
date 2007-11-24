/**
 ** @mainpage first - This is my first Qt application
 **
 ** This application is my first skeleton.  It is enough to get a running executable
 **  to build my app around.  The comments I'm typing now are compatible with the
 **  doxygen documentation system, and will appear in my apps documentation set.
 **
 ** @author Augusto Dobeslao
 **
 */

#ifndef FIRST_H_
#define FIRST_H_

/**
 ** Define application globals and constants here...
 **
 */
#define ORG_DOMAIN "nibble.org.mx"
#define APP_NAME   "firstQTApp"

/*
** Include any stock Qt files here...
**
*/
#include <QApplication>
#include <QtGui>
#include <QMainWindow>
#include <QDebug>

/*
** Include any application specific headers here.
**
*/
#include <ui_frmMainWindow.h>

/*
** Forward-declare any required classes here.  We do not include the
**  header files for these classes here because it just increases the
**  compile times unnecessarily.  This method is considered more
**  practical - these are typical.
**
*/
class QAction;
class QAction;
class QListWidget;
class QMenu;
class QTextEdit;
 
class QSqlDatabase;
class QSqlRelationalTableModel;
class QSqlRelationalDelegate;

/**
 ** The Main Window is the main user interface screen for the
 **  application.  It is implemented as a MIDI type window.
 **
 */
class firstMainWindow : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT
 
public:
  firstMainWindow();
};

#endif /*FIRST_H_*/
