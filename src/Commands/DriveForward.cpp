#include "DriveForward.h"

DriveForward::DriveForward(double distance_) : distance(distance_), kP(1/distance_), kD(0), kI(0), error(0), power(0), basePower(0.1){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
}

// Called just before this Command runs the first time
void DriveForward::Initialize() {
	drive->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute() {
	error = distance - (drive->leftDistance() + drive->rightDistance())/2;
	power = kP*error;
	drive->tankDrive(power + basePower, power + basePower);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	if (error < 2 && error > -2) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void DriveForward::End() {
	drive->tankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {

}
