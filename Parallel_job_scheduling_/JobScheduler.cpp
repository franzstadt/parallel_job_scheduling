#include "JobScheduler.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;
using std::vector;

bool JobScheduler::ScheduleJobs(const std::string& filename) const
{
	ifstream input(filename);

	if (CheckCondition(!input.is_open(), 0, "Unable to open file!", ""))
		return false;

	if (CheckCondition(FileIsEmpty(input), 0, "Input File is empty!", ""))
		return false;

	string line;

	getline(input, line);

	if (CheckCondition(!IsDigit(line), 0, "The first line should define the numer of vertices! It must be digit!", ""))
		return false;

	int number_of_vertices = stoi(line);

	if (CheckCondition(number_of_vertices < 1, 0, "The number of vertices must be greather than 0!", ""))
		return false;

	try
	{
		bool has_error = false;
		Graph graph(number_of_vertices);

		for (int i = 1; !has_error && getline(input, line); i++)
		{
			int from, to;
			if (CheckEdgeLine(line, i, number_of_vertices, from, to))
			{
				graph.AddEdge(from, to);
			}
			else
			{
				has_error = true;
			}
		}

		if (!has_error)
		{
			cout << graph << endl;
			CalculateDependencies(graph);
		}
	}
	catch (const std::exception e)
	{
		cout << "Exception: " << e.what() << endl;
		return false;
	}
	return true;
}

bool JobScheduler::CheckEdgeLine(const std::string & line, int line_number, int number_of_vertices, int & from, int & to) const
{
	int arrow_pos = line.find("->");

	if (CheckCondition(arrow_pos == string::npos, line_number, "The '->' is missing.", line))
		return false;

	arrow_pos = line.find("->", arrow_pos + 1);
	if (CheckCondition(arrow_pos != string::npos, line_number, "It contains more '->'.", line))
		return false;

	string first = line.substr(0, line.find("->"));

	if (CheckCondition(!IsDigit(first) || first.empty(), line_number, "First vertex is not a digit.", line))
		return false;

	from = stoi(first);
	if (CheckCondition(from < 0 || from >= number_of_vertices, line_number, "First vertex is out of range.", line))
		return false;

	string second = line.substr(line.find("->") + 2, string::npos);

	if (CheckCondition(!IsDigit(second) || second.empty(), line_number, "Second vertex is not a digit.", line))
		return false;

	to = stoi(second);
	if (CheckCondition(to < 0 || to >= number_of_vertices, line_number, "Second vertex is out of range.", line))
		return false;

	return true;
}

void JobScheduler::CalculateDependencies(const Graph& graph) const
{
	vector<vector<int>> dependency_tree;
	if (graph.CalculateDependencyTree(dependency_tree))
	{
		cout << "Dependency tree:" << endl;

		for (size_t j = 0; j < dependency_tree.size(); j++)
		{
			cout << "Layer " << j << ": ";
			for (size_t k = 0; k < dependency_tree[j].size(); k++)
			{
				cout << dependency_tree[j][k] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "There is a cycle in the graph!" << endl;
	}
}

bool JobScheduler::CheckCondition(bool condition, int line_number, const std::string & reason, const std::string & line) const
{
	if (condition)
	{
		cout << "The " << line_number << " line is wrong. Reason: " << reason << " Line:" << line << endl;
		return true;
	}
	return false;
}
