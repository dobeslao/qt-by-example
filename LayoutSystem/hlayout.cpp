#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>

int main (int argc, char **argv)
{
	QApplication app(argc, argv);
	QWidget window;
	
	QHBoxLayout *mylayout = new QHBoxLayout(&window);
	QLabel *etiqueta1 = new QLabel("Cero");
	QLabel *etiqueta2 = new QLabel("Uno");
	
	mylayout->addWidget(etiqueta1);
	mylayout->addWidget(etiqueta2);
	
	window.show();
	
	return app.exec(); 
}
