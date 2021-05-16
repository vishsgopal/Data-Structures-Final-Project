#pragma once
#include <string>

/** 
 * Parses a CSV file into a 2D vector
 * @param filename The file to read from
 * @return a vector of vectors containing elements from each line from CSV
 */
std::vector<std::vector<std::string>> parse_CSV(const std::string & filename);