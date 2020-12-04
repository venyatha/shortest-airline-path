#include "shortestPath.h"

Graph::Graph() {}

Graph::Graph(map<string, int> city_ids, vector<vector<string>> all_data) {
    int n = city_ids.size();
    // initialize everything in the adjacency matrix to -1, 
    // indicating no edges between airport nodes yet
    vector<vector<int>> vec(n, vector<int>(n, -1));
    g = vec;
    int dist;
    for (unsigned i = 0; i < all_data.size(); i++) {
        string str_dist = all_data[i][4];
        dist = stoi(str_dist);      
        if (g[city_ids[all_data[i][2]]][city_ids[all_data[i][3]]] == -1 ||
            g[city_ids[all_data[i][2]]][city_ids[all_data[i][3]]] > dist) { 
            g[city_ids[all_data[i][2]]][city_ids[all_data[i][3]]] = dist;
        }
    }
}

vector<vector<int>> Graph::getGraph() {
    return g;
}


