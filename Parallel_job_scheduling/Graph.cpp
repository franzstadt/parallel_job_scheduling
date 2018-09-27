#include "Graph.h"

using std::vector;

void Graph::AddEdge(const Edge & edge)
{
	m_adjacency_list[edge.from].push_back(edge.to);
}

int Graph::GetVerticesCount() const
{
	return m_vertices_count;
}

std::vector<int> Graph::GetVertices(int vertex) const
{
	if (vertex >= m_adjacency_list.size())
		throw std::range_error("out of range");

	return m_adjacency_list[vertex];
}

