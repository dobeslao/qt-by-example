#include <QtGui>
#include "ByteConverterDialog.h"

int main (int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	ByteConverterDialog bc;
	
	bc.setAttribute(Qt::WA_QuitOnClose);
	bc.show();
	
	return app.exec();
}
