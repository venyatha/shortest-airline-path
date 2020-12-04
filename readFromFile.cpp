#include "readFromFile.h"
#include <fstream>
#include <sstream>


vector<string> Data::file_to_vector(const string& filename) {
    ifstream text(filename);
    string line;
    vector<string> out;
    if (text.is_open()) {
        istream_iterator<string> iter(text);

        while (!text.eof()) {
            out.push_back(*iter);
            ++iter;
        }
    }
    return out;
}

Data::Data(){}

Data::Data(const string& filename) {
    extract_required_info(file_to_vector(filename));
}

void Data::extract_required_info(const vector<string> vec) {
    //airline, airline id, source airport id, destination airport id, stops
    for (auto line : vec) {
        stringstream ss(line);
        vector<string> vec_line;
        
        while (ss.good()) {
            string substring;
            getline(ss, substring, ',');
            vec_line.push_back(substring);

            if (vec_line.size() == 8) {
                //string info = vec_line[0] + "," + vec_line[1] + "," + vec_line[3] + "," 
                //        + vec_line[5] + "," + vec_line[7];            
                // 0 = airline code, 1 = airline id, 3 = source airport id, 
                // 5 = destination airport id, 7 = stops
                vector<string> info = {vec_line[0], vec_line[1],vec_line[3], vec_line[5], vec_line[7]};
                all_data.push_back(info);
                //push into airport id vec if unique id
                if (ids.size() == 0) {
                    ids.push_back(vec_line[3]);
                    city_ids[vec_line[3]] = ids.size() - 1;
                } else if (ids[ids.size() - 1] != vec_line[3]) {
                    ids.push_back(vec_line[3]);
                    city_ids[vec_line[3]] = ids.size() - 1;
                }
            } else {
                continue;
            }
        }
    }
}

vector<string> Data::getIds() {
    return ids;
}

vector<vector<string>> Data::getAll() {
    return all_data;
}

map<string, int> Data::getCityIds() {
    return city_ids;
}