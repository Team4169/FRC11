//DEF PROGRAM EDITED BY Noah
#include "WPILib.h"

class DefaultRobot: public SimpleRobot {
	DriverStation * ds;
	Jaguar * mTest;
	Jaguar * mTest2;
	//DigitalInput *baySwitch;//Switch to tell if ball is in bay
	Joystick *rightStick; // joystick 1 (arcade stick or right tank stick)
	Joystick *leftStick; // joystick 2 (tank left stick)
	
	float rJoyX;
	float rJoyThrottle;
	bool rJoyTrigger;
	
	float rJoyPrevX;
	float rJoyPrevThrottle;
	
	float lJoyX;
	float lJoyThrottle;
	bool lJoyTrigger;
	
	float lJoyPrevX;
	float lJoyPrevThrottle;
	
	float collectorSpeed;
	float prevCollectorSpeed;
	
	float shooterSpeed;
	float prevShooterSpeed;
	
	float damper;
	
	//DriverStation *ds; // driver station object

	enum // Driver Station jumpers to control program operation
	{
		ARCADE_MODE = 1, // Tank/Arcade jumper is on DS Input 1 (Jumper present is arcade)
		ENABLE_AUTONOMOUS = 2,// Autonomous/Teleop jumper is on DS Input 2 (Jumper present is autonomous)
	} jumpers;

public:
	DefaultRobot(void) {
		ds = DriverStation::GetInstance();
		
		rightStick = new Joystick(1); // create the joysticks
		leftStick = new Joystick(2);
		//baySwitch = new DigitalInput(1); // create the limit switch inputs
		
		//Motor controllers
		mTest = new Jaguar(2);
		mTest2 = new Jaguar(3);
		//baySwitch = new DigitalInput(1);
		
		damper = 2;
		
		/*collectorSpeed = 0.0f;
		prevCollectorSpeed = 0.0f;
		shooterSpeed = 0.0f;
		prevShooterSpeed =0.0f;
		*/
		//Update the motors at least every 100ms.
		//myRobot->SetExpiration(0.1);
	}
	
	void Autonomous(void) {
		/*
		 mTest->Set(0.5f, 0);
		 mTest2->Set(0.5f, 0);
		 Wait(1);
		 mTest->Set(0.0f, 0);
		 mTest2->Set(0.0f, 0);
		 */
		
	}
	
	void OperatorControl(void) {
		//Set up prev values
		/*rJoyPrevX = rJoyThrottle;
		rJoyPrevThrottle = rJoyThrottle;
		lJoyPrevX = lJoyX;
		
		prevCollectorSpeed = collectorSpeed;
		prevShooterSpeed = shooterSpeed;*/
	
		//Setting joystick values
		/*rJoyX = rightStick->GetX();
		rJoyThrottle = rightStick->GetThrottle();
		rJoyTrigger = rightStick->GetTrigger();
		
		lJoyX = leftStick->GetX();
		lJoyThrottle = leftStick->GetThrottle();
		lJoyTrigger = leftStick->GetTrigger();*/
		float speed = rightStick->GetY();
		mTest->Set(speed, 0);
		mTest2->Set(speed, 0);
		
		//********** Right Joystick value setting **********//
		//Right motor set
		/*if(rJoyX != rJoyPrevX){//Prevent motor spamming
			mRight.Set(rJoyX / damper, 0);
		}
		
		//Collector speed
		//Prevent motor spam, check that ball isn't in bay or trigger isn't pressed
		//if(baySwitch->Get() != 0 && rJoyTrigger != true && lJoyTrigger != true){
		if(rJoyTrigger != true && lJoyTrigger != true){
			collectorSpeed = 1.0f;
		} else{
			collectorSpeed = 0.0f;
		}
		
		if(prevCollectorSpeed != collectorSpeed){
			mCollector.set(collectorSpeed, 0);
		}
	
		//Shooter speed
		if(rJoyTrigger == true || lJoyTrigger == true){
			shooterSpeed = 1.0f;
		} else{
			shooterSpeed = 0.0f;
		}
		
		if(prevShooterSpeed != shooterSpeed){
			mShoote\r1.set(shooterSpeed, 0);
			mShooter2.set(shooterSpeed, 0);
		}*/
		//********************//
		
		
		//********** Left Joystick value setting **********//
		//Left motor set
		/*if(lJoyX != lJoyPrevX){//Prevent motor spamming
			lRight.Set(lJoyX / damper, 0);
		}
		*/
		//********************//
	}
};
	
	START_ROBOT_CLASS(DefaultRobot);
