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
#include "Vector.h"
#include "Elevator.h"
#include "ElevatorStop.h"


int main()
{
	string type = "call";
	int floor = 1;
	int time = 2;

	Query* query1 = new Query(6, 3);
	OutsideQuery* query2 = new OutsideQuery(5, 6, directionEnum::UP);
	Query* query3 = new Query(3, 5);
	Query* query4 = new Query(2, 15);
	Query* query5 = new Query(1, 4);
	vector<Query*> queries;

	queries.push_back(query1);
	queries.push_back(query2);
	queries.push_back(query3);
	queries.push_back(query4);
	queries.push_back(query5);


	Elevator elevator(queries);
	vector<ElevatorStop*> processedQueries = elevator.processQueries();
	for (int i = 0; i < processedQueries.size(); i++) {
		processedQueries[i]->print();
	}

	return 0;

}