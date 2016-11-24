#include <iostream>
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

	ofstream output;
	output.open("output.txt");

	//cout << "How many times do you want to run the program? " << endl;
	//cin >> howManyRuns;
	inputFile >> numMazes;
	inputFile >> levels >> rows >> columns; 
	inputFile >> startL >> startR >> startC;
	inputFile >> endL >> endR >> endC;

	cout << "we have " << numMazes << " mazes." << endl;
	cout << "our maze is: " << levels << rows << columns << endl;
	
	cout << "starting at " << startL << startR << startC << endl;
	cout << "ending at " << endL << endR << endC << endl;

	int map[levels][rows][columns] = {}; 
	for( int i = 0 ; i < levels; i++){
		cout << endl << "map " << i+1 <<": ";
		for(int j = 0; j < rows; j++){
			cout << endl << "row " << j << endl;
			cout << "Added: ";
			for(int k = 0; k < columns; k++){ 
				inputFile >> map[i][j][k];
				cout  << map[i][j][k] << " " ;
			}
		}
	}
 
				

}
/*




	for(int i = 0; i < howManyRuns; i++) {
		t = 0;
		n = 0;
		value = 0;
		sumofNum = 0;
		vector<int> given;
		vector<parts> results;


		//cout << "How many number are there?" << endl;
		//cin >> n;
		inputFile >> n;

		//cout << "Enter how big you want t to be." << endl;
		//cin >> t;
		inputFile >> t;

		//cout << "Enter all the values." << endl;
		for (int i = 0; i < n; i++) {
			//cin >> value;
			inputFile >> value;
			given.push_back(value);						//populate the vector with given values
		}



		for (int i = 0; i < n; i++) {
			results.push_back(parts());
			results[i].score = 2147483647;
		}

		for (int i = n - 1; i > -1; i--) {
			for (int j = i; j > -1; j--) {
				if (j == i) {
					if (i == n - 1) {																				//base case
						if (getScore(t, given.at(j)) < results[j].score) {		//if we have a better score
							results[j].score = getScore(t, given.at(j));
							results[j].partSeg.push_back(1);
						}
					}
					else {
						if (getScore(t, given.at(j)) + results[i + 1].score < results[j].score) {
							results[j].score = getScore(t, given.at(j)) + results[i + 1].score;
							results[j].partSeg = results[i + 1].partSeg;
							results[j].partSeg.push_back(1);
						}
					}
				}
				else {
					for (int k = j; k <= i; k++) {
						sumofNum += given.at(k);
					}
					if (sumofNum > t)
						break;									//if we went over bucket size
					else {
						if (i == n - 1) {																				//base case
							if (getScore(t, sumofNum) < results[j].score) {
								results[j].score = getScore(t, sumofNum);
								results[j].partSeg.push_back(i - j + 1);
							}
						}
						else {
							if (getScore(t, sumofNum) + results[i + 1].score < results[j].score) {
								results[j].score = getScore(t, sumofNum) + results[i + 1].score;
								results[j].partSeg = results[i + 1].partSeg;
								results[j].partSeg.push_back(i - j + 1);
							}
						}
					}
				}
				sumofNum = 0;
			}
		}

//		cout << results[0].partSeg.size() << " ";
		output << results[0].partSeg.size() << " ";

		for (int i = results[0].partSeg.size() - 1; i > -1; i--) {
			//cout << results[0].partSeg.at(i) << " ";
			output << results[0].partSeg.at(i) << " ";
		}

		//cout << endl
		output << endl;

	}
		output.close();
}

*/
