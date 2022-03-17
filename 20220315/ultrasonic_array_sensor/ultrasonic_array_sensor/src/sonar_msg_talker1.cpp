#include <ros/ros.h>
#include <ros/xmlrpc_manager.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float32.h>
#include <string.h>
#include <sstream>


#define NO_SONAR 5

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Sonars_Array_pub");
  ros::NodeHandle n;
  
  int i;

  std_msgs::Float32 sonar_data;
  char topic_id_base[] = "sonar_1";
  char c_number[5];
  char topic_id[20];
  for(i=0;i<NO_SONAR;i++)
  {
      strcpy(topic_id,topic_id_base);
      printf("%s\n",topic_id);
      //itoa(i,c_number,10);
    //  strcat(topic_id,c_number);
  }
  ros::Publisher pub_sonar_array = n.advertise<std_msgs::Float32MultiArray>("/sonar_array",1000);
  
  ros::Rate loop_rate(10);
   
  std_msgs::Float32MultiArray sonar_array_msg;

  int count = 0;
  srand(time(NULL));

  while (ros::ok())
  {
    sonar_array_msg.data.clear(); // clear array data
   // sonar_array_msg.layout = NO_SONAR;
    for(i=0;i<NO_SONAR; i++)
    {
      sonar_data.data = (float)(rand()%50+1)/10;
      sonar_array_msg.data.push_back(sonar_data.data);//Write it yourself, feasible
    }
    pub_sonar_array.publish(sonar_array_msg);
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
