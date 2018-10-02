#include "pch.h"
#include "../Parallel_job_scheduling/Graph.h"
#include "../Parallel_job_scheduling/Graph.cpp"
#include "../Parallel_job_scheduling/Scheduler.h"
#include "../Parallel_job_scheduling/Scheduler.cpp"
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using std::range_error;
using std::ifstream;
using std::string;
using std::to_string;
using std::stoi;
using std::vector;

TEST(GraphTest, DeathTest1)
{
	EXPECT_THROW(Graph g(0), range_error);
	EXPECT_THROW(Graph g2(-1), std::length_error);
}

TEST(GraphTest, DeathTest2) 
{
	Graph g(1);
	EXPECT_THROW(g.AddEdge(0,4), range_error);
	EXPECT_THROW(g.AddEdge(4,0), range_error);
	EXPECT_THROW(g.AddEdge(-1,0), range_error);
	EXPECT_THROW(g.AddEdge(1,0), range_error);
	EXPECT_THROW(g.AddEdge(0,1), range_error);
}

TEST(GraphTest, GetVerticesTest)
{
	Graph g(5);

	g.AddEdge(1,2);
	vector<int> v = g.GetVertices(1);
}

TEST(SchedulerTest, RegressionTest)
{
	for (int i = 0; i < 3; i++)
	{
		ifstream input("../Parallel_job_scheduling/input" + to_string(i) + ".txt");
		
		string vertices_count_str;
		input >> vertices_count_str;

		Graph g(stoi(vertices_count_str));

		string edge_str;
		while (input >> edge_str)
			g.AddEdge(stoi(edge_str.substr(0, edge_str.find("->"))), stoi(edge_str.substr(edge_str.find("->") + 2, string::npos)));

		Scheduler s;
		vector<vector<int>> computational_graph = s.CalculateComputationalGraph(g);

		string output_str;

		for (int j = 0; j < computational_graph.size(); j++)
		{
			output_str += "Layer " + to_string(j) + ": ";
			for (int k = 0; k < computational_graph[j].size(); k++)
				output_str += to_string(computational_graph[j][k]) + " ";
			output_str += "\n";
		}

		ifstream output("../Parallel_job_scheduling/expected" + to_string(i) + ".txt");

		std::string control_str((std::istreambuf_iterator<char>(output)),
			std::istreambuf_iterator<char>());

		EXPECT_EQ(output_str == control_str, true);
	}
}

