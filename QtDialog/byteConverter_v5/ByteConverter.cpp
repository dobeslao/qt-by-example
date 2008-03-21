#include "ByteConverter.h"

ByteConverter::ByteConverter(QObject* parent) :
	QObject(parent) {}

/* En general los slot reciben un parametro y operan
 * con el, despues emiten una señal con el valor
 * correspondiente actualizado.
 */

void ByteConverter::setDec(const QString& newValue)
{
	bool ok;
	int num = newValue.toInt(&ok);
	
	if(ok){
		emit hexChanged(QString::number(num,16));
		emit binChanged(QString::number(num,2));
	} else {
		emit hexChanged("");
		emit binChanged("");
	}
}

void ByteConverter::setHex(const QString& newValue)
{
	bool ok;
	int num = newValue.toInt(&ok, 16);
	
	if(ok){
		emit decChanged(QString::number(num));
		emit binChanged(QString::number(num,2));
	} else {
		emit decChanged("");
		emit binChanged("");
	}
}

void ByteConverter::setBin(const QString& newValue)
{
	bool ok;
	int num = newValue.toInt(&ok, 2);
	
	if(ok){
		emit decChanged(QString::number(num));
		emit hexChanged(QString::number(num,16));
	} else {
		emit decChanged("");
		emit hexChanged("");
	}
}
