#pragma once
#include "Graph.h"
#include <vector>
#include <stack>

class Scheduler
{
	
	void SortUntil(int vertex, std::vector<bool>& visited,const Graph& graph, std::stack<int>& topological_sort) const;
public:
	std::stack<int> CalculateTopologicalSort(const Graph& graph) const;
};

