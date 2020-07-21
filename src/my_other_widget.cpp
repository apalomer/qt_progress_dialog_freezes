#include "my_other_widget.h"

#include <QLabel>
#include <QVBoxLayout>

MyOtherGUI::MyOtherGUI(QWidget* parent) : QMainWindow(parent)
{
  // Create central widget
  QWidget* central_widget = new QWidget(this);
  setCentralWidget(central_widget);

  // Create layout and button
  QVBoxLayout* layout = new QVBoxLayout(central_widget);
  layout->addWidget(new QLabel("Secondary main window", this));
}

QSize MyOtherGUI::sizeHint() const
{
  return QSize(350, 350);
}
