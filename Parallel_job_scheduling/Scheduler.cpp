#include "Scheduler.h"
#include <stack>
#include <queue>

using std::vector;
using std::stack;
using std::queue;

vector<vector<int>> Scheduler::CalculateDependencyTree(const Graph & graph, bool& cycle_detected) const
{
	cycle_detected = false;
	vector<int> in_degree(graph.GetVerticesCount(), 0);

	for (int i = 0; i < graph.GetVerticesCount(); i++)
		for (const auto& vertex : graph.GetVertices(i))
			in_degree[vertex]++;

	vector<vector<int>> output;
	vector<int> vertices;

	vector<int> first_layer;
	for (int i = 0; i < graph.GetVerticesCount(); i++)
		if (in_degree[i] == 0)
		{
			vertices.push_back(i);
			first_layer.push_back(i);
		}

	output.push_back(first_layer);

	int count = vertices.size();

	if (count == graph.GetVerticesCount())
		return output;

	if (vertices.empty())
		cycle_detected = true;

	while (!vertices.empty())
	{
		vector<int> neighbours;

		for (const auto& u : vertices)
			for (const auto&v : graph.GetVertices(u))
				if (--in_degree[v] == 0)
				{
					neighbours.push_back(v);
					count++;
				}
		
		vertices = neighbours;
		if(!neighbours.empty())
			output.push_back(neighbours);
	}

	if (count != graph.GetVerticesCount())
		cycle_detected = true;


	return output;
}

