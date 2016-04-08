#include <iostream>
#include <string>

using namespace std;

// void afterMath(int& row, int& column, int& numDays, char** battlefield) {
void afterMath(int& row, int& column, int& numDays, int* diff) {
	// Instantiate room for battlefield and battlefield on next day
	char battlefield[row][column];
	char nextDayMath[row][column];
	int i, j, charAtCell;
	// Create the initial battlefield
	for (i = 0; i < row; ++i) {
		for (j = 0; j < column; ++j) {
			cin >> battlefield[i][j];
			nextDayMath[i][j] = battlefield[i][j];
		}
	}

	for (int currDay = 0; currDay < numDays; ++currDay) {
		// Traverse field to see change in value at end of each day
		for (i = 0; i < row; ++i) {
			for (j = 0; j < column; ++j) {
				// If there is a cell below
				if (i < row - 1) {
					// Change initial cell at (i, j)
					if ((charAtCell = diff[(battlefield[i][j] - battlefield[i + 1][j]) + 22]) < 0) {
						nextDayMath[i][j] = (char)(-1 * charAtCell);
					// Change value at cell at (i+1, j)
					} else if (charAtCell > 0) {
						nextDayMath[i + 1][j] = (char)charAtCell;
					}
				}
				// If there is cell to right
				if (j < column - 1) {
					// Change initial cell at (i, j)
					if ((charAtCell = diff[(battlefield[i][j] - battlefield[i][j + 1]) + 22]) < 0) {
						nextDayMath[i][j] = (char)(-1 * charAtCell);
					// Change value at cell at (i, j+1)
					} else if (charAtCell > 0) {
						nextDayMath[i][j + 1] = (char)charAtCell;
					}
				}
			}
		}
		for (i = 0; i < row; ++i) {
			for (j = 0; j < column; ++j) {
				battlefield[i][j] = nextDayMath[i][j];
			}
		}
	}
// Print the outcome of the battle for numDays days
	for (i = 0; i < row; ++i) {
		for (j = 0; j < column; ++j) {
			cout << battlefield[i][j];
		}
		cout << "\n";
	}
}

int main() {
	int numTestCases;
	cin >> numTestCases;
	// Return negative means that the initial cell is changed
	// Return positive means that the relative cell to initial cell is changed
	int diff[45];
	diff[0] = -87;
	diff[6] = 71;
	diff[16] = 65;
	diff[22] = 0;
	diff[28] = -65;
	diff[38] = -71;
	diff[44] = 87;
	for (int currCase = 0; currCase < numTestCases; ++currCase) {
		int row, column, numDays;
		cin >> row >> column >> numDays;
		afterMath(row, column, numDays, diff);
	}
	return 0;
}
