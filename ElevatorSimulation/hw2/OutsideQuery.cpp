/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Marina Ivanova
* @idnumber 71420
* @task 2
* @compiler VC
*
*/

#include "OutsideQuery.h"


OutsideQuery::OutsideQuery(int floor, int time, directionEnum dir) : Query(floor, time)
{
	this->type = "call";
	this->dir = dir;
}

//OutsideQuery::OutsideQuery() : Query()
//{
//	this->dir = 0;
//}

string OutsideQuery::toString()
{
	string result = "";
	return result.append(type).append(std::to_string(floor)).append(std::to_string(time)).append(std::to_string(dir));
}

void OutsideQuery::printQuery()
{
	cout << type << " " << floor << " " << time << " " << dir << endl;
}

int OutsideQuery::getDir()
{
	return this->dir;
}