#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

// Incluimos la cabecera del componente Ui generado por el comando uic
// Es importante porque contiene la información de la clase utilizada
#include "ui_MainWindow.h"
#include <QMainWindow>

// Forward declaration, se usa solo para declarar los tipos de datos
// agiliza el compilador
// Solo se puede aplicar en apuntadores y tipos referenciados
class QLabel;

// Aqui es importante declararlo como miembro privado,
// los metodos son publicos dentro de la clase
class MainWindow : public QMainWindow,
				   private Ui::MainWindow
{
	Q_OBJECT
	
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	
protected:
	void setupActions();
    bool mayDiscardDocument();
    void saveFile(const QString&);

protected slots:
	void newFile();
	void loadFile();
	void saveFile();
	void saveFileAs();
	void undo();
	void redo();
	void copy();
	void about();
	void updateStats();

private:
	// Esta variable especifica la ruta del archivo actual.
	// Si el documento no ha sido salvado hasta ahora, la cadena esta vacia.
	QString mFilePath;
	QLabel *mStatLabel;
};

#endif /*MAINWINDOW_H_*/
