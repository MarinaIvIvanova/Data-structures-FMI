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

#include "Elevator.h"




Elevator::Elevator(std::vector<Query*> queryList)
{
	this->queries = queryList;
	//queries.push_front(new Query("call", 1, 0));
	Query* initial = new Query(1, 0);
	queries.insert(queries.begin(), initial);
}


Elevator::~Elevator()
{
}

vector<ElevatorStop*> Elevator::processQueries()
{
	Query* finishedQuery;
	Query* curQuery;
	for (int i = 0; i < queries.size() - 1; i++) {
		if (queries.size() > 1) {
			finishedQuery = queries[i];
			curQuery = queries[i + 1];
			int direction = getElevatorDirection(finishedQuery, curQuery);
			int timeQ = (curQuery->getFloor() - finishedQuery->getFloor()) * 5;

			for (int j = i; j < queries.size(); j++) {
				if (queries[j]->getType() == "go" || (queries[j]->getType() == "call" && queries[j]->getDir() == direction)) {
					bool hasReceivedBeforeFinishCurrentQuerry = (queries[j]->getTime() - curQuery->getTime()) < timeQ;
					bool isReceivedQueryFloorAfterCurrentFloor = (finishedQuery->getFloor() + (queries[j]->getTime() - finishedQuery->getTime()) / 5) < queries[j]->getFloor();

					if (hasReceivedBeforeFinishCurrentQuerry && isReceivedQueryFloorAfterCurrentFloor) {
						queries.insert(queries.begin() + i + 1, queries[j]);
						queries.erase(queries.begin() + j + 1);
					}
				}
			}
		}
	}
	
	return this->formatResult(queries);
	vector<ElevatorStop*> asd;
	return asd;
}

int Elevator::getElevatorDirection(Query* from, Query* to)
{
	if (from->getFloor() - to->getFloor() < 0) {
		return directionEnum::UP;
	}
	else if (from->getFloor() - to->getFloor() > 0)
	{
		return directionEnum::DOWN;
	}

	return -1;
}

vector<Query*> Elevator::getQueriesSequence() {
	return queries;
}


vector<ElevatorStop*> Elevator::formatResult(std::vector<Query*> sortedQueries)
{
	vector<ElevatorStop*> result;
	for (int i = 1; i < sortedQueries.size(); i++) {
		int time = (sortedQueries[i - 1]->getFloor() - sortedQueries[i]->getFloor()) * 5 + sortedQueries[i]->getTime();
		int floor = sortedQueries[i]->getFloor();
		directionEnum dir = sortedQueries[i - 1]->getFloor() < sortedQueries[i]->getFloor() ? directionEnum::UP : directionEnum::DOWN;

		result.push_back(new ElevatorStop(time, floor, dir));

	}

	return result;
}



