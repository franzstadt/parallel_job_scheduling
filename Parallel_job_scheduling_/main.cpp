#include <iostream>
#include <fstream>
#include "Graph.h"
#include "JobScheduler.h"
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::cin;

int main()
{
	cout << "Insert file name(exit 'q'): ";
	string filename;

	JobScheduler scheduler;
	
	cin >> filename;
	while (filename != "q" && !scheduler.ScheduleJobs(filename))
	{
		cout << "Insert file name(exit 'q'): ";
		cin >> filename;
	}

	system("pause");
	return 0;
}