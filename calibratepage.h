#ifndef CALIBRATEPAGE_H
#define CALIBRATEPAGE_H

#include <QWidget>
#include <QLocalSocket>
#include <QBuffer>
#include <QPixmap>
#include <QProcess>
#include <QThread>
#include <QTimer>

namespace Ui {
  class CalibratePage;
}

class CalibratePage : public QWidget {
  Q_OBJECT

public:
  explicit CalibratePage(QWidget* parent, QLocalSocket* socket);
  ~CalibratePage();

  void activated();
  void deactivated();

private:
  Ui::CalibratePage* ui;
  QLocalSocket* socket;
  QByteArray buffer;
  int expectedSize = -1;
  void readFrame();
};

#endif // CALIBRATEPAGE_H
