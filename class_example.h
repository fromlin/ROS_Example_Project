#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <vector>
#include <string>

class example
{
public:
  example(ros::NodeHandle* nh);
private:
  ros::NodeHandle  _nh;
  ros::Publisher  _pub;
  ros::Subscriber _sub;
  
  
  double a;
  double b;
  void initSub();
  void initPub();
  void CallBack(const std_msgs::Float32::ConstPtr& msg);
};
