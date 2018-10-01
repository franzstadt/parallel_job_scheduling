#include "Scheduler.h"
#include <stack>
#include <queue>

using std::vector;
using std::stack;
using std::queue;

vector<vector<int>> Scheduler::CalculateComputationalGraph(const Graph & graph) const
{
	vector<int> in_degree(graph.GetVerticesCount(), 0);

	for (int i = 0; i < graph.GetVerticesCount(); i++)
		for (const auto& vertex : graph.GetVertices(i))
			in_degree[vertex]++;

	vector<vector<int>> output;
	vector<int> vertices;

	vector<int> layer_0_elements;
	for (int i = 0; i < graph.GetVerticesCount(); i++)
		if (in_degree[i] == 0)
		{
			vertices.push_back(i);
			layer_0_elements.push_back(i);
		}

	output.push_back(layer_0_elements);

	vector<int> top_order;

	while (!vertices.empty())
	{
		vector<int> neighbours;

		for (const auto& u : vertices)
			for (const auto&v : graph.GetVertices(u))
				if (--in_degree[v] == 0)
					neighbours.push_back(v);
		
		vertices = neighbours;
		if(!neighbours.empty())
			output.push_back(neighbours);
	}

	return output;
}

