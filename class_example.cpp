#include "class_example.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "example_node");
    ros::NodeHandle nh;

    EXAMPLE ex(&nh);

    ros::Rate loop_rate(100);
    while (ros::ok())
    {
        example.Run();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}



void EXAMPLE::init()
{
  _pub = _nh.advertise<std_msgs::Float32>("/topic/pub", 1, true);
  _sub = _nh.subscribe("/topic/sub", 1, &example::CallBack, this);
}

void EXAMPLE::CallBack(const std_msgs::Float32& msg)
{
  temp = msg.data;
  _pub.publish(temp);
}

void EXAMPLE::Run()
{
}
