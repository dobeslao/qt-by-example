#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>

int main (int argc, char **argv)
{
	QApplication app(argc, argv);
	QWidget window;
	
	QVBoxLayout *mylayout = new QVBoxLayout(&window);
	QLabel *etiqueta1 = new QLabel("Primera");
	QLabel *etiqueta2 = new QLabel("Segunda");
	
	mylayout->addWidget(etiqueta1);
	mylayout->addWidget(etiqueta2);
	
	window.show();
	
	return app.exec(); 
}
