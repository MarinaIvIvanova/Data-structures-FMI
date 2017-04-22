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

#ifndef OutsideQuery_h
#define OutsideQuery_h

#include "Query.h"
#include "DirectionEnum.h"


class OutsideQuery : public Query
{
public:


	OutsideQuery(int, int, directionEnum);
	virtual string toString();
	virtual void printQuery();
	virtual int getDir();


private:
	int dir;

};

#endif