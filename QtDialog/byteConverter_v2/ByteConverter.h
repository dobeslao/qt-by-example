#ifndef BYTECONVERTER_H_
#define BYTECONVERTER_H_

#include <QObject>

class ByteConverter : public QObject
{
	Q_OBJECT
	
public:
	ByteConverter(QObject* = 0);
	
// Declaramos los slots
public slots:
	void setDec(const QString&);
	void setHex(const QString&);
	void setBin(const QString&);
	
// Estas son las señales que se pueden emitir
signals:
	void decChanged(const QString&);
	void hexChanged(const QString&);
	void binChanged(const QString&);
};

#endif /*BYTECONVERTER_H_*/
