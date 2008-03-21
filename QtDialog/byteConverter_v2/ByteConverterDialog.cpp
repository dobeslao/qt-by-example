// ByteConverterDialog.cpp

#include "ByteConverterDialog.h"
#include "ByteConverter.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QIntValidator>
#include <QRegExpValidator>

ByteConverterDialog::ByteConverterDialog()
{
	// Generate the necesary layouts
	QVBoxLayout *mainlayout = new QVBoxLayout(this);
	QGridLayout *editlayout = new QGridLayout;
	QHBoxLayout *buttonlayout = new QHBoxLayout;
	
	mainlayout->addLayout(editlayout);
	mainlayout->addStretch(); //This add a white space fill
	mainlayout->addLayout(buttonlayout);
	//-- You must do it before add any widget
	
	// Generate the labels and line-edits
	// add it to the editlayout
	QLabel *decLabel = new QLabel(tr("Decimal"));
	QLabel *hexLabel = new QLabel(tr("Hexadecimal"));
	QLabel *binLabel = new QLabel(tr("Binario"));
	
	QLineEdit *decEdit = new QLineEdit;
	QLineEdit *hexEdit = new QLineEdit;
	QLineEdit *binEdit = new QLineEdit;
	
	editlayout->addWidget(decLabel, 0, 0);
	editlayout->addWidget(decEdit, 0, 1);
	editlayout->addWidget(hexLabel, 1, 0);
	editlayout->addWidget(hexEdit, 1, 1);
	editlayout->addWidget(binLabel, 2, 0);
	editlayout->addWidget(binEdit, 2, 1);
	
	// Add the quit button, and add it to the layout
	QPushButton *exitbutton = new QPushButton(tr("Salir"));
	
	buttonlayout->addStretch();
	buttonlayout->addWidget(exitbutton);
	
	exitbutton->setDefault(true);
	
	//Limit input values to correct values 0-255
	QIntValidator *decvalidator = new QIntValidator(0, 255, decEdit);
	decEdit->setValidator(decvalidator);
	
	QRegExpValidator *hexvalidator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,2}"), hexEdit);
	hexEdit->setValidator(hexvalidator);
	
	QRegExpValidator *binvalidator = new QRegExpValidator(QRegExp("[0-1]{1,8}"), binEdit);
	binEdit->setValidator(binvalidator);
	
	setWindowTitle("Byte Converter v2");
	
	connect(exitbutton, SIGNAL(clicked()), this, SLOT(accept()));
	
	ByteConverter *bc = new ByteConverter(this);
	connect(decEdit, SIGNAL(textChanged(const QString&)), bc, SLOT(setDec(const QString&)));
	connect(hexEdit, SIGNAL(textChanged(const QString&)), bc, SLOT(setHex(const QString&)));
	connect(binEdit, SIGNAL(textChanged(const QString&)), bc, SLOT(setBin(const QString&)));
	
	connect(bc, SIGNAL(decChanged(const QString&)), decEdit, SLOT(setText(const QString&)));
	connect(bc, SIGNAL(hexChanged(const QString&)), hexEdit, SLOT(setText(const QString&)));
	connect(bc, SIGNAL(binChanged(const QString&)), binEdit, SLOT(setText(const QString&)));

}
