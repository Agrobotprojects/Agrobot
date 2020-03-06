#include<P89V51RD2.H>
// header file of microcontroller
//Variables Declaration
sbit w_m1=P2^4;
sbit w_m2=P2^5;
sbit w_m11=P2^6;
sbit w_m22=P2^7;
//Function Declaration
void forward_motor();
void reverse_motor();
void left_motor();
void right_motor();
void main( void ) //Main Function
{
while(1)
{
forward_motor()
}
  void forward_motor()
//Forward movement
{
w_m1=1;
w_m2=0;
w_m11=1;
w_m22=0;
MSDelay( 1000);
w_m1=0;
w_m2=0;
w_m11=0;
w_m22=0;
right_motor();
}
void right_motor()
//Right movement
{
w_m1=0;
w_m2=1;
w_m11=1;
w_m22=0;
MSDelay( 1000);
w_m1=0;
w_m2=0;
w_m11=0;
w_m22=0;
left_motor();
}
void left_motor()
{
w_m1=1;
w_m2=0;
w_m11=0;
w_m22=1;
MSDelay( 1000);
w_m1=0;
w_m2=0;
w_m11=0;
w_m22=0;
reverse_motor();
}
void reverse_motor()
{
w_m1=0;
w_m2=1;
w_m11=0;
w_m22=1;
MSDelay( 1000);
w_m1=0;
w_m2=0;
w_m11=0;
w_m22=0;
}
