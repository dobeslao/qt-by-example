// Proporciona un Widget LCD y una barra dezplasable
#include <QLCDNumber>
#include <QSlider>

// Incluimos la cabecera de esta clase
#include "mywidget.h"

// Ahora definimos el comportamiento del constructor
// Requiere el padre y nombre
/* Primero se llama al constructor de QVBoxLayout para proporcionarle
 * el parent y name hasta llegar al QObject
 */
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
	// Se crean nuevos objetos LCDNumber y Slider
	QLCDNumber *lcd = new QLCDNumber( this );
	QSlider *slider = new QSlider(Qt::Horizontal, this);
	
	// Emisor, Señal, Receptor, Accion
	// Se conecta la señal valueChanged del Slider al slot display del LCDNumber
	connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
	
	// Creamos un marco vertical
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(lcd);
	layout->addWidget(slider);
	
	setLayout(layout);
	show();
}
