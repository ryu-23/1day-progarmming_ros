#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Bool.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h> //cmd_vel
#include <sensor_msgs/Range.h>   //ultrasonic sensor message


void UltraSonarCallback1(const std_msgs::Bool::ConstPtr& msg)
{
	if(msg->data)
	{
		ROS_INFO("AEB_Activation!!");
		ROS_INFO("DO~MAN~CHA~~~!!");
	}
	else
	{
		ROS_INFO("go~ go~ go~~");
	}
}
void UltraSonarCallback2(const std_msgs::Int32::ConstPtr& msg)
{
		ROS_INFO("numder : [%d]", msg->data);

	
	}

int main(int argc, char **argv)
{
  int count = 0;
  
  ros::init(argc, argv, "aeb_controller_sub");

  ros::NodeHandle n;

  ros::Rate loop_rate(1); 
  
  ros::Subscriber sub2 = n.subscribe("Bool_judment", 1000, UltraSonarCallback1);
  ros::Subscriber sub3 = n.subscribe("seq", 1000, UltraSonarCallback2);
  
  while(ros::ok())
  {
	loop_rate.sleep();
	ros::spinOnce();	
	count++;
  }
  
  return 0;
}
