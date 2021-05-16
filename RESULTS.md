# Project Outcome

The DFS utilized our graph implementation to traverse the data set and map the airports based on their flight paths. However, in this traversal we realized that there were parts of the graph that were disconnected. Our prims algorithm constructs a prims MST based on the weights calculated from the longitude and latitude for the airports. Some flight paths within the dataset were directional. A flight path existed from Airport A to B, but not B to A. For the purposes of this project, we had to make it undirected. Another shortcoming in the MST is that there were a few airports in the dataset that operated only as a cluster. Flight paths existed from airports within the cluster, but not anywhere else outside. These clusters are discussed more in depth below. While the landmark path algorithm accurately accounted for weights as we designed it and gave the respective flight path accordingly, the feasibility of the results in real life is rather questionable. For example, when running the landmark path algorithm on three airports, the output path rests solely on the weights(distances). It outputs the path that visits the landmark from the source and reaches the destination with the least distance travelled. In real life it is much more complex than that given the fuel capacity, weather patterns, airport traffic and numerous other logistics. It could be sometimes more beneficial, both for the airline and the passenger to go the extra distance and land at another airport than change planes in between 2-3 times.

## Interesting observations about the dataset

* By running our Prim's MST algorithm on the OpenFlights dataset, we were able to see discontinuities in the graph by seeing which edges in the MST connected to nothing. We then ran these airports into our DFS to find the other airports in each cluster of discontinuities. There are 26 airports in total that are disconnected. These involve the following locations:
  * The islands of New Caledonia: NOU airport only handles international flights and doesn't have flights to the domestic airports of New Caledonia.
    * Run a DFS on airport TOU to see all of 10 these airports. 
  * Alaska, U.S.A.: A cluster of small airports in the state of Alaska do not have flights that go to other states.
    * These airports are AKB, DUT, IKO, and KQA.
  * Washington, U.S.A.: A cluster of small airports in the state of Washington do not have flights that go to other states.
    * These airports are BFI, CLM, ESD, FRD
  * Greenland: Airports CNP and OBY are domestic airports that only travel between each other.
  * British Columbia, Canada: CXH and YWH airports are actually sea ports that only have flights between each other according to the dataset.
  * Namibia: A cluster of airports in Namibia only travel between each other.
    * These airports are ERS, MPA, NDU, OND