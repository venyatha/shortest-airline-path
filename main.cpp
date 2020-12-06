#include <iostream>
#include <vector>
#include <string>

#include "readFromFile.h"
#include "Dijkstra.h"

using namespace std;

int main() {
    vector<string> vec = file_to_vector("routes.txt");
    
    vector<string*> all_data = extract_required_info(vec);

    for (auto word : all_data) {
        cout << *word << endl;
    }

    string* aer = new string("AER");
    Dijkstra d(aer, all_data);
    d.getGraph().print();

    return 0;
}