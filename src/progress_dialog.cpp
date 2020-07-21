#include "progress_dialog.h"

#include <QKeyEvent>

ProgressDialog::ProgressDialog(const QString &labelText, const QString &cancelButtonText, int minimum, int maximum,
                               QWidget *parent, Qt::WindowFlags f)
  : QProgressDialog(labelText, cancelButtonText, minimum, maximum, parent, f)
{
}

ProgressDialog::ProgressDialog(QWidget *parent, Qt::WindowFlags f) : QProgressDialog(parent, f)
{
}

ProgressDialog::~ProgressDialog()
{
}

ProgressDialog *ProgressDialog::create(const QString &title, const QString &label, const QString &cancel_text,
                                       const int &minimum, const int &maximum, QWidget *parent,
                                       const Qt::WindowModality window_modality)
{
  ProgressDialog *progress = new ProgressDialog(label, cancel_text, minimum, maximum, parent);
  if (!title.isEmpty())
    progress->setWindowTitle(title);
  progress->setWindowFlag(Qt::CustomizeWindowHint, true);
  progress->setWindowFlag(Qt::WindowCloseButtonHint, false);
  progress->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
  progress->setWindowModality(window_modality);
  if (cancel_text.isEmpty())
    progress->setCancelButton(nullptr);
  return progress;
}

bool ProgressDialog::event(QEvent *event)
{
  QKeyEvent *keyEvent = dynamic_cast<QKeyEvent *>(event);
  if (keyEvent && keyEvent->key() == Qt::Key_Escape)
  {
    keyEvent->accept();
    return true;
  }
  return QProgressDialog::event(event);
}
