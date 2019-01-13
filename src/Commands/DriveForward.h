#ifndef DriveForward_H
#define DriveForward_H

#include "../CommandBase.h"

class DriveForward : public CommandBase {
private:
	double distance;
	double kP;
	double kI;
	double kD;
	double error;
	double power;
	double basePower;
public:
	DriveForward(double distance_);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForward_H
