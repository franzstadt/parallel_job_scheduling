#include "pch.h"
#include "Graph.h"
#include "Graph.cpp"
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
	EXPECT_THROW(Graph g(0), std::length_error);
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


TEST(SchedulerTest, CheckWithPrecalculatedInputs)
{
	for (int i = 0; i < 3; i++)
	{
		ifstream input("../Parallel_job_scheduling_/input" + to_string(i) + ".txt");
		
		string vertices_count_str;
		input >> vertices_count_str;

		Graph g(stoi(vertices_count_str));

		string edge_str;
		while (input >> edge_str)
			g.AddEdge(stoi(edge_str.substr(0, edge_str.find("->"))), stoi(edge_str.substr(edge_str.find("->") + 2, string::npos)));

		vector<vector<int>> dependency_tree;

		EXPECT_EQ(g.CalculateDependencyTree(dependency_tree), true);

		string output_str;

		for (size_t j = 0; j < dependency_tree.size(); j++)
		{
			output_str += "Layer " + to_string(j) + ": ";
			for (size_t k = 0; k < dependency_tree[j].size(); k++)
				output_str += to_string(dependency_tree[j][k]) + " ";
			output_str += "\n";
		}

		ifstream output("../Parallel_job_scheduling_/expected" + to_string(i) + ".txt");

		std::string control_str((std::istreambuf_iterator<char>(output)),
			std::istreambuf_iterator<char>());

		EXPECT_EQ(output_str == control_str, true);
	}
}

TEST(SchedulerTest, CycleDetectionTest)
{
	Graph g(3);

	g.AddEdge(0, 1);
	g.AddEdge(1, 2);
	g.AddEdge(2, 0);

	vector<vector<int>> dependency_tree;

	EXPECT_EQ(g.CalculateDependencyTree(dependency_tree), false);

	Graph g2(4);
	
	g2.AddEdge(0, 1);
	g2.AddEdge(1, 2);
	g2.AddEdge(2, 3);
	g2.AddEdge(3, 1);

	EXPECT_EQ(g2.CalculateDependencyTree(dependency_tree), false);

	Graph g3(1);

	g3.AddEdge(0, 0);

	EXPECT_EQ(g3.CalculateDependencyTree(dependency_tree), false);

	Graph g4(1);

	EXPECT_EQ(g4.CalculateDependencyTree(dependency_tree), true);
}
