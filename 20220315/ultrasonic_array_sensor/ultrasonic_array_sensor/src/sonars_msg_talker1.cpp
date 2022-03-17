#include <ros/ros.h>
#include <ros/xmlrpc_manager.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float32.h>
#include <sensor_msgs/Range.h>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NO_SONAR 5


void sonar_sensor_msg_init(sensor_msgs::Range &range_name, char *frame_id_name)
{
  range_name.radiation_type = sensor_msgs::Range::ULTRASOUND;
  range_name.header.frame_id = frame_id_name;
  range_name.field_of_view = 3.1459/180*30;
  range_name.min_range = 0.0;
  range_name.max_range = 2.0;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Sonars_Array_pub");
  ros::NodeHandle n;
  
  int i;

  ros::Publisher pub_sonar_array = n.advertise<std_msgs::Float32MultiArray>("/sonar_array",100);
  ros::Publisher pub_sonar_range[NO_SONAR];
  ros::Rate loop_rate(10);
  std_msgs::Float32MultiArray sonar_array_msg;
  std_msgs::Float32 sonar_data;
  sensor_msgs::Range ultra_sonar_range[NO_SONAR];
  int count = 0;

  char topic_id_base[] = "sonar_";

  char topic_id[20];
  for(i=0;i<NO_SONAR;i++)
  {
     sprintf(topic_id,"%s%d",topic_id_base,i);
     pub_sonar_range[i] = n.advertise<sensor_msgs::Range>(topic_id,100);
     ROS_INFO("%s",topic_id);
     sonar_sensor_msg_init(ultra_sonar_range[i], topic_id);
    //
  }

  srand(time(NULL));

  while (ros::ok())
  {
    sonar_array_msg.data.clear(); // clear array data

    sonar_array_msg.data.resize(NO_SONAR);
    for(i=0;i<NO_SONAR; i++)
    {
      sonar_data.data = (float)(rand()%50+1)/10;
      sonar_array_msg.data[i]=(sonar_data.data);//Write it yourself, feasible
      ultra_sonar_range[i].header.stamp =  ros::Time::now();
      ultra_sonar_range[i].range =  sonar_data.data;

    }

    pub_sonar_array.publish(sonar_array_msg);

    for(i=0;i<NO_SONAR;i++)
    {
      pub_sonar_range[i].publish(ultra_sonar_range[i]);
      ROS_INFO("Sonar range[%d] =[%6.3lf]",i,  ultra_sonar_range[i].range );
    }

    //int num = sonar_array_msg.data.size();
    //ROS_INFO("The size of sonar_array_msg %d\n", num);
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }
  return 0;
}
