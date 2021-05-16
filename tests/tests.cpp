#include <string>
#include <vector>

#include "catch/catch.hpp"
#include "../readFromFile.h"
#include "../graph.h"
#include "../prims.h"


TEST_CASE("parse_CSV correctly parses a small sample") {
	std::vector<std::vector<std::string>> res = parse_CSV("tests/testParse.csv");
	std::vector<std::vector<std::string>> expected;
	expected.push_back({"akshayb3","1"});
	expected.push_back({"fmoy3","2"});
	expected.push_back({"vg12","3"});
	
	REQUIRE(3 == res.size());

	for (int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			REQUIRE(expected[i][j] == res[i][j]);
		}
	}
}

TEST_CASE("Graph DFS traversal visits all points in small graph") {

}
