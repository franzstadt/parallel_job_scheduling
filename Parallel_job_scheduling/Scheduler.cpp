#include "Scheduler.h"
#include <stack>
#include <queue>

using std::vector;
using std::stack;
using std::queue;

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

vector<vector<int>> Scheduler::KahnsTopologicalSort(const Graph & graph) const
{
	vector<int> in_degree(graph.GetVerticesCount(), 0);

	for (int i = 0; i < graph.GetVerticesCount(); i++)
		for (const auto& vertex : graph.GetVertices(i))
			in_degree[vertex]++;

	queue<int> queue;
	vector<vector<int>> output;

	vector<int> layer_0_elements;
	for (int i = 0; i < graph.GetVerticesCount(); i++)
		if (in_degree[i] == 0)
		{
			queue.push(i);
			layer_0_elements.push_back(i);
		}

	output.push_back(layer_0_elements);
	int visited_vertecies = 0;

	vector<int> top_order;

	while (!queue.empty())
	{
		int u = queue.front();
		queue.pop();
		top_order.push_back(u);

		vector<int> layer_elements;
		for (const auto&v:graph.GetVertices(u))
		{
			if (--in_degree[v] == 0)
			{
				queue.push(v);
				layer_elements.push_back(v);
			}
		}
		if(!layer_elements.empty())
			output.push_back(layer_elements);

		visited_vertecies++;
	}

	return output;
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
