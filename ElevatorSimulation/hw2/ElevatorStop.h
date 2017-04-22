#ifndef ElevatorStop_h
#define ElevatorStop_h

#include "directionEnum.h"
#include <iostream>

using namespace std;

class ElevatorStop
{
public:
	ElevatorStop(int, int, directionEnum);

	int getTime();
	int getFloor();
	int getDir();

	void setTime(int);
	void setFloor(int);
	void setDir(directionEnum);

	void print() const;


private:
	int time;
	int floor;
	int dir;

};

#endif

	