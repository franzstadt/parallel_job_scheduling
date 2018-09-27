#pragma once
#include "Edge.h"
#include <vector>

class Graph
{
	int m_vertices_count;
	std::vector<std::vector<int>> m_adjacency_list;
public:
	Graph(int vertices) : m_vertices_count(vertices), m_adjacency_list(vertices) {}
	void AddEdge(const Edge& edge);
	int GetVerticesCount() const;
	std::vector<int> GetVertices(int vertex) const;
};
