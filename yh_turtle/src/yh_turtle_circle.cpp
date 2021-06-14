#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "talkercpp");

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        geometry_msgs::Twist t;
        t.angular.z = 10;
        t.linear.x = 10;
        pub.publish(t);
        ros::spinOnce();
    }
    return 0;
}