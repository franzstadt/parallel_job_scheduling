#include "Scheduler.h"
#include <stack>

using std::vector;
using std::stack;


stack<int> Scheduler::CalculateTopologicalSort(const Graph& graph) const
{
	stack<int> topological_sort;
	int vertices_count = graph.GetVerticesCount();
	vector<bool> visited(vertices_count, false);

	for (int i = 0; i < vertices_count; i++)
		if (!visited[i])
			SortUntil(i, visited,graph, topological_sort);

	return topological_sort;
}

void Scheduler::SortUntil(int vertex, vector<bool>& visited,const Graph& graph, std::stack<int>& topological_sort) const
{
	visited[vertex] = true;

	for (const auto& v : graph.GetVertices(vertex))
	{
		if (!visited[v])
			SortUntil(v, visited, graph, topological_sort);
	}
	topological_sort.push(vertex);
}
