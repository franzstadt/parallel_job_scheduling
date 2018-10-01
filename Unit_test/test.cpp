#include "pch.h"
#include "../Parallel_job_scheduling/Graph.h"
#include "../Parallel_job_scheduling/Graph.cpp"

using std::range_error;

TEST(GraphTest, DeathTest1)
{
	EXPECT_THROW(Graph g(0), range_error);
}

TEST(GraphTest, DeathTest2) 
{
	Graph g(1);
	Edge e(2,4);
	
	EXPECT_THROW(g.AddEdge(e), range_error);
}