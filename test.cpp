#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

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
	ifstream inputFile;

	if(argc != 2) {
			cout << "\nInvalid number of arguments. Usage: ./project3 input.txt\n" << endl;
			return -1;
	}
	inputFile.open(argv[1]);
	if(!inputFile.is_open()) {
		cout << "\nFile \'" << argv[1] << "\' could not be opened. Check the file and try again.\n" << endl;
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

		int map[levels][rows][columns] = {}; 
		for( int i = 0 ; i < levels; i++){
			cout << endl << endl << "level " << i <<": ";
			for(int j = 0; j < rows; j++){
				cout << endl << "row " << j << ": ";
				for(int k = 0; k < columns; k++){ 
					inputFile >> map[i][j][k];
					cout  << setw(6) << map[i][j][k] << " " ;
				}
			}
		}		
	}
}

