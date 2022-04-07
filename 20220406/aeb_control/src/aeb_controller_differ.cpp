#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Bool.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h> //cmd_vel
#include <sensor_msgs/Range.h>   //ultrasonic sensor message

std_msgs::Bool flag_AEB;
sensor_msgs::Range range;
std_msgs::Float32 delta_range;
std_msgs::Float32 old_sonar_range;
geometry_msgs::Twist cmd_vel_msg;

void SonardifferCallback(const std_msgs::Float32::ConstPtr& msg)
{
		//ROS_INFO("Sonar Range: [%f]" , msg->range);	
	//ROS_INFO("old_range : [%f]", old_sonar_range.data);
	//delta_range.data = msg->range - old_sonar_range.data;
	
	
	if(delta_range.data < 0)
	{
		ROS_INFO("delta_range : [%f]", -delta_range.data);
		
		}
		else
		{
		ROS_INFO("delta_range : [%f]", delta_range.data);
		}
	
   //	old_sonar_range.data = msg->range;	
	

}

int main(int argc, char **argv)
{
  int count = 0;
  
  ros::init(argc, argv, "aeb_controller_differ");

  ros::NodeHandle n;

  ros::Rate loop_rate(30); 
  
  ros::Subscriber sub_aeb_activation_differ = n.subscribe("/pub_aeb_activation_differ", 1000, SonardifferCallback);
  
  
  while(ros::ok())
  {
	loop_rate.sleep();
	ros::spinOnce();	
	count++;
  }
  
  return 0;
}
