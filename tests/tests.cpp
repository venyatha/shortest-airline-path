#include <string>
#include <vector>
#include "../catch/catch.hpp"
#include "../readFromFile.h"


TEST_CASE("Verify that file_to_vector works on a small example") {
	std::vector<std::string> actual = file_to_vector("tests/smallSample.txt");
	// always check "expected" == "actual" --> be consistent

    std::vector<std::string> expected = {"2B,410,AER,2965,KZN,2990,,0,CR2", 
                                        "2B,410,ASF,2966,KZN,2990,,0,CR2", 
                                        "2B,410,ASF,2966,MRV,2962,,0,CR2", 
                                        "2B,410,CEK,2968,KZN,2990,,0,CR2", 
                                        "2B,410,CEK,2968,OVB,4078,,0,CR2", 
                                        "2B,410,DME,4029,KZN,2990,,0,CR2", 
                                        "2B,410,DME,4029,NBC,6969,,0,CR2",
                                        "2B,410,DME,4029,UUA,6160,,0,CR2", 
                                        "2B,410,EGO,6156,KGD,2952,,0,CR2", 
                                        "2I,8359,CUZ,2812,LIM,2789,,0,142", 
                                        "141"};

	REQUIRE(expected == actual);
}

TEST_CASE("Verify that extract_required_info works correctly") {
	std::vector<std::string> vec = file_to_vector("tests/smallSample.txt");
    std::vector<std::string> actual = extract_required_info(vec);
    
	// always check "expected" == "actual" --> be consistent

    std::vector<std::string> expected = {"2B,410,2965,2990,0", 
                                        "2B,410,2966,2990,0", 
                                        "2B,410,2966,2962,0", 
                                        "2B,410,2968,2990,0", 
                                        "2B,410,2968,4078,0", 
                                        "2B,410,4029,2990,0", 
                                        "2B,410,4029,6969,0",
                                        "2B,410,4029,6160,0", 
                                        "2B,410,6156,2952,0", 
                                        "2I,8359,2812,2789,0"};

	REQUIRE(expected == actual);
}