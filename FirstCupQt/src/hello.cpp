#include <QApplication>
#include <QLabel>
 
int main(int argc, char **argv)
{
   QApplication app(argc, argv);
   
   QLabel message("Hello, World!");
   message.show();

   return app.exec();
}
