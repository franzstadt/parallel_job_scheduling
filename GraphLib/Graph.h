#pragma once
#include <vector>

class Graph
{
	int m_vertices_count;
	std::vector<std::vector<int>> m_adjacency_list;
public:
	Graph(int vertices);
	void AddEdge(int from, int to);
	int GetVerticesCount() const;
	const std::vector<int>& GetSuccessors(int vertex) const;
	//Calculates the dependency tree of a computational Graph. 
	//The function checks of DAG property also. 
	//It returns with false if a cycle is detected.
	bool CalculateDependencyTree(std::vector<std::vector<int>>& dependency_tree) const;
};
