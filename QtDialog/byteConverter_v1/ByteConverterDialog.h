#ifndef BYTECONVERTERDIALOG_H_
#define BYTECONVERTERDIALOG_H_

#include <QDialog>
class QLineEdit;

class ByteConverterDialog : public QDialog
{
	Q_OBJECT
	
public:
	ByteConverterDialog(); //Constructor
	
private:
	QLineEdit* decEdit;
	QLineEdit* hexEdit;
	QLineEdit* binEdit;
	
private slots:
	void decChanged(const QString&);
	void hexChanged(const QString&);
	void binChanged(const QString&);
	
}; //Termina la definición de la clase.

#endif /*BYTECONVERTERDIALOG_H_*/
