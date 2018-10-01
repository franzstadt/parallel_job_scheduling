#pragma once
#include "Graph.h"
#include <vector>
#include <stack>

class Scheduler
{
public:
	std::vector<std::vector<int>> CalculateComputationalGraph(const Graph& graph) const;
};

