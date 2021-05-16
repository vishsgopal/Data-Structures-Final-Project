#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <set>


class Graph{
    public:
      // Public Graph constructor 
      Graph();
      // DFS traveral function
      void dfs();
      // DFS traversal function starting at source_airport
      void dfs(std::string source_airport);
      // Writes the DFS traversal to a file
      void printDFS();
      std::set<std::string> visited;
      std::vector<std::string> path;
      int node_count;
      std::map<std::string, std::vector<std::string>> airports;
      std::vector<std::vector<std::string>> airports_temp;
      std::vector<std::vector<std::string>> routes;
      std::map<std::string, std::map<std::string, double>> adj_list;
};

// Haversine formula used to find great-circle distance that will be used as edge weights 
long double distance(long double lat1, long double long1, long double lat2, long double long2);
// Converts degrees of longitude or latitude to radians for use in the Haversine formula
long double deg2rad(long double degree);
