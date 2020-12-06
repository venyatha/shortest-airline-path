#include "Dijkstra.h"
#include <sstream>

using namespace std;

Dijkstra::Dijkstra(Vertex* start, vector<string*> all_data) : g_(true, true) {
    start_ = *start;
    for (unsigned i = 0; i < all_data.size(); i++) { 
        // split string by space
        vector<string> vec;
        stringstream ss(*all_data[i]);

        while( ss.good() ) {
            string substr;
            getline( ss, substr, ',' );
            vec.push_back(substr);
        } 

        /*for (auto v : vec) {
            cout << v << endl;
        }*/

        if (!g_.vertexExists(vec[0])) {
            g_.insertVertex(vec[0]);
        }
        if (!g_.vertexExists(vec[2])) {
            g_.insertVertex(vec[2]);
        }
        if (!g_.edgeExists(vec[0], vec[2])) {
            g_.insertEdge(vec[0], vec[2]);
            g_.setEdgeWeight(vec[0], vec[2], INT_MAX);
        }
        if (g_.getEdgeWeight(vec[0], vec[2]) > stoi(vec[1])) {
            g_.setEdgeWeight(vec[0], vec[2], stoi(vec[1]));
        }
    }
}

const Graph & Dijkstra::getGraph() const {
  return g_;
}