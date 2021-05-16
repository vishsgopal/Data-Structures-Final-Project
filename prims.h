#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>

#include "graph.h"

class Prims{
    public:
        Prims(Graph & g);
        void primsMST();
        void printMST(std::map<std::string, std::string> parent);
        std::string minKey(std::map<std::string, double> key);
        Graph graph;
        std::map<std::string, std::map<std::string, double>> adj_list;
        int node_count;
};