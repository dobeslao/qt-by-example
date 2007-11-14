

// Aplicacion principal
#include <QApplication>

// Comuniación entrada salida
#include <iostream>

//Definimos la clase chismosa
class VerboseObject : public QObject
{
public:
	VerboseObject(QObject *parent=0, char* name=0) : QObject (parent)
	{
		appname = name;
		std::cout << "Created: "  << appname << std::endl;
	}
	
	~VerboseObject()
	{
		std::cout << "Deleted: "  << appname << std::endl;
	}
	
	void doStuff()
	{
		std::cout << "Hace algo: " << appname << std::endl;
	}
		
private:
	char *appname; 
};

int main(int argc, char **argv)
{
	//Se crea una aplicacion
	QApplication app(argc, argv);
	
	//Se crean instancias de la clase
	VerboseObject top(0, "top");
	VerboseObject *x =  new VerboseObject( &top, "x");
	VerboseObject *y =  new VerboseObject( &top, "y");
	
	VerboseObject *z =  new VerboseObject(    x, "z");
	
	//Ejecuta doStuff
	top.doStuff();
	x->doStuff();
	y->doStuff();
	z->doStuff();
	
	return 0;
}

//-- NOTAS FINALES
//-- Estructura de la jerarquia
/*
 *                           top
 *                          /   \
 *                         x     y
 *                         |
 *                         z
 * 
 * Al finalizar la ejecucion, todos los objetos son eliminados, notar que cada rama es eliminada
 * completamente antes de que continue con la siguiente. Se puede observar cuando se elimina z
 * antes de y. 
 * 
 * Si la referencia del padre se elimina de X y Y, escapes de memoria (memory leak) pueden ocurrir, p.e.
 * 
 *   VerboseObject *x =  new VerboseObject( 0, "x");
 *   VerboseObject *y =  new VerboseObject( 0, "y");
 * 
 * En esta situacion no causa daño, debido a que la aplicacion termina despues de que ocurre, pero en otra
 * situacion puede ser una potencial amenaza de la estabilidad completa del sistema. 
 */
