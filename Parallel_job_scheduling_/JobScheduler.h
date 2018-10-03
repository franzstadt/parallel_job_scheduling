#pragma once
#include <string>
#include "Graph.h"

class JobScheduler
{
public:
	void LoadGraphFromFile(const std::string& filename);
	void ScheduleJobs();

private:
	bool CheckEdgeLine(const std::string& line, int line_number, int number_of_vertices, int& from, int& to);
	void CalculateDependencies(const std::string& graph);
	bool CheckCondition(bool condition, int line_number, const std::string& reason, const std::string& line);
};

