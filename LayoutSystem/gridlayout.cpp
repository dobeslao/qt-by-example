#include <QApplication>
#include <QGridLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget window;
	
	QGridLayout *grid = new QGridLayout(&window);
	
	QLabel *lbl1 = new QLabel("uno");
	QLabel *lbl2 = new QLabel("dos");
	QLabel *lbl3 = new QLabel("tres");
	QLabel *lbl4 = new QLabel("cuatro");
	QLabel *lbl5 = new QLabel("cinco");
	QLabel *lbl6 = new QLabel("seis");
	
	grid->addWidget(lbl1, 0, 0);
	grid->addWidget(lbl2, 0, 1);
	grid->addWidget(lbl3, 1, 0);
	grid->addWidget(lbl4, 1, 1);
	grid->addWidget(lbl5, 2, 0);
	grid->addWidget(lbl6, 2, 1);
	
	window.show();
	
	return app.exec();
}
