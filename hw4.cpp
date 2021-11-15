#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void sortArrays(string *, int *, int);

int main() {
    int arraySize;
    cout << "Note: All numbers entered will be processed as integers. If you enter a number with a decimal point,\n";
    cout << "the program will round the number down to the nearest integer.\n" << endl;
    cout << "How many scores will you enter? " ;

    cin >> arraySize;

    // Input validation: If user does not enter an integer or enters a negative number,
    // throw an invalid argument exception with message stating the entry requirements.
    if ( cin.fail() || arraySize < 0 ) {
        throw invalid_argument("Invalid entry. Entry must be a non-negative integer.");
    }

    // If user enters 0 for the number of test scores to be entered, exit program.
    if (arraySize == 0) {
        cout << "Exiting program" << endl;
        return 0;
    }

    // Ignore all characters up to the next \n to ensure that, if the user input a decimal point
    // number, the next extraction will be from the next user input.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Dynamically allocate 2 arrays with a size equal to the number of test scores the
    // user entered. One array will be for the student names, and the other will be for
    // the student test scores. Create pointer variables to point to the first element
    // in both arrays.
    string * ptrName;
    int * ptrScore;
    ptrName = new string [arraySize];
    ptrScore = new int [arraySize];

    string name;
    int score;

    // Prompt user for student names and test scores. Use pointer arithmetic
    // to add the user input to the arrays.
    for (int i = 0; i < arraySize; i++) {
        cout << "Enter student " << i + 1 << "'s last name: ";
        cin >> name;
        if (cin.fail()) {
            throw invalid_argument("Invalid entry.");
        }
        *(ptrName + i) = name;

        cout << "Enter that student's test score: ";
        cin >> score;
        // Input validation: If user does not enter an integer between 0 and 100, inclusive,
        // throw an invalid argument exception with a message stating the entry requirements.
        if (cin.fail() || score < 0 || score > 100) {
            throw invalid_argument("Invalid entry. Test score must be between 0 and 100, inclusive");
        }

        // Ignore all characters up to the next \n to ensure that, if the user input a decimal point
        // number, the next extraction will be from the next user input.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        *(ptrScore + i) = score;
    }

    sortArrays(ptrName, ptrScore, arraySize);

    // Use delete operator to de-allocate dynamic memory.
    delete[] ptrName;
    delete[] ptrScore;
}

void sortArrays(string * ptrName, int * ptrScore, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << *(ptrName + i) << ", " << *(ptrScore + i) << endl;
    }
}
