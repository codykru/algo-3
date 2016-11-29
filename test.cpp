///////////////////////////////////////////////////////////
//         Cody Krukauskas                               //
//                 Analysis of Algorithms								 //
//         Project 3 - 3D Maze 													 //
///////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <queue>


using namespace std;


struct vertex {
	string value; 				//the binary we are dealing with (6 bits: N E S W U D )
	bool discovered;
	int i, j, k;					//level, col, row
};


void findExit(string value, int i, int j, int k){
	//while we don't have the neighbors
	//get front of Queue, throw it away?
	//use findNeighbors. // make sure they aren't visitied
}

//void findNeighbors( vertex * map, queue<vertex> Q, vertex * v, int i, int j, int k){
void findNeighbors(queue<vertex> Q){
	int i, j, k;
	//really want to be passing, Queue, map, start pos, end and returning the path.

//	while(!Q.empty()){
		vertex cur = Q.front();
		string value = cur.value;
		//need to mark first as visited in map...
		Q.pop();
		i = cur.i; j = cur.j; k = cur.k;
		cout << "current position: (" << i << ", " << j << ", " << k << ")" << endl;
		cout << "we can go: ";



	if(value[0] ==  '1'){		//NORTH
		//Q.push(map[i][j-1][k]);
		cout << "North...  ";
	}
	if(value[1] ==  '1'){		//EAST
		cout << "East...  ";
		//Q.push(map[i][j-1][k]);
	}
	if(value[2] ==  '1'){		//SOUTH
		cout << "South...  ";
  	//Q.push(map[i][j+1][k]);
	}
	if(value[3] ==  '1'){		//WEST
		cout << "West...  ";
  	//Q.push(map[i][j][k-1]);
	}
	if(value[4] ==  '1'){		//UP
		cout << "Up...  ";
  	//Q.push(map[i+1][j][k]);
	}
	if(value[5] ==  '1'){		//DOWN
		cout << "Down...  ";
  	//Q.push(map[i-1][j][k]);
	}
	cout << endl;
//}
}


int main(int argc, char* argv[]) {
	ifstream inputFile;
	queue<vertex> Q;			//queue for BFS

	int numMazes;
	int levels, rows, columns;

	int startL, startR, startC;
	int   endL,   endR,   endC;


	if(argc != 2) {
			cout << "\nInvalid number arguments. \
						Usage: ./project3 input.txt\n" << endl;
			return -1;
	}

	inputFile.open(argv[1]);
	if(!inputFile.is_open()) {
		cout << "\nFile \'" << argv[1] << "\' could not be opened. \
							Check the file and try again.\n" << endl;
		return -1;
	}

	//currently unused output.
	//ofstream output;
	//output.open("output.txt");

	inputFile >> numMazes;
	cout << "we have " << numMazes << " mazes." << endl;

	for(int maze = 0 ; maze < numMazes; maze++){

		inputFile >> levels >> rows >> columns;
		inputFile >> startL >> startR >> startC;
		inputFile >> endL >> endR >> endC;

		cout << endl << "Maze: " << maze << " " << levels << "x" << rows << "x" << columns << endl;

		//output start to finish
		cout << "(" << startL << ", " << startR << ", " << startC << ")" << " --->";
		cout << "(" << endL 	<< ", " << endR 	<< ", " << endC 	<< ")"<< endl << endl;


		vertex map[levels][rows][columns] = {};
		for( int i = 0 ; i < levels; i++){
			for(int j = 0; j < rows; j++){
				for(int k = 0; k < columns; k++){
						vertex *v = new vertex;
						inputFile >> v->value;
							v->i = i;
							v->j = j;
							v->k = k;
						map[i][j][k] = *v;					//add the pointer to v in the map
				}
			}
		}

		Q.push(map[startL][startR][startC]);			//push start onto Queue
		findNeighbors(Q);
		Q.pop();																	//remove start bc this isn't working.
		}

	}
