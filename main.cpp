#include <iostream>
#include <vector>
#include <string>

#include "readFromFile.h"
#include "Dijkstra.h"

using namespace std;

int main() {
    vector<string> vec = file_to_vector("tests/smallSample.txt");
    
    vector<string*> all_data = extract_required_info(vec);

    /*for (auto word : all_data) {
        cout << *word << endl;
    }*/

    Dijkstra d(all_data);

    //d.getGraph().print();
    
    vector<Vertex> sol = d.shortestPath("CEK", "KZN");
    string s = d.printPath(sol, "CEK", "KZN");
    cout << s << endl;

    vector<Vertex> dne = d.shortestPath("AER", "LIM");
    string r = d.printPath(dne, "AER", "LIM");
    cout << r << endl;

    return 0;
}