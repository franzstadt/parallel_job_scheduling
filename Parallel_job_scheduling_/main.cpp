#include <iostream>
#include <fstream>
#include "Graph.h"
#include "JobScheduler.h"
using std::cout;
using std::endl;
using std::ifstream;

int main()
{ 
	JobScheduler j;
	j.LoadGraphFromFile("input0.txt");
	j.ScheduleJobs();

	system("pause");
	return 0;
}