/*
 * graph.h
 *
 *  Created on: 25 ���. 2015 �.
 *      Author: andy
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <list>
#include <queue>
#include <iostream>

namespace graph {
// This class represents a directed graph using adjacency list representation
class Graph {
  int V;    // No. of vertices
  std::list<int> *adj;    // Pointer to an array containing adjacency lists
  void DFSUtil(int v, bool visited[]);  // A function used by DFS
 public:
  Graph(int V);  // Constructor
  virtual ~Graph();  // Constructor
  void addEdge(int v, int w);  // function to add an edge to graph
  void BFS(int s);  // prints BFS traversal from a given source s
  void DFS(int v);    // DFS traversal of the vertices reachable from v
};

Graph::Graph(int V) {
  this->V = V;
  adj = new std::list<int>[V];
}

Graph::~Graph() {
  delete adj;
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);  // Add w to v�s list.
}

void Graph::BFS(int s) {
  // Mark all the vertices as not visited
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  // Create a queue for BFS
  std::list<int> queue;

  // Mark the current node as visited and enqueue it
  visited[s] = true;
  queue.push_back(s);

  // 'i' will be used to get all adjacent vertices of a vertex
  std::list<int>::iterator i;

  while (!queue.empty()) {
    // Dequeue a vertex from queue and print it
    s = queue.front();
    std::cout << s << " ";
    queue.pop_front();

    // Get all adjacent vertices of the dequeued vertex s
    // If a adjacent has not been visited, then mark it visited
    // and enqueue it
    for (i = adj[s].begin(); i != adj[s].end(); ++i) {
      if (!visited[*i]) {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

void Graph::DFSUtil(int v, bool visited[]) {
  // Mark the current node as visited and print it
  visited[v] = true;
  std::cout << v << " ";

  // Recur for all the vertices adjacent to this vertex
  std::list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
      DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void Graph::DFS(int v) {
  // Mark all the vertices as not visited
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  // Call the recursive helper function to print DFS traversal
  DFSUtil(v, visited);
}

}    // namespace graph

#endif /* GRAPH_H_ */
