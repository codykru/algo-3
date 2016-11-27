#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <queue>       


using namespace std;


struct vertex {
	int value; 		//the binary we are dealing with 
	bool discovered;
	int col;
	int row; 
	int level;
}; 

void findNeighbors(string value, int i, int j, int k){
	cout << "we are at: " << i << ", " << j << ", " << k <<  endl;
	//floor = i 
	//row = j 
	//col = k
	//N E S  W U D 
	if(value[0] ==  '1'){
		cout << "NORTH!   " ;
		cout << "go to: " << i << ", " << j - 1 << ", " << k <<  endl;
		//findNeighbors(
	}
	if(value[1] ==  '1'){
		cout << "EAST!    " ;
		cout << "go to: " << i << ", " << j << ", " << k + 1 <<  endl;
	}
	if(value[2] ==  '1'){
		cout << "SOUTH!   " ;
		cout << "go to: " << i << ", " << j + 1<< ", " << k <<  endl;
	}
	if(value[3] ==  '1'){
		cout << "WEST     " ;
		cout << "go to: " << i << ", " << j << ", " << k - 1 <<  endl;
	}
	if(value[4] ==  '1'){
		cout << "UP!      " ;
		cout << "go to: " << i + 1<< ", " << j << ", " << k  <<  endl;
	}
	if(value[5] ==  '1'){
		cout << "DOWN!    " ;
		cout << "go to: " << i -1 << ", " << j << ", " << k <<  endl;	
	}
	cout << endl;

}

	
int main(int argc, char* argv[]) {
	int numMazes;
	int levels, rows, columns;
	int startL, startR, startC;
	int endL, endR, endC;


	int i = 0;					//counter variable
	int t = 0;					//bucket size
	int n = 0;					//length of our case
	int value = 0;
	int sumofNum =0;
	queue<string> working;
	ifstream inputFile;

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
		cout << endl << endl << "Maze: " << maze << endl;	
		inputFile >> levels >> rows >> columns; 
		inputFile >> startL >> startR >> startC;
		inputFile >> endL >> endR >> endC;

		cout << "our maze is: " << levels << "x" << rows << "x" << columns << endl;
	
		cout << "start: (" << startL << ", " << startR << ", " << startC << ")" <<  endl;
		cout << "end:   (" << endL << ", "  << endR << ", " << endC <<")"<< endl;

		string map[levels][rows][columns] = {}; 
		for( int i = 0 ; i < levels; i++){
			cout << endl << endl << "level " << i <<": ";
			for(int j = 0; j < rows; j++){
				cout << endl << "row " << j << ": " << endl;
				for(int k = 0; k < columns; k++){ 
					inputFile >> map[i][j][k];
					//findNeighbors(map[i][j][k], i, j, k);
					//cout  << setw(6) << map[i][j][k] << " " ;
					
				}
			}
		}

		//While(we aren't at end position && Q isn't empty) 
			findNeighbors(map[startL][startR][startC], startL, startR, startC);
		
		
	}
}

