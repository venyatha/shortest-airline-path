#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;


class Data {

    private:
        //0 -> airline code
        //1 -> airline id
        //2 -> source airport id
        //3 -> destination airport id
        //4 -> number of stops
        vector<vector<string>>* all_data;
        vector<string> ids;
        map<string, int>* city_ids;

    public:
        Data();
        ~Data();
        Data(const string& filename);


        /** reads from data.txt, moves data t ostring vector**/
        vector<string> file_to_vector(const string& filename);

        /**
         * this fucntion extracts the airline, airline id, destination airpot id, 
         * origin airport id, number of stops **/
        void extract_required_info(const vector<string> vec);

        vector<string> getIds();
        vector<vector<string>>* getAll();
        map<string, int>* getCityIds();
};
