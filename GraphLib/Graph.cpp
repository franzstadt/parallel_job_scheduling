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

const vector<int>& Graph::GetSuccessors(int vertex) const
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
		for (int vertex : GetSuccessors(i))
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

	int count = vertices.size();

	while (!vertices.empty())
	{
		dependency_tree.push_back(vertices);
		vector<int> neighbours;

		for (int u : vertices)
		{
			for (int v : GetSuccessors(u))
			{
				if (--in_degree[v] == 0)
				{
					neighbours.push_back(v);
					count++;
				}
			}
		}

		vertices.swap(neighbours);
	}

	return count == GetVerticesCount();
}

