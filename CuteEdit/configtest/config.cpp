#include <QSettings>
#include <QDebug>

int main (int argc, char *argv[])
{
	// Proveedor, Producto
	QSettings settings("OpenSourcePress","ConfigTest");
	QString hello = "Hello World!";
	
	// Almacena un valor
	settings.setValue("Messages/Greetings",hello);
	// Reinicia valor
	hello = "";
	
	// Leer el valor y asignar en la variable
	hello = settings.value("Greetings").toString();
	qDebug() << hello; // Imprime el valor contenido
	
	return 0;
}
