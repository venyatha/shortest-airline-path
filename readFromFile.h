#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


class Data {

    private:
    vector<string> all_data;
    vector<string> ids;

    public:
    Data();
    Data(const string& filename);


    /** reads from data.txt, moves data t ostring vector**/
    vector<string> file_to_vector(const string& filename);

    /**
     * this fucntion extracts the airline, airline id, destination airpot id, 
     * origin airport id, number of stops **/
    void extract_required_info(const vector<string> vec);

    vector<string> getIds();
    vector<string> getAll();
};
