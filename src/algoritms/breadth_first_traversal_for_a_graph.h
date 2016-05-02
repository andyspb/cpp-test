/*
 * breadth_first_traversal_for_a_graph.h
 *
 *  Created on: Apr 29, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_BREADTH_FIRST_TRAVERSAL_FOR_A_GRAPH_H_
#define SRC_ALGORITMS_BREADTH_FIRST_TRAVERSAL_FOR_A_GRAPH_H_

#include <iostream>
#include <list>

namespace breadth_first_traversal_for_a_graph {

class Graph {
  int V;    // No. of vertices
  std::list<int> *adj;    // Pointer to an array containing adjacency lists
 public:
  Graph(int V);  // Constructor
  ~Graph();  // Constructor
  void addEdge(int v, int w);  // function to add an edge to graph
  void BFS(int s);  // prints BFS traversal from a given source s
};

Graph::Graph(int V) {
  this->V = V;
  adj = new std::list<int> [V];
}

Graph::~Graph() {
  this->V = V;
  delete adj;
}

void Graph::BFS(int s) {
  // Mark all the vertices as not visited
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  // Create a queue for BFS
  list<int> queue;

  // Mark the current node as visited and enqueue it
  visited[s] = true;
  queue.push_back(s);

  // 'i' will be used to get all adjacent vertices of a vertex
  list<int>::iterator i;

  while (!queue.empty()) {
    // Dequeue a vertex from queue and print it
    s = queue.front();
    cout << s << " ";
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

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);  // Add w to v’s list.
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  std::cout
      << "Following is Breadth First Traversal (starting from vertex 2) \n";
  g.BFS(2);

  RETURN_OK();
}

}  // namespace breadth_first_traversal_for_a_graph

#endif /* SRC_ALGORITMS_BREADTH_FIRST_TRAVERSAL_FOR_A_GRAPH_H_ */
