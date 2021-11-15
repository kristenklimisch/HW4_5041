#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void sortArrays(string *, int *, int);
void printArrays (string *, int *, int);
float getAverageScore (int *, int);

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
    cout << "The test scores in ascending order, and their average, are:\n" << endl;
    sortArrays(ptrName, ptrScore, arraySize);
    printArrays(ptrName, ptrScore, arraySize);
    float average = getAverageScore(ptrScore, arraySize);
    cout << "\nAverage score:   " << setprecision(2) << fixed << average << endl;

    // Use delete operator to de-allocate dynamic memory.
    delete[] ptrName;
    delete[] ptrScore;
}

// Function:     sortArrays
// Purpose:      sorts the arrays for the student scores and student names so that both
//               are sorted in order of ascending test score. For the score array, this
//               means that the lowest score will be the first element in the array and
//               the highest score will be the last element in the array. For the name
//               array, this means that the name of the student with the lowest score
//               will be the first element of the array, and the name of the student
//               with the highest score will be the last element of the array.
//               This function sorts the arrays using bubble sort.
// Parameters:   ptrName -    a pointer to the first element in the array of student names
//               ptrScore -   a pointer to the first element in the array of scores
//               arraySize -  the size of the arrays. Both arrays have the same size.
void sortArrays(string * ptrName, int * ptrScore, int arraySize) {
    int i, j;
    bool swapped;
    for (i = 0; i < arraySize - 1; i++) {
        swapped = false;
        for (j = 0; j < arraySize - i - 1; j++) {

            if ( *(ptrScore + j) > *(ptrScore + j + 1) ) {
                swap(*(ptrScore + j), *(ptrScore + j + 1) );
                swap(*(ptrName + j), *(ptrName + j + 1) );
                swapped = true;
            }
        }
        // Break if no two elements were swapped by inner loop.
        if (swapped = false)
            break;
    }
}

// NEED HELP WITH FORMATTING
// Function:     printArrays
// Purpose:      prints the arrays for the student scores and students names in the format
//               given in the assignment specification.
// Parameters:   ptrName -    a pointer to the first element in the array of student names
//               ptrScore -   a pointer to the first element in the array of scores
//               arraySize -  the size of the arrays. Both arrays have the same size.
void printArrays(string * ptrName, int * ptrScore, int arraySize) {
    cout << "Name" << setw(20) << "Score" << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << *(ptrName + i) << setw(20) << *(ptrScore + i) << endl;
    }
}

// Function:     getAverageScore
// Purpose:      calculates and returns the average of the test scores entered by the user.
// Parameters:   ptrScore -   a pointer to the first element in the array of scores
//               arraySize -  the size of the array.
// Returns:      the average score as a float
float getAverageScore (int * ptrScore, int arraySize) {
    // Iterate through the array to calculate the sum of the scores in the array.
    int sum = 0;
    for (int i = 0 ; i < arraySize; i++) {
        sum += *(ptrScore + i);
    }

    // Cast the sum and the array size as floats and divide the sum by the size
    // to calculate the average score.
    float average = static_cast<float>(sum) / static_cast<float>(arraySize);
    return average;
}




