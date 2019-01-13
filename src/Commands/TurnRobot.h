#ifndef TurnRobot_H
#define TurnRobot_H

#include "../CommandBase.h"

class TurnRobot : public CommandBase {
private:
	double amount;
	double kP;
	double kI;
	double kD;
	double error;
	double power;
	double basePower;
public:
	TurnRobot(double amount_);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // TurnRobot_H
