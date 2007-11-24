#include <QApplication>
#include <QWidget>
#include <QLabel>
 
int main(int argc, char **argv)
{
   QApplication app(argc, argv);
   
   QWidget window;
   QLabel *message = new QLabel("Hello, World!", &window);
   window.show();

   return app.exec();
}
