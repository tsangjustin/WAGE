#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

typedef struct landCell {
	char landOwner;
	bool isModified;
} Cell;

// void afterMath(int& row, int& column, int& numDays, char** battlefield) {
void afterMath(int& row, int& column, int& numDays) {
	// Instantiate room for battlefield and battlefield on next day
	// TODO: Find if they are initialized to flase and empty char
	Cell battlefield[row][column];
	Cell nextDayMath[row][column];
	Cell (*currField)[row][column] = &battlefield;
	Cell (*nextDayField)[row][column] = &nextDayMath;
	int i, j;
	char teamAmerica;
	// Create the initial battlefield
	for (i = 0; i < row; ++i) {
		for (j = 0; j < column; ++j) {
			cin >> teamAmerica;
			(*currField)[i][j]->landOwner = teamAmerica;
		}
	}

	for (int currDay = 0; currDay < numDays; ++currDay) {
		// Quickly switch pointers to each battlefield
		// If at odd number of days
		if ((currDay & 1) == 1) {
			currField = &nextDayMath;
			nextDayField = &battlefield;
		// If at even number days
		} else {
			currField = &battlefield;
			nextDayField = &nextDayMath;
		}
		// Traverse field to see change in value at end of each day
		for (i = 0; i < row; ++i) {
			for (j = 0; j < column; ++j) {
				// Return negative means that the initial cell is changed
				// Return positive means that the relative cell to initial cell is changed
				int charAtCell;
				(*currField)[i][j]->isModified = false;
				if ((*nextDayField)[i][j]->isModified == false) {
					// Create a map
				}
				if ((i < row - 1) && (*nextDayField)[i + 1][j]->isModified == false) {
					if ((charAtCell = ) != '') {
						(*nextDayField)[i + 1][j]->landOwner = charAtCell;
						(*nextDayField)[i + 1][j]->isModified = true;
					}
				}
				if ((j < column - 1) && (*nextDayField)[i][j + 1]->isModified == false) {
					if ((charAtCell = ) != '') {
						(*nextDayField)[i][j + 1]->landOwner = charAtCell;
						(*nextDayField)[i][j + 1]->isModified = true;
					}
				}
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
