#pragma once
#include <QObject>

class StateMachine : public QObject
{
  Q_OBJECT
public:
  static StateMachine* open(QThread* worker_thread, QWidget* parent);

signals:

  void finished();
  void datasetOpened();
  void requestCloseDataset();
  void errorMessage(QString text);

  void progressShow();

  void progressHide();

  void progressText(QString text);

  void requestProcess1();
  void requestProcess2();
  void requestProcess3();
  void requestProcess4();
protected slots:

  void process1Done();

  void process2Done();

  void process3Done();

  void process4Done();

protected:
  StateMachine(QThread* worker_thread, QWidget* parent = nullptr);
};
