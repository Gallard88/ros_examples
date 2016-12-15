
#include "MainWindow.h"

#include <examplelib/examplelib.h>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
  
  
  RosTimer.start(100);
  connect(&RosTimer, SIGNAL(timeout()), this, SLOT(checkRos()));
  
  Compass_ = new CompassWidget();
  Led_ = new LedWidget();

  setWindowTitle("Turtle Bot GUI");
  
  PosX_ = new QLabel("Unknown");
  PosY_ = new QLabel("Unknown");
  PosTheta_ = new QLabel("Unknown");
  
  QLabel * lbl = new QLabel("X");
  MainLayout_.addWidget(lbl,  0,0);  // row, column
  MainLayout_.addWidget(PosX_,0,1);  // row, column
  
  lbl = new QLabel("Y");
  MainLayout_.addWidget(lbl,  1,0);  // row, column
  MainLayout_.addWidget(PosY_,1,1);  // row, column
  
  lbl = new QLabel("Theta");
  MainLayout_.addWidget(lbl,      2,0);  // row, column
  MainLayout_.addWidget(PosTheta_,2,1);  // row, column
  
  MainLayout_.addWidget(Led_,    3,1);  // row, column
  MainLayout_.addWidget(Compass_,3,3);  // row, column
  setLayout(&MainLayout_);
  
  ros::NodeHandle node;
  TurtlePos_ = node.subscribe("/turtle1/pose", 50, &MainWindow::turtlePosition, this);
 
}

MainWindow::~MainWindow()
{
}

void MainWindow::turtlePosition(const turtlesim::Pose & pos)
{
  if (( LastPose_.x != pos.x ) ||
      ( LastPose_.y != pos.y ) ||
      ( LastPose_.theta != pos.theta )) {
    
    Led_->setChecked(true);
  } else {
    Led_->setChecked(false);
  }
  
  PosX_->setText(QString::number(pos.x));
  PosY_->setText(QString::number(pos.y));
  PosTheta_->setText(QString::number(pos.theta));
  Compass_->setBearing(Trig_RadiansToDegrees(pos.theta));
  
  LastPose_ = pos;
  
}

void MainWindow::checkRos()
{
  ros::spinOnce();
}

