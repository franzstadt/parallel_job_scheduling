#pragma once
#include <string>
#include "Graph.h"
#include <algorithm>
#include <cctype>
#include <fstream>

class JobScheduler
{
public:
	bool ScheduleJobs(const std::string& filename) const;

private:
	bool CheckEdgeLine(const std::string& line, int line_number, int number_of_vertices, int& from, int& to) const;
	void CalculateDependencies(const Graph& graph) const;
	bool CheckCondition(bool condition, int line_number, const std::string& reason, const std::string& line) const;
	bool FileIsEmpty(std::ifstream& input) const
	{
		return input.peek() == std::ifstream::traits_type::eof();
	}
	bool IsDigit(const std::string& str) const
	{
		return !str.empty() && std::find_if(str.begin(), str.end(), [](char c) { return !std::isdigit(c); }) == str.end();
	}
};

