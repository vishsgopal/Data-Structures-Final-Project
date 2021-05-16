#include <iostream>
#include <vector>
#include <cstring>
#include "graph.h"
#include "prims.h"
#include "landmark.h"
#include "readFromFile.h"

int main(int argc, const char * argv[]) {
	Graph mainGraph;
	Prims mainPrim(mainGraph);
	Landmark mainLP(mainGraph);
	
	// argv[1] is the first argument, so on...
	// No arguments passed, run all three algos at once with default args
	if(argc == 1) {
		mainGraph.dfs();
		mainGraph.printDFS();
		mainPrim.primsMST();
		mainLP.findLandmarkPath();
	}

	// Landmark can have 3 args or no args
	else if(std::strcmp(argv[1], "landmark") == 0) {
		if(argc == 2) {
			mainLP.findLandmarkPath();
		}
		else if(argc != 5) {
			std::cout << "Usage : ./finalproj landmark sourceAirport landmarkAirport destinationAirport" << std::endl;
			return 420; // hehe
		}
		else {
			mainLP.findLandmarkPath(argv[2], argv[3], argv[4]);
		}
	}

	// Prims has no args
	else if(std::strcmp(argv[1], "prims") == 0) {
		if(argc > 2) {
			std::cout << "Usage : ./finalproj prims" << std::endl;
			return 69420; // hehe
		}
		mainPrim.primsMST();
	}

	// DFS can have one arg (source airport) or no args
	else if(std::strcmp(argv[1], "dfs") == 0) {
		if(argc > 3) {
			std::cout << "Usage : ./finalproj dfs [sourceAirport]" << std::endl;
			return 1738; // hehe
		}
		if(argc == 2) {
			mainGraph.dfs();
			mainGraph.printDFS();
		}
		else {
			mainGraph.path.clear();
			mainGraph.visited.clear();
			mainGraph.dfs(argv[2]);
			mainGraph.printDFS();
		}
	}

	// Invalid arguments handler
	else {
		std::cout << "Invalid input. Please follow the instructions in the README and try again." << std::endl;
		return 69; // hehe
	}
	return 0;
}