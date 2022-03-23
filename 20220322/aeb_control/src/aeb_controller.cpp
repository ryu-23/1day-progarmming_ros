#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include "sensor_msgs/Range.h"    // ultrasonic sensor message
#include "geometry_msgs/Twist.h" // cmd_vel
#include "nav_msgs/Odometry.h"

std_msgs::Bool flag_AEB;
std_msgs::Float32 delta_range;
sensor_msgs::Range range;
std_msgs::Float32 old_sonar_range;
geometry_msgs::Twist cmd_vel_msg;
nav_msgs::Odometry pos, delta_pos, past_pos;
geometry_msgs::Twist V_spd;


void UltraSonarCallback(const sensor_msgs::Range::ConstPtr& msg)
{
//   ROS_INFO("Sonar Seq: [%d]" , msg->header.seq);
//   ROS_INFO("Sonar Range: [%f]" , msg->range);   
//   ROS_INFO("old_range : [%f]", old_sonar_range.data);
   delta_range.data = msg->range - old_sonar_range.data;
   
   
   if(delta_range.data < 0)
   {
   //   ROS_INFO("delta_range : [%f]", -delta_range.data);
      
      }
      else
      {
   //   ROS_INFO("delta_range : [%f]", delta_range.data);
      }
   
//   ROS_INFO("delta_range : [%f]", delta_range.data);
   old_sonar_range.data = msg->range;   
   
   
   if(msg-> range <=1)
   {
      ROS_INFO("AEB_Activation!!");
      flag_AEB.data = true;
      
      }
      else
      {
         flag_AEB.data = false; 
      }
   
}


/*
void CarControlCallback(const geometry_msgs::Twist& msg)
{
   ROS_INFO("Cmd_vel : linear_x [%f]",msg.linear.x);
//   printf("test");
   cmd_vel_msg = msg;
//   ROS_INFO("Cmd_vel : linear_x [%f]",cmd_vel_msg.linear.x);
   
}
*/
void odomCallback(const nav_msgs::Odometry& msg)
{
//   ROS_INFO("Pos : x-[%.2lf] y-[%.2lf]", msg.pose.pose.position.x, msg.pose.pose.position.y);
   pos.pose.pose.position.x = msg.pose.pose.position.x;
   pos.pose.pose.position.y = msg.pose.pose.position.y;
   
   delta_pos.pose.pose.position.x = pos.pose.pose.position.x - past_pos.pose.pose.position.x ;
   delta_pos.pose.pose.position.y = pos.pose.pose.position.y - past_pos.pose.pose.position.y ;
   
//   ROS_INFO("Delta Pos : x-[%.2lf] y-[%.2lf]", delta_pos.pose.pose.position.x,delta_pos.pose.pose.position.y);
   
   past_pos.pose.pose.position.x  = pos.pose.pose.position.x;
   past_pos.pose.pose.position.y  = pos.pose.pose.position.y;
   
   V_spd.linear.x= delta_pos.pose.pose.position.x / 0.02; 
   V_spd.linear.y= delta_pos.pose.pose.position.y / 0.02; // 50hz period
   
//   ROS_INFO("Vx: [%.2lf] Vy: [%.2lf]", v.linear.x, v.linear.y);
   
}

void CarControlCallback(const geometry_msgs::Twist& msg)
{
  // ROS_INFO("cmd_vel : linear_x [%f]", msg.linear.x);
   
   cmd_vel_msg = msg;
  // ROS_INFO("cmd_vel : linear_x [%f]", cmd_vel_msg.linear.x);
}





int main(int argc, char **argv)
{
   int count = 0;
   
   ros ::init(argc, argv, "aeb_controller_pub");
   
   ros ::NodeHandle n;
   
   ros ::Rate loop_rate(10); // 10
 
   std::string odom_sub_topic = "/ackermann_steering_controller/odom"; 
   


   ros::Publisher V_pub = n.advertise<geometry_msgs::Twist>("/V_spd", 10);
   ros::Publisher pub2 = n.advertise<std_msgs::Bool>("Bool_judment", 1000);
   ros::Publisher pub3 = n.advertise<std_msgs::Int32>("seq", 1000);
   //ros::Publisher pub_aeb_activation_differ = n.advertise<std_msgs::Float32>("/pub_aeb_activation_differ", 1000);
   ros::Publisher pub_aeb_activation_flag = n.advertise<std_msgs::Bool>("/aeb_activation_flag", 1);
   ros::Publisher pub_cmd_vel = n.advertise<geometry_msgs::Twist>("/ackermann_steering_controller/cmd_vel", 10);
   ros::Publisher delta_range_pub = n.advertise<std_msgs::Float32>("/delta_range", 10);
   
   ros ::Subscriber sub =n.subscribe("range",1000,UltraSonarCallback);
   //ros ::Subscriber cmd_vel_sub =n.subscribe("/cmd_vel",10,CarControlCallback);
    ros::Subscriber sub_odom = n.subscribe(odom_sub_topic, 10, &odomCallback); 
      ros::Subscriber cmd_val_sub = n.subscribe("/cmd_vel", 10, CarControlCallback);
       
   std_msgs::Int32 num;
  
   
   while (ros::ok())
   {
      if((count%10)==0)
      {
         pub_aeb_activation_flag.publish(flag_AEB);
      }
      
      if(flag_AEB.data == true)
      {
         cmd_vel_msg.linear.x = 0;
      
         
               
         pub_cmd_vel.publish(cmd_vel_msg);
      }
      else
      {
         pub_cmd_vel.publish(cmd_vel_msg);
      }
      
      delta_range_pub.publish(delta_range);
   
      V_pub.publish(V_spd);
      num.data = count;
     //  pub_aeb_activation_differ.publish(delta_range);
      pub2.publish(flag_AEB);
      pub3.publish(num);
      loop_rate.sleep();
      ros::spinOnce();
      ++count;
   }
   return 0 ;
}
