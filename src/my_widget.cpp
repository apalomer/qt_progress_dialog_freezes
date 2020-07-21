#include "my_widget.h"

#include <QThread>
#include <QTimer>
#include <QVBoxLayout>

#include "my_other_widget.h"
#include "state_machine.h"

MyGUI::MyGUI(QWidget* parent) : QMainWindow(parent)
{
  // Set title
  setWindowTitle("GUI");

  // Create central widget
  QWidget* central_widget = new QWidget(this);
  setCentralWidget(central_widget);

  // Create layout and button
  QVBoxLayout* layout = new QVBoxLayout(central_widget);
  push_button_ = new QPushButton("Start process", this);
  layout->addWidget(push_button_);
  connect(push_button_, &QPushButton::clicked, this, &MyGUI::onButtonPush);

  // Create other main window
  MyOtherGUI* other_gui = new MyOtherGUI(this);
  other_gui->setWindowFlag(Qt::Window);
  other_gui->setWindowTitle("Other gui");
  other_gui->show();

  // Thread for working
  worker_thread_ = new QThread(this);
  worker_thread_->start();
}

QSize MyGUI::sizeHint() const
{
  return QSize(350, 150);
}

void MyGUI::onButtonPush()
{
  StateMachine* odsm = StateMachine::open(worker_thread_, this);
  connect(odsm, &StateMachine::finished, this, [this]() { QTimer::singleShot(1000, this, &MyGUI::onButtonPush); });
  push_button_->setEnabled(false);
}
