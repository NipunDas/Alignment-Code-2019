/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TurnRobot.h"

//amount refers to degrees of turn, left is negative, right is positive
TurnRobot::TurnRobot(double amount_) : amount(amount_), kP (1/amount_), kI(0), kD(0), error(0), power(0), basePower(0.1){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
}

// Called just before this Command runs the first time
void TurnRobot::Initialize() {
	drive->gyroReset();
}

// Called repeatedly when this Command is scheduled to run
void TurnRobot::Execute() {
	error = amount - drive->getAngle();
	power = kP*error;
	if (amount < 180 && amount > -180) {
	if (amount > 0) {
		drive->tankDrive(power + basePower, -power - basePower);
	} else if (amount < 0) {
		drive->tankDrive(-power - basePower, power + basePower);
	} else {
		std::cout << "Error: Turn Amount is set to 0" << std::endl;
	}
	} else {
		std::cout << "Error: Turn Amount is not between -180 and 180" << std::endl;
		amount = 0;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TurnRobot::IsFinished() {
	if (error < 2 && error > -2) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void TurnRobot::End() {
	drive->tankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnRobot::Interrupted() {

}
