#include <iostream>
#include <vector>
#include "readFromFile.h"
#include <string>
#include "Dijkstra.h"
using namespace std;

int main() {
    
    //print vector

    vector<string> vec = file_to_vector("routes.txt");
    
    vector<string*> all_data = extract_required_info(vec);

    for (auto word : all_data) {
        cout << *word << endl;
    }

    string* dme = new string("DME");
    Dijkstra d(dme, all_data);
    d.getGraph().print();
    //delete all_data

    return 0;

}