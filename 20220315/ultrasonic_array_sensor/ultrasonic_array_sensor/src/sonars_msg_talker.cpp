#include <ros/ros.h>
#include <ros/xmlrpc_manager.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float32.h>
#include <sstream>


#define NO_SONAR 5

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Sonars_Array_pub");
  ros::NodeHandle n;
  
  int i;

  ros::Publisher pub_sonar_array = n.advertise<std_msgs::Float32MultiArray>("/sonar_array",1000);
  ros::Rate loop_rate(10);
  std_msgs::Float32MultiArray sonar_array_msg;
  std_msgs::Float32 sonar_data;
  int count = 0;
  srand(time(NULL));

  while (ros::ok())
  {
    sonar_array_msg.data.clear(); // clear array data

    sonar_array_msg.data.resize(NO_SONAR);
    for(i=0;i<NO_SONAR; i++)
    {
      sonar_data.data = (float)(rand()%50+1)/10;
      sonar_array_msg.data[i]=(sonar_data.data);//Write it yourself, feasible
    }
    pub_sonar_array.publish(sonar_array_msg);

    //int num = sonar_array_msg.data.size();
    //ROS_INFO("The size of sonar_array_msg %d\n", num);
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }
  return 0;
}
