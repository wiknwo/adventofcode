/**
 * Program to calculate which floor the instructions 
 * from the text file will take Santa to in the apartment 
 * building. 
 * */
#include<iostream> // IO processing from stdin/stdout
#include<string> // String class for CPP
#include <cstdlib> // Absolute value function
#include <fstream> // File handling for IO file streams
using namespace std;

/** Function Prototypes */
int calculateSantaFloor(string instructions);

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
    cout << "C++ Version: " << __cplusplus << "\n";
    cout << "TEST1A: " << (calculateSantaFloor("(())") == 0) << "\n";
    cout << "TEST1B: " << (calculateSantaFloor("(())") == calculateSantaFloor("()()")) << "\n";
    cout << "TEST2A: " << (calculateSantaFloor("(((") == 3) << "\n";
    cout << "TEST2B: " << (calculateSantaFloor("(((") == calculateSantaFloor("(()(()(")) << "\n";
    cout << "TEST3: " << (calculateSantaFloor("))(((((") == 3) << "\n";
    cout << "TEST4A: " << (calculateSantaFloor("())") == 1) << "\n";
    cout << "TEST4B: " << (calculateSantaFloor("())") == calculateSantaFloor("))(")) << "\n";
    cout << "TEST5A: " << (calculateSantaFloor(")))") == 3) << "\n";
    cout << "TEST5B: " << (calculateSantaFloor(")))") == calculateSantaFloor(")())())")) << "\n";
    // Final assertion on challenge input
    cout << "TESTN: " << (calculateSantaFloor(instructions) == 232) << "\n";
}

/** Function Definitions */
int calculateSantaFloor(string instructions) {
    /**
     * Function to calculate which floor Santa ends up
     * on after following the instructions in the text 
     * file.
     */
    int floorNumber = 0;
    // Iterate over instructions
    for (char instruction : instructions) {
        if (instruction == '(') {
            floorNumber++;
        } else if (instruction == ')') {
            floorNumber--;
        }
    }
    // Return the floor number
    return abs(floorNumber);
}