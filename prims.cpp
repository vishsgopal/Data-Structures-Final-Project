#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <fstream>
#include <limits.h>


#include "prims.h"

Prims::Prims(Graph & g){
    graph = g;
    node_count = g.node_count;
    adj_list = g.adj_list;
}
  
// Finds the vertex with the
// minimum key value from the set of vertices  
// not yet in the MST
std::string Prims::minKey(std::map<std::string, double> key){  
    // Initialize min value and min node
    double min_dist = INT_MAX;
    std::string min_index;

    // if the distance is less than the min dist, update min index and min dist
    for (auto v : key){
        if (v.second < min_dist){
            min_index = v.first;
            min_dist = v.second;
        }
    }

    // return min dist
    return min_index;  
}  
  
// A function to print the  
// constructed MST stored in parent map
void Prims::printMST(std::map<std::string, std::string> parent)  
{  
    // Open output file for writing
    std::ofstream outFile("primsMST_output.txt");
    outFile << "Edge \tWeight\n" << std::endl;
    // Print out all edges and weights in the MST
    for(auto airport : adj_list){
        if(parent[airport.first] != "")
            outFile << parent[airport.first] << " - " << airport.first << " \t" << (adj_list[airport.first])[parent[airport.first]] << " \n";
    }
    outFile.close();
    std::cout << "Prim's MST written to primsMST_output.txt" << std::endl;
}
  
// A function to construct and print the MST for  
// a graph represented using our adj_list data
// structure
void Prims::primsMST()  
{  
    // Map that maps a node to its parent in the MST
    std::map<std::string, std::string> parent;
      
    // Map that maps a node to its minimum weight edge while traversing MST
    std::map<std::string, double> key;
      
    // Represents the visited state of nodes in the MST
    std::map<std::string, bool> mstSet;

    // Initilize mstSet to false
    for(auto itr = adj_list.begin(); itr != adj_list.end(); ++itr) {
        mstSet.insert({itr->first, false});
    }

    // Initialize all keys as INFINITE 

    // for (int i = 0; i < V; i++){ 
    //     key[i] = INT_MAX, mstSet[i] = false;  
    // }
  
    // Make the key 0 so that this vertex is picked as the first vertex
    key["AER"] = 0;
    // Make the parent of the first airport an ignore statement since it has no parent
    parent["AER"] = "(Ignore Parent of First Airport)"; // First node is always root of MST
  
    // Start going through the nodes in the MST
    for (int count = 0; count < node_count - 1; count++) 
    {  
        // Pick the vertex with the minimum key from the  
        // set of vertices not yet included in MST  
        std::string u = minKey(key);  
  
        // Add the picked vertex to the MST Set
        mstSet[u] = true;  
        
        // Update key value and parent index of  
        // the adjacent vertices not yet included
        // in the MST of the picked vertex.  
        for (auto v : adj_list[u]){

            // If the key data structure does not have the node connected to u
            // and it is unvisited, insert the new node into key with its value
            // as INT_MAX
            if(key.find(v.first) == key.end() && mstSet[v.first] == false) {
                key.insert({v.first, INT_MAX});
            }

            // If the new node is unvisited and the new node's weight with u plus
            // the weight of u in key is less than the weight of the new node in
            // key, update the parent of the new node to v and the new minimum
            // weight in key appropriately.
            // Update the key only if graph[u][v] is smaller than key[v]
            if (mstSet[v.first] == false && v.second + key[u] < key[v.first]){
                parent[v.first] = u;
                key[v.first] = v.second + key[u];  
            }
        }
        // Eliminate u from the key since it is not needed anymore  
        key.erase(u);
    }  
  
    // print the constructed MST  
    printMST(parent);  
}