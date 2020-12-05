#include <iostream>
#include <vector>
#include "readFromFile.h"
#include "shortestPath.h"
#include <string>
using namespace std;

int main() {
    
    //print vector
    Data d;
    vector<string> vec = d.file_to_vector("tests/smallSample.txt");
    d.extract_required_info(vec);
    
    vector<vector<string>>* all_data = d.getAll();
    map<std::string, int>* city_ids = d.getCityIds();
    vector<string> ids = d.getIds();
    /*for (auto it = city_ids->begin(); it != city_ids->end(); it++) {
        cout << "city: " << it->first << " " << it->second << endl;
    }
    for (unsigned i = 0; i < all_data->size(); i++) {
        for (unsigned j = 0; j < 5; j++) {
            cout << "all: " << (*all_data)[i][j] << " ";
        }
        cout << endl;
    }*/
    Graph g(city_ids, ids, all_data);
    std::vector<std::vector<int>>* actual = g.getGraph();
    std::cout << "done" << std::endl;
    

	//for (auto word : req) {
	//	cout << word << endl;
	//}

    return 0;

}