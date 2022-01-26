#include <ros/ros.h>
#include <std_msgs/Float32.h>

class example
{
public:
  example(ros::NodeHandle* nh)_nh(*nh){
    init();
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


void example::init()
{
  _pub = _nh.advertise<std_msgs::Float32>("/topic/pub", 1, true);
  _sub = _nh.subscribe("/topic/sub", 1, &example::CallBack, this);
}

void example::CallBack(const std_msgs::Float32& msg)
{
  temp = msg.data;
  _pub.publish(temp);
}
