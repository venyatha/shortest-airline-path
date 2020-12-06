#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;


/** reads from data.txt, moves data t ostring vector**/
vector<string> file_to_vector(const string& filename);

/**
 * this fucntion extracts the airline, airline id, destination airpot id, 
 * origin airport id, number of stops **/
vector<string*> extract_required_info(const vector<string> vec);

