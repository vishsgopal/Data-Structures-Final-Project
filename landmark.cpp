#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <fstream>
#include <limits.h>

#include "landmark.h"

Landmark::Landmark(Graph & g){
    graph = g;
    node_count = g.node_count;
    adj_list = g.adj_list;
}

void Landmark::printLandmarkPath()
{  
    // Open output file for writing (append to file)
    std::ofstream outFile("landmark_output.txt", std::ofstream::out | std::ofstream::app);
    // Print out the landmark path (it writes in reverse so it must be read from bottom to top)
    for(auto airport : landmarkPath) {
        outFile << airport << std::endl;
    }
    outFile << "End of landmark path: destination reached";
    outFile.close();
}

// Returns the closest airport that the current airport has a direct flight to.
std::string Landmark::minDistance(std::map<std::string, double> key, std::map<std::string, bool> sptMap) {
    double min_dist = INT_MAX;
    std::string min_index;

    for(auto v : key) {
        if(v.second < min_dist && sptMap[v.first] == false) {
            min_dist = v.second;
            min_index = v.first;
        }
    }
    return min_index;
}

void Landmark::findLandmarkPath() {
    findLandmarkPath("ORD", "JFK", "CMI"); // source, landmark, and destination
}

void Landmark::findLandmarkPath(std::string source, std::string landmark, std::string destination){
    // Flush out the existing file for overwriting
    std::ofstream outFile("landmark_output.txt");
    outFile << "Generated Landmark Path:" << std::endl;
    outFile.close();
    // Traverse from landmark to destination first because we're pushing to the path vector like a stack
    findLandmarkPathHelper(landmark, destination);
    // Now go from source to landmark using SSSP
    findLandmarkPathHelper(source, landmark);
    // Push the source to the path vector
    landmarkPath.insert(landmarkPath.begin(), source);
    printLandmarkPath();
    std::cout << "Landmark path written to landmark_output.txt" << std::endl;
}

// Basically an adaptation of Dijkstra's SSSP
void Landmark::findLandmarkPathHelper(std::string sourceAirport, std::string destAirport) {
    // Map of distances from source airport, holds shortest distance from source to airport (each airport is a key)
    std::map<std::string, double> dist;
    // Map (shortest-path tree) describing whether or not a certain vertex was visited
    std::map<std::string, bool> sptMap;
    // Parent array used to keep track of the path
    std::map<std::string, std::string> parent;

    //Initialize distances as infinite and sptMap to all false because none of the nodes have been visited yet
    for(auto itr = graph.airports.begin(); itr != graph.airports.end(); ++itr) {
        dist.insert({itr->first, INT_MAX});
        sptMap.insert({itr->first, false});
    }

    // Distance between source and itself is zero
    dist[sourceAirport] = 0;
    // There is no airport that we visit before the starting airport, set to "None"
    parent[sourceAirport] = "None";

    // Run search until we get to our destination
    while(sptMap[destAirport] == false) {
        // Get the airport closest to the current airport and traverse to it
        std::string u = minDistance(dist, sptMap);
        sptMap[u] = true;
        
        // Update the distance of the vertices adjacent to the traversed vertex
        for(auto v : adj_list[u]) {
            // Only update the distance of the adjacent airport if it is not visited already
            if(sptMap[v.first] == false && v.second + dist[u] < dist[v.first]) {
                parent[v.first] = u;
                dist[v.first] = dist[u] + v.second;
            }
        }
    }
    // Parse and add corresponding half of traversal to path
    std::string airport = destAirport;
    while(parent[airport] != "None"){
        landmarkPath.insert(landmarkPath.begin(), airport);
        airport = parent[airport];
    } 
}