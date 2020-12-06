#pragma once

#include <vector>
#include <sstream>
#include <algorithm>

#include "graph.h"
#include "edge.h"

class Dijkstra {
    public:
        /**
         * Constructor to create a graph with the airports as the vertices, the routes as
         * the edges, and the shortest path as the edge weights.
         * 
         * @param start The starting vertex
         * @param all_data All of the data needed to form the vertices, edges, and edge weights of the graph
         */
        Dijkstra(Vertex* start, vector<string*> all_data);

        /**
         * Returns a constant reference to the state space graph.
         * 
         * @returns A constant reference to the state space graph.
         */
        const Graph & getGraph() const;

    private:
        Graph g_;
        Vertex start_;
};