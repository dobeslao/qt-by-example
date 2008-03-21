#include <QtGui>
#include "ByteConverterDialog.h"

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

  // Usando autoconnect, no se requieren proporcionarlos explisitamente, ve la cabecera
  //connect(decEdit, SIGNAL(textChanged(const QString&)), this, SLOT(decChanged(const QString&)));
  //connect(hexEdit, SIGNAL(textChanged(const QString&)), this, SLOT(hexChanged(const QString&)));
  //connect(binEdit, SIGNAL(textChanged(const QString&)), this, SLOT(binChanged(const QString&)));
}

void ByteConverterDialog::on_decChanged_textChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok);
    if (ok) {
        hexEdit->setText(QString::number(num, 16));
        binEdit->setText(QString::number(num, 2));
    } else {
        hexEdit->setText("");
        binEdit->setText("");
    }
}

void ByteConverterDialog::on_hexChanged_textChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok, 16);
    if (ok) {
        decEdit->setText(QString::number(num));
        binEdit->setText(QString::number(num, 2));
    } else {
        decEdit->setText("");
        binEdit->setText("");
    }
}

void ByteConverterDialog::on_binChanged_textChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok, 2);
    if (ok) {
        decEdit->setText(QString::number(num));
        hexEdit->setText(QString::number(num, 16));
    } else {
    }
}
