#pragma once
#include <QObject>

class StateMachineWorker : public QObject
{
  Q_OBJECT
public:
  StateMachineWorker(QObject* parent = nullptr);

signals:

  void process1Done();

  void process2Done();

  void process3Done();

  void process4Done();

public slots:
  void process1();

  void process2();

  void process3();

  void process4();
};