#include <iostream>
#include <vector>
#include "readFromFile.h"
#include "shortestPath.h"
#include <string>
using namespace std;

int main() {
    
    //print vector
    Data d;
    vector<string> vec = d.file_to_vector("data.txt");
    d.extract_required_info(vec);
	//for (auto word : req) {
	//	cout << word << endl;
	//}

    return 0;

}