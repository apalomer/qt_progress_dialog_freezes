#include "state_machine_worker.h"

#include <thread>

StateMachineWorker::StateMachineWorker(QObject *parent) : QObject(parent)
{
}

void StateMachineWorker::process1()
{
  std::this_thread::sleep_for(std::chrono::seconds(2));
  emit process1Done();
}

void StateMachineWorker::process2()
{
  std::this_thread::sleep_for(std::chrono::seconds(2));
  emit process2Done();
}

void StateMachineWorker::process3()
{
  std::this_thread::sleep_for(std::chrono::seconds(2));
  emit process3Done();
}

void StateMachineWorker::process4()
{
  std::this_thread::sleep_for(std::chrono::seconds(2));
  emit process4Done();
}
