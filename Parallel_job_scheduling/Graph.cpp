#include "Graph.h"

using std::vector;

Graph::Graph(int vertices) : m_vertices_count(vertices), m_adjacency_list(vertices)
{
	
	if (vertices < 1)
		throw std::range_error("out of range");
}

void Graph::AddEdge(int from, int to)
{
	if (from >= m_vertices_count || from < 0 ||
		to >= m_vertices_count || to < 0)
		throw std::range_error("out of range");

	m_adjacency_list[from].push_back(to);
}

int Graph::GetVerticesCount() const
{
	return m_vertices_count;
}

const vector<int>& Graph::GetVertices(int vertex) const
{
	if (vertex >= m_adjacency_list.size() || vertex < 0)
		throw std::range_error("out of range");

	return m_adjacency_list[vertex];
}

