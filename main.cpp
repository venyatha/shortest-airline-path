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
    Graph g(city_ids, all_data);
    std::vector<std::vector<int>>* actual = g.getGraph();
    std::cout << "done" << std::endl;
    

	//for (auto word : req) {
	//	cout << word << endl;
	//}

    return 0;

}