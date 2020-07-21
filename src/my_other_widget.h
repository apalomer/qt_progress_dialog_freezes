#pragma once
#include <QMainWindow>

class MyOtherGUI : public QMainWindow
{
  Q_OBJECT
public:
  MyOtherGUI(QWidget* parent = nullptr);

  virtual QSize sizeHint() const override;
};
