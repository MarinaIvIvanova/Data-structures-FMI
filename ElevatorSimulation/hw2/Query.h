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

#ifndef Query_h
#define Query_h

#include<iostream>
#include<string>


//#include "directionEnum.h"

using namespace std;

class Query
{
protected:
	string type;
	int floor;
	int time;

public:
	Query(int, int);
	//Query();
	virtual string toString();
	virtual void printQuery();

	bool operator<(const Query& rhs);

	int getTime();
	int getFloor();
	string getType();
	virtual int getDir();

};

#endif
