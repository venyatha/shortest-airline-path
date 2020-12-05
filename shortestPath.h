#pragma once
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Graph {
    public:
        Graph();
        ~Graph();
        Graph(map<string, int>* city_ids, vector<vector<string>>* all_data);
        vector<vector<int>>* getGraph();
        
        
        //void shortestPath(int data[][], int start);

    private:
        vector<vector<int>>* g;
};