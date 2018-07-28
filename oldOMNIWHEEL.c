f#include "JoystickDriver.c";

task main()
{
	TJoystick joystick;
	while(1)
	{
		getJoystickSettings(joystick);
		float x=-(joystick.joy1_x1-1)/1.28;
		float y=(joystick.joy1_y1+1)/1.28;
		float b = joystick.joy1_TopHat;
	//	float clock=joystick.joy1_x2+1;
	//	float counter=joystick.joy1_y2+1;
		float angle=180*atan2(x, y)/PI;
		float speed=pow((x*x)+(y*y),0.5);
		angle+=270;
		setMotorSpeed(motorA, speed*cosDegrees(angle));
		setMotorSpeed(motorB, speed*cosDegrees(angle-120));
		setMotorSpeed(motorC, speed*cosDegrees(angle+120));
		if (b>0&&b<=3)
		{
			setMotorSpeed(motorA,-40);
			setMotorSpeed(motorB,-40);
			setMotorSpeed(motorC,-40);
		}
		if (b>=5&&b<=7)
		{
			setMotorSpeed(motorA,40);
			setMotorSpeed(motorB,40);
			setMotorSpeed(motorC,40);
		}
		if ((b<1||b==4||b==80) && ((x<5 && x>-5) && (y<5 && y>-5)))
		{
			setMotorSpeed(motorA,0);
			setMotorSpeed(motorB,0);
			setMotorSpeed(motorC,0);
		}
		sleep(100);
	}
}
