#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "graph.h"

class Landmark{
    public:
        Landmark(Graph & g);
        Graph graph;
        int node_count;
        std::map<std::string, std::map<std::string, double>> adj_list;
        void findLandmarkPath();
        void findLandmarkPathHelper(std::string sourceAirport, std::string destAirport);
        void printLandmarkPath();
        void findLandmarkPath(std::string source, std::string landmark, std::string destination);
        std::string minDistance(std::map<std::string, double> key, std::map<std::string, bool> sptSet);
        std::vector<std::string> landmarkPath;
};