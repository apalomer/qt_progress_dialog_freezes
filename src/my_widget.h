#pragma once
#include <QMainWindow>
#include <QPushButton>

class MyGUI : public QMainWindow
{
  Q_OBJECT
public:
  MyGUI(QWidget* parent = nullptr);

  virtual QSize sizeHint() const override;

protected slots:
  void onButtonPush();

private:
  QPushButton* push_button_ = nullptr;
  QThread* worker_thread_ = nullptr;
};
