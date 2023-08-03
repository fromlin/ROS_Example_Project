#ifndef EXAMPLE_CLASS_H
#define EXAMPLE_CLASS_H

#include <ros/ros.h>
#include <std_msgs/Float32.h>

class EXAMPLE
{
public:
  EXAMPLE(ros::NodeHandle* nh) : _nh(*nh)
  {
    init();
  }
  ~EXAMPLE()
  {

  }
  
  void Run();
  
private:
  ros::NodeHandle  _nh;
  ros::Publisher  _pub;
  ros::Subscriber _sub;
  
  
  double temp;
  void init();
  void CallBack(const std_msgs::Float32& msg);
};

#endif // EXAMPLE_CLASS_H
