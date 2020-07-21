#include <QApplication>
#include <QStyleFactory>

#include "my_widget.h"

int main(int argc, char** argv)
{
  // Create application
  QApplication app(argc, argv);
  app.setStyle(QStyleFactory::create(QStringLiteral("Fusion")));

  // Create widget
  MyGUI* my_gui = new MyGUI;
  my_gui->show();

  // Run application
  return app.exec();
}
