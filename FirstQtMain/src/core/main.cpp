#include "first.h"

int main(int argc, char **argv)
{
  /*
  ** Create the Qt application object.
  **
  */
  QApplication app(argc,argv);
 
  /*
  ** Set the organization and application names for QSettings
  **  savage and restoration.
  **
  */
  app.setOrganizationDomain(ORG_DOMAIN);
  app.setApplicationName(APP_NAME);
 
  firstMainWindow win;
  win.show();
 
  return app.exec();
 
} // endint main(int argc, char **argv)

