#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QGridLayout>

#include "LedWidget.h"
#include "CompassWidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
  void timeout();

private:
    QGridLayout MainLayout_;
    QTimer Timer;

    LedWidget *Led_;
    int Target_, Value_;
    int Yaw_;

    CompassWidget * Compass_;
};

#endif // MAINWINDOW_H
