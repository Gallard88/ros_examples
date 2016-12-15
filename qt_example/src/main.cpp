#include "MainWindow.h"
#include <QApplication>
#include <ros/ros.h>

class qt_example : public QApplication
{
public:
  ros::NodeHandlePtr nh_;

  qt_example(int& argc, char** argv)
    : QApplication(argc, argv)
  {
    ros::init(argc, argv, "qt_example", ros::init_options::NoSigintHandler);
    nh_.reset(new ros::NodeHandle);
  }
  
  int exec()
  {
    MainWindow frame;
    frame.show();
    return QApplication::exec();
  }
};

int main(int argc, char** argv)
{
  qt_example app(argc, argv);
  return app.exec();
}
