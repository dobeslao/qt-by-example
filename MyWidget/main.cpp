// Incluimos la aplicacion principal
#include <QApplication>

// Incluimos la cabecera de nuestra clase
#include "mywidget.h"

int main (int argc, char **argv)
{
	// Inicializa el sistema de ventanas
	QApplication app(argc, argv);
	
	/* Creamos un nuevo objeto de nuestra clase
	 * Lo colocamos como widget principal
	 * Se mantiene durante la ejecucion de la aplicacion
	 */
	MyWidget *content = new MyWidget;
	app.setActiveWindow(content);

	return app.exec();
}
