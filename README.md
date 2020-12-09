# suded2-vmanne3-violaz2-lucianat

## CS225 Final Project: Openflights Dijkstra's Algorithm 

The purpose of our program is to find the shortest airplane paths between two cities, possibly with a stop in 
between. We got our data from https://openflights.org/data.html, where we used the routes database. Instead of
using all of the data, we decided to use a smaller sample. By using an accurate smaller sample size, we are assuming this implementation will work with all cities. This project is very useful in the real world, as it is very important for airlines to use the shortest path possible between two ciites.

## Motivation

For this project, we needed to use graphs somehow, and flights can be easily and logcially represented with graphs. Because of this, we decided to use the OpenFlights dataset. We used Dijktra's algorithm to implement a sohrtest path algorirthm and a landmark path algorithm, which are both useful in real life.

## Installation

Simply download the project from github and run `make` in the folder on the command line to build the project

## How to use? 

Once the project is downloaded and built, you can run `./finalproj`. This will prompt you to input whether you would like to run shortest path or landmark path
- Shortest path will give you the shortest path between two airports
- Landmark path will give you the shortest path betweeen two aiports with a stop in the middle at a 
particular airport

Please input either `shortest path` or `landmark path`

Next, the program will prompt you to input source, destination, and if you are running landmark path, stop airports. Please input the IATA 3-letter codes for the airports you would like to use.

Once these are all inputted, the program wil run and output put the particular sequence of airports your flight will take or notify you that no route between the airports you inputted is possible.

## Tests

To run the tests, you can run `make test` and then `./test` on the command line.

## Credits

Sude Demir - suded2@illlinois.edu <br />
Venyatha Manne - vmanne3@illinois.edu <br />
Luciana Toledo-Lopez - lucianat@illinois.edu <br />
Viola Zhao - violaz2@illinois.edu