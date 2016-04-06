#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

typedef struct landCell {
	char landOwnder;
	bool isModified;
} Cell;

// void afterMath(int& row, int& column, int& numDays, char** battlefield) {
void afterMath(int& row, int& column, int& numDays) {
	// Instantiate room for battlefield and battlefield on next day
	char battlefield[row][column];
	char nextDayMath[row][column];
	char (*currField)[row][column] = &battlefield;
	char (*nextDayField)[row][column] = &nextDayMath;
	int i, j;
	char teamAmerica;
	// Create the initial battlefield
	for (i = 0; i < row; ++i) {
		for (j = 0; j < column; ++j) {
			cin >> teamAmerica;
			(*currField)[i][j] = teamAmerica;
		}
	}

	for (int currDay = 0; currDay < numDays; ++currDay) {
		// Quickly switch pointers to each battlefield
		if ((currDay % 2) == 1) {
			currField = &nextDayMath;
			nextDayField = &battlefield;
		} else {
			currField = &battlefield;
			nextDayField = &nextDayMath;
		}
		// Traverse field to see change in value at end of each day
		for (i = 0; i < row; ++i) {
			for (j = 0; j < column; ++j) {

			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int numTestCases;
	cin >> numTestCases;
	for (int currCase = 0; currCase < numTestCases; ++currCase) {
		int row, column, numDays;
		cin >> row >> column >> numDays;
		//char battlefield[row][column];
		// Create on heap
		// char** battlefield = new char*[row];
		// for (int r = 0; r < row; ++r) {
		// 	battlefield[r] = new char[column];
		// 	char team;
		// 	for (int col = 0; col < column; ++col) {
		// 		cin >> team;
		// 		battlefield[r][col] = team;
		// 	}
		// }
		afterMath(row, column, numDays);
		// for (int r = 0; r < row; ++r) {
		// 	for (int col = 0; col < column; ++col) {
		// 		cout << battlefield[r][col] << " ";
		// 	}
		// 	cout << "\n";
		// }
	}
	return 0;
}