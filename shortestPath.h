#pragma once
using namespace std;
#include <vector>;
#include <string>;

class Graph {
    public:
        Graph(vector<string> nodes, vector<string> all_info);
        
        //void shortestPath(int data[][], int start);

    private:
        vector<vector<int>> g;
        
    
};





