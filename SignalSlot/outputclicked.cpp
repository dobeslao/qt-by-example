#include <QApplication>
#include <QPushButton>

int main (int argc, char **argv)
{
	QApplication app(argc, argv);
	
	QPushButton pushme("Salir");
	
	pushme.resize(200,40);
	pushme.setFont(QFont("Arial", 20, QFont::Bold));
	pushme.show();
	
	// Conecta el mensaje clicked del objeto pushme con quit del objeto app.
	QObject::connect(&pushme, SIGNAL(clicked()), &app, SLOT(quit()));
	
	return app.exec(); 
}
