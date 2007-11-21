#include <QApplication>
#include <QPushButton>

int main (int argc, char **argv)
{
	QApplication app(argc, argv);
	
	QPushButton pushme("Hola Mundo");
	pushme.resize(200,40);
	
	pushme.setFont(QFont("Arial", 20, QFont::Bold));
	
	QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));
	
	pushme.show();
	
	return app.exec(); 
}
