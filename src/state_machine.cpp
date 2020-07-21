#include "state_machine.h"

#include <QWidget>

#include "progress_dialog.h"
#include "state_machine_worker.h"

StateMachine *StateMachine::open(QThread *worker_thread, QWidget *parent)
{
  return new StateMachine(worker_thread, parent);
}

StateMachine::StateMachine(QThread *worker_thread, QWidget *parent) : QObject(parent)
{
  // Connect
  connect(this, &StateMachine::finished, this, &QObject::deleteLater);

  // Create worker
  StateMachineWorker *worker = new StateMachineWorker();
  worker->moveToThread(worker_thread);
  connect(this, &StateMachine::finished, worker, &QObject::deleteLater);
  /// Dataset file license
  connect(this, &StateMachine::requestProcess1, worker, &StateMachineWorker::process1);
  connect(worker, &StateMachineWorker::process1Done, this, &StateMachine::process1Done);
  /// Sonar list
  connect(this, &StateMachine::requestProcess2, worker, &StateMachineWorker::process2);
  connect(worker, &StateMachineWorker::process2Done, this, &StateMachine::process2Done);
  /// Sonar limit
  connect(this, &StateMachine::requestProcess3, worker, &StateMachineWorker::process3);
  connect(worker, &StateMachineWorker::process3Done, this, &StateMachine::process3Done);
  /// Dataset initialize
  connect(this, &StateMachine::requestProcess4, worker, &StateMachineWorker::process4);
  connect(worker, &StateMachineWorker::process4Done, this, &StateMachine::process4Done);

  // Create progress
  ProgressDialog *progress = ProgressDialog::create("OpenProject", "", "", 0, 0, parent, Qt::ApplicationModal);
  connect(this, &StateMachine::progressHide, progress, &QWidget::hide);
  connect(this, &StateMachine::progressShow, progress, &QWidget::show);
  connect(this, &StateMachine::finished, progress, &QWidget::hide);
  connect(this, &StateMachine::progressText, progress, &ProgressDialog::setLabelText);
  connect(this, &StateMachine::finished, progress, &QObject::deleteLater);

  // Check dataset file license
  emit progressText("First check");
  emit progressShow();
  emit requestProcess1();
}

void StateMachine::process1Done()
{
  emit progressText("Second check");
  emit requestProcess2();
}

void StateMachine::process2Done()
{
  emit progressText("Third check");
  emit requestProcess3();
}

void StateMachine::process3Done()
{
  emit progressText("Fourth check");
  emit requestProcess4();
}

void StateMachine::process4Done()
{
  emit progressHide();
  emit requestCloseDataset();
  emit datasetOpened();
  emit finished();
}
