#include "ElevatorStop.h"


ElevatorStop::ElevatorStop(int time, int floor, directionEnum dir)
{
	this->time = time;
	this->floor = floor;
	this->dir = dir;
}

int ElevatorStop::getTime()
{
	return this->time;
}

int ElevatorStop::getFloor()
{
	return this->floor;
}

int ElevatorStop::getDir()
{
	return this->dir;
}

void ElevatorStop::setTime(int time)
{
	this->time = time;
}

void ElevatorStop::setFloor(int floor)
{
	this->floor = floor;
}

void ElevatorStop::setDir(directionEnum dir)
{
	this->dir = dir;
}

void ElevatorStop::print() const
{
	cout << this->time << " " << this->floor << " " << this->dir << endl;
}
