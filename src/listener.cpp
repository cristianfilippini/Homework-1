#include "ros/ros.h"
#include "std_msgs/String.h"

void selectorCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Ho ricevuto: [%s]", msg->data.c_str());
}


int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("selector", 1000, selectorCallback);
  ros::spin();
  
  return 0;
}


