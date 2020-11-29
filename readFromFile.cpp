#include "readFromFile.h"
#include <fstream>
#include <sstream>

vector<string> file_to_vector(const string& filename) {
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

vector<string> extract_required_info(const vector<string> vec) {
    //airline, airline id, source airport id, destination airport id, stops
    vector<string> toReturn;
    for (auto line : vec) {
        stringstream ss(line);
        vector<string> vec_line;
        
        while (ss.good()) {
            string substring;
            getline(ss, substring, ',');
            vec_line.push_back(substring);

            if (vec_line.size() == 8) {
                string info = vec_line[0] + "," + vec_line[1] + "," + vec_line[3] + "," 
                        + vec_line[5] + "," + vec_line[7];
                toReturn.push_back(info);
            } else {
                continue;
            }
        }
    }
    return toReturn;

}