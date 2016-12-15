#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QGridLayout>

#include <ros/ros.h>
#include <turtlesim/Pose.h>

#include "LedWidget.h"
#include "CompassWidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
  void checkRos();

private:
  
  void turtlePosition(const turtlesim::Pose & pos);
  
  turtlesim::Pose LastPose_;
  ros::Subscriber TurtlePos_;
  
  QGridLayout MainLayout_;
  QTimer RosTimer;

  LedWidget     * Led_;
  CompassWidget * Compass_;
  
  QLabel * PosX_;
  QLabel * PosY_;
  QLabel * PosTheta_;
};

#endif // MAINWINDOW_H
