#include "MainWindow.h"
#include <QLabel>

MainWindow::MainWindow()
{
	setWindowTitle(tr("Cute Editor"));
	resize(600,400);
	
	QLabel *label = new QLabel(tr("Central Widget"));
	setCentralWidget(label);
	label->setAlignment(Qt::AlignCenter);
}
