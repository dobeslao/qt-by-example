#include <QIntValidator>
#include <QRegExpValidator>
#include "ByteConverterDialog.h"
#include "ByteConverter.h"

ByteConverterDialog::ByteConverterDialog(QWidget *parent)
 : QDialog(parent)
{
	setupUi(this);

	//Limit input values to correct values 0-255
	QIntValidator *decvalidator = new QIntValidator(0, 255, decEdit);
	decEdit->setValidator(decvalidator);
	
	// Limit input hex values
	QRegExpValidator *hexvalidator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,2}"), hexEdit);
	hexEdit->setValidator(hexvalidator);
	
	// Limit input bin values
	QRegExpValidator *binvalidator = new QRegExpValidator(QRegExp("[0-1]{1,8}"), binEdit);
	binEdit->setValidator(binvalidator);
  
	// Make all the connection stuff
	ByteConverter *bc = new ByteConverter(this);
	connect(decEdit, SIGNAL(textChanged(const QString&)), bc, SLOT(setDec(const QString&)));
	connect(hexEdit, SIGNAL(textChanged(const QString&)), bc, SLOT(setHex(const QString&)));
	connect(binEdit, SIGNAL(textChanged(const QString&)), bc, SLOT(setBin(const QString&)));
		
	connect(bc, SIGNAL(decChanged(const QString&)), decEdit, SLOT(setText(const QString&)));
	connect(bc, SIGNAL(hexChanged(const QString&)), hexEdit, SLOT(setText(const QString&)));
	connect(bc, SIGNAL(binChanged(const QString&)), binEdit, SLOT(setText(const QString&)));
}
