#include <string>
#include <vector>
#include <iostream>

#include "../catch/catch.hpp"
#include "../readFromFile.h"
#include "../Dijkstra.h"
#include "../graph.h"
#include "../edge.h"

using namespace std;

TEST_CASE("Verify that file_to_vector works on a small example") {
	vector<string> actual = file_to_vector("tests/smallSample.txt");

    vector<string> expected = {"2B,410,AER,2965,KZN,2966,,3,CR2",
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
	vector<string> vec = file_to_vector("tests/smallSample.txt");
    vector<string*> actual = extract_required_info(vec);

    vector<string> expected = {"AER,3,KZN",
                                "AER,1,KZN",
                                "ASF,0,KZN",
                                "ASF,0,MRV",
                                "CEK,0,KZN",
                                "CEK,0,OVB",
                                "DME,0,KZN",
                                "DME,0,NBC",
                                "DME,0,UUA",
                                "EGO,1,KGD",
                                "CUZ,0,LIM"};

    for (unsigned i = 0; i < expected.size(); i++) {
        REQUIRE(expected[i] == *actual[i]);
    }
}

TEST_CASE("Dijkstra(start, all_data) constructor creates the correct vertices") {
    vector<string> vec = file_to_vector("tests/smallSample.txt");
    vector<string*> all_data = extract_required_info(vec);
    string* aer = new string("AER");
    Dijkstra d(aer, all_data);
    const Graph & g = d.getGraph();

    REQUIRE(g.vertexExists("AER"));
    REQUIRE(g.vertexExists("KZN"));
    REQUIRE(g.vertexExists("ASF"));
    REQUIRE(g.vertexExists("MRV"));
    REQUIRE(g.vertexExists("CEK"));
    REQUIRE(g.vertexExists("OVB"));
    REQUIRE(g.vertexExists("DME"));
    REQUIRE(g.vertexExists("NBC"));
    REQUIRE(g.vertexExists("UUA"));
    REQUIRE(g.vertexExists("EGO"));
    REQUIRE(g.vertexExists("KGD"));
    REQUIRE(g.vertexExists("CUZ"));
    REQUIRE(g.vertexExists("LIM"));
}

TEST_CASE("Dijkstra(start, all_data) constructor creates the correct edges") {
    vector<string> vec = file_to_vector("tests/smallSample.txt");
    vector<string*> all_data = extract_required_info(vec);
    string* aer = new string("AER");
    Dijkstra d(aer, all_data);
    const Graph & g = d.getGraph();

    REQUIRE(g.edgeExists("AER", "KZN"));
    REQUIRE(g.edgeExists("ASF", "KZN"));
    REQUIRE(g.edgeExists("ASF", "MRV"));
    REQUIRE(g.edgeExists("CEK", "KZN"));
    REQUIRE(g.edgeExists("CEK", "OVB"));
    REQUIRE(g.edgeExists("DME", "KZN"));
    REQUIRE(g.edgeExists("DME", "NBC"));
    REQUIRE(g.edgeExists("DME", "UUA"));
    REQUIRE(g.edgeExists("EGO", "KGD"));
    REQUIRE(g.edgeExists("CUZ", "LIM"));
}