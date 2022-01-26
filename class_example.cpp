#include "class_example.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "example_node");
    ros::NodeHandle nh;

    example ex(&nh);

    ros::Rate loop_rate(100);
    while (ros::ok())
    {
        example.Run();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
