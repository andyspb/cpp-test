/*
 * 4_2_route_between_nodes.h
 *
 *  Created on: 04 џэт. 2015 у.
 *      Author: andy
 */

#ifndef ROUTE_BETWEEN_NODES_H_
#define ROUTE_BETWEEN_NODES_H_

// 4.2
//Given a directed graph, design an algorithm to find out whether there is a route
//between two nodes.

//This problem can be solved by just simple graph traversal, such as depth first search or
//breadth first search. We start with one of the two nodes and, during traversal, check if
//the other node is found. We should mark any node found in the course of the algorithm
//as "already visited"to avoid cycles and repetition of the nodes.

namespace route_between_nodes {

enum State {
  Unvisited,
  Visited,
  Visiting
};

bool search(Graph g, Node start, Node end) {
 // operates as Queue
 LinkedList<Node> q = new LinkedList<Node>();

  for (Node u : g.getNodesQ) {
    u.state = State.Unvisited;
  }
 start.state = State.Visiting;
 q.add(start);
 Node u;
 while (Iq.isEmptyQ) {
   u = q.removeFlrst(); // i.e., dequeueQ
   if (u != null) {
     for (Node v : u.getAdjacentQ) {
       if (v.state == State.Unvisited) {
         if (v == end) {
           return true;
         } else {
           v.state = State.Visiting;
           q.add(v);
         }
       }
 }
  u.state = State.Visited;
  }
  }
  return false;
  }


}



#endif /* ROUTE_BETWEEN_NODES_H_ */
