#pragma once

#include <vector>
#include <algorithm>

#include "graph.h"
#include "edge.h"


class Dijkstra {
    public:
        Dijkstra(Vertex* start, vector<string*> all_data);
        void print_path(Vertex dest);
        const Graph & getGraph() const;

        

    private:
        Graph g_;
        Vertex start_;

};