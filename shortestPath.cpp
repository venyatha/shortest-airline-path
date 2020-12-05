#include "shortestPath.h"
#include <iostream>

Graph::Graph() {}

Graph::Graph(map<string, int>* city_ids, vector<vector<string>>* all_data) {
    int n = city_ids->size();
    // initialize everything in the adjacency matrix to -1, 
    // indicating no edges between airport nodes yet
    
    g = new vector<vector<int>>(n, vector<int>(n, -1));
    int dist;
    for (unsigned i = 0; i < all_data->size(); i++) {
        string str_dist = (*all_data)[i][4];
        dist = stoi(str_dist); 

        int a = city_ids->operator[]((*all_data)[i][2]);
        int b = city_ids->operator[]((*all_data)[i][3]);

        int val = (*g)[a][b];
        std::cout << "val:" << val << " dist:" << dist << std::endl;
        if (val == -1 || val > dist) { 
            (*g)[a][b] = dist;
        }
    }
}

Graph::~Graph() {
    delete g;
}

vector<vector<int>>* Graph::getGraph() {
    return g;
}


