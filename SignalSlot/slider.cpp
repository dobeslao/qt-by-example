#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>

int main (int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	QWidget window;
	
	QVBoxLayout *mylayout = new QVBoxLayout(&window);
	QLabel   *lnumber  = new QLabel("0");
	QSpinBox *spinbox = new QSpinBox;
	QSlider  *hslider = new QSlider(Qt::Horizontal);
	
	mylayout->addWidget(lnumber);
	mylayout->addWidget(spinbox);
	mylayout->addWidget(hslider);
	
	// spinbox connects
	QObject::connect(spinbox,SIGNAL(valueChanged(int)),lnumber,SLOT(setNum(int)));
	QObject::connect(spinbox,SIGNAL(valueChanged(int)),hslider,SLOT(setValue(int)));
	
	// slider connects
	QObject::connect(hslider,SIGNAL(valueChanged(int)),lnumber,SLOT(setNum(int)));
	QObject::connect(hslider,SIGNAL(valueChanged(int)),spinbox,SLOT(setValue(int)));
	
	window.show();
	
	return app.exec();
}
