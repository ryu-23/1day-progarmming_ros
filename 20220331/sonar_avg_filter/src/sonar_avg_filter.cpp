#include "ros/ros.h"
#include <sensor_msgs/Range.h>   //ultrasonic sensor message

sensor_msgs::Range avg_range;

float range1,range2,range3,range4,range5;


void RangeCallback(const sensor_msgs::Range::ConstPtr& msg)
{
		
	range5 = range4;
	
	range4 = msg->range;
	
	range4 = range3;
	
	range3 = msg->range;
	
	range3 = range2;
	
	range2 = msg->range;
	
	range2 = range1; 

	range1 = msg->range;
	
	
	
	
	avg_range.range = (range1 + range2 + range3 + range4 + range5)/5.0;
	//ROS_INFO("[%f]",avg_range.range);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sonar_avg_filter");

  ros::NodeHandle n;
  
  ros::Subscriber sub = n.subscribe("/range", 1000, RangeCallback);
  
  ros::Publisher pub_avg_range = n.advertise<sensor_msgs::Range>("/range_avg", 1000);

  ros::Rate loop_rate(1); 
  
  while(ros::ok())
  {
	  pub_avg_range.publish(avg_range);
	  
	  ROS_INFO("range1 = [%f]",range1);
	  ROS_INFO("range2 = [%f]",range2);
	  ROS_INFO("range3 = [%f]",range3);
	  ROS_INFO("range4 = [%f]",range4);
	  ROS_INFO("range5 = [%f]",range5);
	  
	  ROS_INFO("avg_range = [%0.2f]",avg_range.range);
	  
	  loop_rate.sleep();
	  ros::spinOnce();	
  }
  return 0;
}
