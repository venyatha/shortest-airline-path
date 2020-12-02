#include "shortestPath.h"
using namespace std;

Graph::Graph(vector<string> ids, vector<string> all_info) {
    int n = ids.size();
    // initialize everything in the adjacency matrix to -1, indicating no edges between airport nodes yet
    vector<vector<int>> vec( n, vector<int> (n, -1));
    g = vec;
}