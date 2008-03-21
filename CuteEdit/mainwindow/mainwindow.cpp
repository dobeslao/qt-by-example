#include <QApplication>
#include <QMainWindow>
#include <QLabel>

int main (int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	QMainWindow mainWindow;
	QLabel *label = new QLabel("<center>Central Label</center>");
	mainWindow.setCentralWidget(label);
	mainWindow.show();
	
	return app.exec();
}
