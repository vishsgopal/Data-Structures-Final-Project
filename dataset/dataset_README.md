# OpenFlights dataset

airports.dat and routes.dat were provided by OpenFlights (https://openflights.org/data.html). routes_simplified.dat was created by trimming unneeded data from routes.dat, such as airline, equipment, and codeshare information, and removing duplicate routes after the aforementioned data was trimmed. airports_simplified.csv retains only the IATA airport code, latitude, and longitude information.  
* airports_simplified.csv:
  * Formatting: Airport,Latitude,Longitude
  * Airports whose IATA codes were reported as NULL ("\N") were not included in airports_simplified
    * This can lead to discontinuities in the graph data structure.
* routes_simplified.csv:
  * Formatting: SourceAirport,DestinationAirport,numberOfStopsAlongRoute
  * routes_simplified is guaranteed to contain only unique routes
  * routes that contain an IATA code not in airports_simplified.csv are ignored
* This project only reads in routes_simplified.csv and airports_simplified.csv