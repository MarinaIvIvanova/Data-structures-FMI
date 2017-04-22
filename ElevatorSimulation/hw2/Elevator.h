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

#ifndef Elevator_h
#define Elevator_h

#include <list>
#include <vector>
#include "Query.h"
#include "ElevatorStop.h"


class Elevator
{
public:
	Elevator(std::vector<Query*> queryList);
	~Elevator();
	std::vector<ElevatorStop*> processQueries();
	std::vector<Query*> getQueriesSequence();

private:
	std::vector<Query*> queries;
	int getElevatorDirection(Query*, Query*);
	std::vector<ElevatorStop*> formatResult(std::vector<Query*> sortedQueries);


};

#endif