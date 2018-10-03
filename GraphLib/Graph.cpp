#include "Graph.h"

using std::vector;

Graph::Graph(int vertices) : m_vertices_count(vertices), m_adjacency_list(vertices)
{
	if (vertices < 1)
		throw std::length_error("");
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

bool Graph::CalculateDependencyTree(vector<vector<int>>& dependency_tree) const
{
	dependency_tree.clear();

	vector<int> in_degree(GetVerticesCount(), 0);

	for (int i = 0; i < GetVerticesCount(); i++)
	{
		for (const auto& vertex : GetVertices(i))
		{
			in_degree[vertex]++;
		}
	}

	vector<int> vertices;

	for (int i = 0; i < GetVerticesCount(); i++)
	{
		if (in_degree[i] == 0)
		{
			vertices.push_back(i);
		}
	}

	dependency_tree.push_back(vertices);

	int count = vertices.size();

	if (count == GetVerticesCount())
		return true;

	if (vertices.empty())
		return false;

	while (!vertices.empty())
	{
		vector<int> neighbours;

		for (const auto& u : vertices)
		{
			for (const auto&v : GetVertices(u))
			{
				if (--in_degree[v] == 0)
				{
					neighbours.push_back(v);
					count++;
				}
			}
		}

		vertices = neighbours;
		if (!neighbours.empty())
		{
			dependency_tree.push_back(neighbours);
		}
	}

	if (count != GetVerticesCount())
		return false;

	return true;
}

