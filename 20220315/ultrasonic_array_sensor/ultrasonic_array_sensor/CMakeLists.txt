cmake_minimum_required(VERSION 3.0.2)
project(ultra_sonar_test)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp   rospy   sensor_msgs   std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ultra_sonar_test
  CATKIN_DEPENDS roscpp rospy sensor_msgs std_msgs
  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)


add_executable(ultra_sonar_test_node src/sonar_msg_talker.cpp)
add_dependencies(ultra_sonar_test_node ${ultra_sonar_test_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ultra_sonar_test_node  ${catkin_LIBRARIES})

add_executable(ultra_sonar_array_test_node src/sonars_msg_talker1.cpp)
add_dependencies(ultra_sonar_array_test_node ${ultra_sonar_array_test_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ultra_sonar_array_test_node  ${catkin_LIBRARIES})


