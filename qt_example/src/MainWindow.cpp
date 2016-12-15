
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    Target_(10), Value_(0), Yaw_(0)
{
  Timer.start(1000);
  connect(&Timer, SIGNAL(timeout()), this, SLOT(timeout()));

  Compass_ = new CompassWidget();
  Led_ = new LedWidget();

  setWindowTitle("Test Widgets");
  MainLayout_.addWidget(Led_,0,0);  // row, column
  MainLayout_.addWidget(Compass_,0,2);  // row, column
  setLayout(&MainLayout_);

}

MainWindow::~MainWindow()
{
}

void MainWindow::timeout()
{
  Yaw_ ++;
  if ( Yaw_ >= 360 ) {
    Yaw_ = 0;
  }
  Compass_->setBearing(Yaw_);
  
  if ( Led_->isChecked() == true ) {
    Led_->setChecked(false);
  } else {
    Led_->setChecked(true);

  }
}
