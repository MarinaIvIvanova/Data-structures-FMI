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

#include "Query.h"

Query::Query(int floor, int time)
{
	this->type = "go";
	this->floor = floor;
	this->time = time;
}

//Query::Query()
//{
//	this->type = "";
//	this->floor = 0;
//	this->time = 0;
//}

string Query::toString()
{
	string result = "";
	return result.append(type).append(std::to_string(floor)).append(std::to_string(time));
}


void Query::printQuery()
{
	cout << type << " " << floor << " " << time << endl;
}

int Query::getTime()
{
	return this->time;
}

int Query::getFloor()
{
	return this->floor;
}

string Query::getType()
{
	return this->type;
}

int Query::getDir()
{
	return NULL;
}

bool Query::operator<(const Query& rhs)
{
	return this->time < rhs.time;
}