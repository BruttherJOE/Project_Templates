/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/Bool.h>

ros::NodeHandle  nh;

std_msgs::Bool estop_msg;
ros::Publisher estop_pub("arduino_estop", &estop_msg);

int inputpin = 7;   // pushbutton connected to digital pin 7
int val = 0;

void setup()
{
  nh.initNode();
  nh.advertise(estop_pub);

  pinMode(inputpin, INPUT);      // sets the digital pin 7 as input
}

void loop()
{
  val = digitalRead(inputpin);   // read the input pin

  if(val == 1){
    estop_msg.data = true;
  } else {
    estop_msg.data = false;
  }
 
  estop_pub.publish( &estop_msg );
  nh.spinOnce();
  delay(100);
}
