#include <iostream>
#include <vector>
#include "readFromFile.h"
#include <string>
using namespace std;

int main() {
    
    //print vector
    vector<string> vec = file_to_vector("data.txt");
    vector<string> req = extract_required_info(vec);
	for (auto word : req) {
		cout << word << endl;
	}

    return 0;

}