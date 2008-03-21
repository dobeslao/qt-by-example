#include "MainWindow.h"
#include "TemplateHandler.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>
#include <QDockWidget>
#include <QListView>

// Inicializa los elementos necesarios para la aplicación
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	setupUi(this);
	setupActions();
	
	// Configura la barra de herramienta
	QMenu *toolBarMenu = menuSettings->addMenu(tr("&Toolbars"));
	toolBar->toggleViewAction()->setShortcut(tr("CTRL+T"));
	toolBar->toggleViewAction()->setStatusTip(tr("Show/Hide Main Toolbar"));
	toolBar->toggleViewAction()->setText(tr("&Main Toolbar"));
	toolBarMenu->addAction(toolBar->toggleViewAction());
	
	actionUndo->setEnabled(false);
	actionRepeat->setEnabled(false);
	
	mStatLabel = new QLabel();
	statusBar()->addPermanentWidget(mStatLabel);
	
	connect(textEdit, SIGNAL(textChanged()),
			this, SLOT(updateStats()));
	
	updateStats();
	
	QDockWidget *templateDocker = new QDockWidget;
	templateDocker->setAllowedAreas(Qt::LeftDockWidgetArea|
									Qt::RightDockWidgetArea);
	templateDocker->setObjectName("TemplateDocker");
	templateDocker->setWindowTitle("Templates");
	addDockWidget(Qt::LeftDockWidgetArea,templateDocker);
	
	QListView *view = new QListView();
	templateDocker->setWidget(view);
	
	TemplateHandler *mTemplate = new TemplateHandler(view, textEdit, this);
	
	templateDocker->toggleViewAction()->setShortcut(tr("CTRL+M"));
	templateDocker->toggleViewAction()->setStatusTip(tr("Show/Hide Template Docker"));
	templateDocker->toggleViewAction()->setText(tr("&Template Docker"));
	toolBarMenu->addAction(templateDocker->toggleViewAction());
}

// Destruye los objetos de memoria
// No hay necesidad de hacer algo porque no creamos nada, lo demas es realizado
// por Qt.
MainWindow::~MainWindow()
{
}

// Realiza todas las conexiones necesarias
void MainWindow::setupActions()
{
	connect(actionQuit, SIGNAL(triggered(bool)),
	        qApp, SLOT(quit()));
	
	connect(actionOpen, SIGNAL(triggered(bool)),
	        this, SLOT(loadFile()));
	
	connect(actionSave, SIGNAL(triggered(bool)),
	        this, SLOT(saveFile()));
	
	connect(actionSave_As, SIGNAL(triggered(bool)),
	        this, SLOT(saveFileAs()));
	
	connect(actionNew, SIGNAL(triggered(bool)),
		        this, SLOT(newFile()));
	
	connect(textEdit, SIGNAL(copyAvailable(bool)),
	        actionCopy, SLOT(setEnabled(bool)));
	
	connect(textEdit, SIGNAL(undoAvailable(bool)),
	        actionUndo, SLOT(setEnabled(bool)));
	
	connect(textEdit, SIGNAL(redoAvailable(bool)),
	        actionRepeat, SLOT(setEnabled(bool)));
	
	connect(actionCopy, SIGNAL(triggered(bool)),
	        this, SLOT(copy()));
	
	connect(actionUndo, SIGNAL(triggered(bool)),
	        this, SLOT(undo()));
	
	connect(actionRepeat, SIGNAL(triggered(bool)),
	        this, SLOT(redo()));
	
	connect(actionInfo, SIGNAL(triggered(bool)),
	        this, SLOT(about()));
}

void MainWindow::loadFile()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open file..."));
	QFile file(filename);
	
	// Especificamos que sea solo lectura, la otra bandera permite leer archivos
	// con formato de Windows \r\n
	if(file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		// Por simplicidad se conviene que el archivo esta en UTF8
		textEdit->setPlainText(QString::fromUtf8(file.readAll()));
		mFilePath = filename;
		
		// Mandamos un mensaje a la barra de estado por 3 segundos
		statusBar()->showMessage(tr("File successfully loaded."), 3000);
	}
}

void MainWindow::saveFile()
{
	if(mFilePath.isEmpty())
		saveFileAs();
	else
		saveFile(mFilePath);
}

void MainWindow::saveFile(const QString &filename)
{
	QFile file(filename);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		file.write(textEdit->toPlainText().toUtf8());
		statusBar()->showMessage(tr("File saved successfully."), 3000);
	}
}

void MainWindow::saveFileAs()
{
	mFilePath = QFileDialog::getSaveFileName(this, tr("Save File As..."));
	if(mFilePath.isEmpty())
		return;
	saveFile(mFilePath);
}

bool MainWindow::mayDiscardDocument()
{
	if (textEdit->document()->isModified())
	{
		QString filename = mFilePath;
		if(filename.isEmpty())
			if(	QMessageBox::question(this, tr("Save Document?"),
				tr("You want to create a new document, but the "
				   "changes in the current document '%1' have not "
				   "been saved. How do you want to proceed?"),
				   tr("Save Document"), tr("Discard Changes") ))
				saveFile();
			return true;
	}
	return false;
}

void MainWindow::newFile()
{
	if(!mayDiscardDocument()) return;
	textEdit->setPlainText("");
	mFilePath = "";
}

void MainWindow::undo() {textEdit->document()->undo();}

void MainWindow::redo() {textEdit->document()->redo();}

void MainWindow::copy() {textEdit->copy();}

void MainWindow::about()
{
	QMessageBox::about(this, tr("About CuteEdit..."), 
			tr("CuteEdit v1.0\nA Qt application example.\n"
			   "(c) 2008 Daniel Molketin, Open Source Press"));;
}

void MainWindow::updateStats()
{
	QString text = textEdit->document()->toPlainText();
	int chars = text.length();
	text = text.simplified();
	int words = text.count(" ");
	
	if(!text.isEmpty()) words++;
	QString output = tr("Characters: %1, Words: %2").arg(chars).arg(words);
	mStatLabel->setText(output);
}
