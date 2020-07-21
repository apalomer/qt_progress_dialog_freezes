#pragma once
#include <QProgressDialog>

class ProgressDialog : public QProgressDialog
{
  Q_OBJECT
public:
  ProgressDialog(const QString& labelText, const QString& cancelButtonText, int minimum, int maximum,
    QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

  ProgressDialog(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

  ~ProgressDialog() override;

  static ProgressDialog* create(const QString& title, const QString& label, const QString& cancel_text,
    const int& minimum, const int& maximum, QWidget* parent = nullptr,
    const Qt::WindowModality window_modality = Qt::ApplicationModal);

protected:
  virtual bool event(QEvent* event) override;
};