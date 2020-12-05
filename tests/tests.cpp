#include <string>
#include <vector>
#include "../catch/catch.hpp"
#include "../readFromFile.h"
#include <map>
#include <iostream>
#include "../shortestPath.h"


TEST_CASE("Verify that file_to_vector works on a small example") {
	Data d;
    
    std::vector<std::string> actual = d.file_to_vector("tests/smallSample.txt");
	// always check "expected" == "actual" --> be consistent

    std::vector<std::string> expected = {"2B,410,AER,2965,KZN,2966,,3,CR2",
                                        "2B,410,AER,2965,KZN,2966,,1,CR2",  
                                        "2B,410,ASF,2966,KZN,2965,,0,CR2", 
                                        "2B,410,ASF,2966,MRV,2965,,0,CR2", 
                                        "2B,410,CEK,2968,KZN,4029,,0,CR2", 
                                        "2B,410,CEK,2968,OVB,4029,,0,CR2", 
                                        "2B,410,DME,4029,KZN,2812,,0,CR2", 
                                        "2B,410,DME,4029,NBC,6156,,0,CR2",
                                        "2B,410,DME,4029,UUA,6156,,0,CR2", 
                                        "2B,410,EGO,6156,KGD,2812,,1,CR2", 
                                        "2I,8359,CUZ,2812,LIM,4029,,0,142", 
                                        "141"};

	REQUIRE(expected == actual);
}

TEST_CASE("Verify that extract_required_info works correctly") {
	Data d;
    std::vector<std::string> vec = d.file_to_vector("tests/smallSample.txt");
    d.extract_required_info(vec);
    std::vector<std::vector<std::string>>* actual = d.getAll();
    
	// always check "expected" == "actual" --> be consistent
    

    std::vector<std::vector<std::string>> expected = {{"2B","410","2965","2966","3"},
                                                    {"2B","410","2965","2966","1"}, 
                                                    {"2B","410","2966","2965","0"}, 
                                                    {"2B","410","2966","2965","0"}, 
                                                    {"2B","410","2968","4029","0"}, 
                                                    {"2B","410","2968","4029","0"}, 
                                                    {"2B","410","4029","2812","0"}, 
                                                    {"2B","410","4029","6156","0"},
                                                    {"2B","410","4029","6156","0"}, 
                                                    {"2B","410","6156","2812","1"}, 
                                                    {"2I","8359","2812","4029","0"}};

	REQUIRE(expected == *actual);
}

TEST_CASE("Verify that ids are unique") {
	Data d;
    std::vector<std::string> vec = d.file_to_vector("tests/smallSample.txt");
    d.extract_required_info(vec);
    std::vector<std::string> actual = d.getIds();
    
	// always check "expected" == "actual" --> be consistent

    std::vector<std::string> expected = {"2965","2966", "2968", "4029", "6156", "2812"};

	
    REQUIRE(expected == actual);
}


TEST_CASE("Verify that adjacency matrix is set up correctly") {
	Data d;
    std::vector<std::string> vec = d.file_to_vector("tests/smallSample.txt");
    d.extract_required_info(vec);
    std::vector<std::vector<std::string>>* all_data = d.getAll();
    map<std::string, int>* city_ids = d.getCityIds();
    for (const auto& elem : *city_ids) {
        std::cout << elem.first << " " << elem.second << std::endl;
    }
    
    Graph g(city_ids, all_data);
    std::vector<std::vector<int>>* actual = g.getGraph();
    

    std::vector<std::vector<int>> expected = {{-1, 1, -1, -1, -1, -1},
                {0, -1, -1, -1, -1, -1},
                {-1, -1, -1, 0, -1, -1},
                {-1, -1, -1, -1, 0, 0},
                {-1, -1, -1, -1, -1, 1},
                {-1, -1, -1, 0, -1, -1}};

	
    REQUIRE(expected == *actual);
}

