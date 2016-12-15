cmake_minimum_required(VERSION 2.8.3)
project(qt_example)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  roslib
  examplelib
)

find_package(Qt5Widgets REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread)

include_directories(include
  src/
  ${Boost_INCLUDE_DIRS}
  ${examplelib_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
  ${roscpp_INCLUDE_DIRS}
)
link_directories(${catkin_LIBRARY_DIRS})

#add_message_files(DIRECTORY msg FILES )
#add_service_files(DIRECTORY srv FILES )
#generate_messages(DEPENDENCIES geometry_msgs std_msgs std_srvs)
set(CMAKE_CXX_FLAGS "-Wall")

catkin_package(CATKIN_DEPENDS geometry_msgs message_runtime std_msgs std_srvs)

set(qt_example_SRCS
  src/CompassWidget.cpp
  src/MainWindow.cpp
  src/LedWidget.cpp
  src/main.cpp
)

set(qt_example_HDRS
  src/CompassWidget.h
  src/LedWidget.h
  src/MainWindow.h
)

qt5_wrap_cpp(qt_example_MOCS ${qt_example_HDRS})


add_executable(qt_example ${qt_example_SRCS} ${qt_example_MOCS})
target_link_libraries(qt_example Qt5::Widgets ${catkin_LIBRARIES} ${Boost_LIBRARIES} ${examplelib_LIBRARIES})


