#pragma once
#include "Graph.h"
#include <vector>
#include <stack>

class Scheduler
{
public:
	std::vector<std::vector<int>> CalculateDependencyTree(const Graph& graph, bool& cycle_detected) const;
};

