#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

#include "readFromFile.h"

std::vector<std::vector<std::string>> parse_CSV(const std::string & filename) {
	// Create file stream and return vector
	std::ifstream fileStream(filename);
	std::string currLine;
	std::vector<std::vector<std::string>> out;

	// Read line by line from file stream (assumes CSV) and place each token into inner vector, then push into output
	if (fileStream.is_open()) {
		while (std::getline(fileStream, currLine)) {
			std::istringstream currLineStream(currLine);
			std::string elem;
			std::vector<std::string> lineVec;
			while (std::getline(currLineStream, elem, ',')) {
				lineVec.push_back(elem);
			}
			out.push_back(lineVec);
		}
	}
	fileStream.close();
	return out;
}