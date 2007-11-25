#include <QApplication>
#include <iostream>

class Reciever : public QObject
{
	Q_OBJECT
	
public:
	Reciever( QObject *parent=0 ) : QObject( parent )
	{
	}
	
public slots:
	void get( int x )
	{
		std::cout << "Recieved: " << x << std::endl;
	}
};

class SenderA : public QObject
{
	Q_OBJECT
	
public:
	SenderA( QObject *parent=0, char *name=0 ) : QObject( parent )
	{
		
	}
	
	void doSend()
	{
		emit( send( 7 ) );
	}
	
Q_SIGNALS:
	void send( int );
};

class SenderB : public QObject
{
	Q_OBJECT
	
public:
	SenderB( QObject *parent=0 ) : QObject( parent )
	{
	}
	
	void doStuff()
	{
		emit( transmit( 5 ) );
	}
	
Q_SIGNALS:
	void transmit( int );
};

#include "moc_sisl.cxx"

int main( int argc, char **argv )
{
	QApplication a( argc, argv );
	
	Reciever r;
	SenderA sa;
	SenderB sb;
	
	QObject::connect( &sa, SIGNAL(send(int)), &r, SLOT(get(int)) );
	QObject::connect( &sb, SIGNAL(transmit(int)), &r, SLOT(get(int)) );
	
	sa.doSend();
	sb.doStuff();
	
	return 0;
}
