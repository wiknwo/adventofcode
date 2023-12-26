/**
 * Now, given the same instructions, find the position 
 * of the first character that causes him to enter the 
 * basement (floor -1).
 */
#include<iostream> // IO processing from stdin/stdout
#include<string> // String class for CPP
#include <cstdlib> // Absolute value function
#include <fstream> // File handling for IO file streams
using namespace std;

/** Function Prototypes */
int findBasementPosition(string instructions);

/** Driver Program */
int main() {
    // Declare file stream for file handling
    fstream file;
    // Declare string to hold Santa's instructions
    string instructions;
    // Open file for reading
    file.open("aoc2015_day1_input.txt", ios::in);
    // Process the string in the file
    file >> instructions;
    
    /** Assertions */
    // Some assertions to check the function is working correctly
    // Sample I/O assertions
    cout << boolalpha; // Set flag to convert 1 and 0 to true and false
    cout << "TEST1: " << (findBasementPosition(")") == 1) << "\n";
    cout << "TEST2: " << (findBasementPosition("()())") == 5) << "\n";
    // Final assertion on challenge input
    cout << "TESTN: " << (findBasementPosition(instructions) == 1783) << "\n";
}

/** Function Definitions */
int findBasementPosition(string instructions) {
    /**
     * Find position of the first character that causes 
     * santa to enter the basement floor (-1).
     */
    int floorNumber = 0, instructionPosition = 1;
    // Iterate over instructions
    for (char instruction : instructions) {
        if (instruction == '(') {
            floorNumber++;
        } else if (instruction == ')') {
            floorNumber--;
            if (floorNumber < 0) return instructionPosition;
        }
        instructionPosition++;
    }
}