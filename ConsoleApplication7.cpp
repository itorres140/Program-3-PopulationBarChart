// ConsoleApplication7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Settting up file name
    string fileName;

    // Ask user for file name
    cout << "Enter the name of the file (with extension): ";
    cin >> fileName;

    // Open file
    ifstream inputFile(fileName);

    // Check if file opened successfully
    if (!inputFile)
    {
        // File did not open correctly
        cerr << "Error opening file: " << fileName << endl;
    }

    // Read all lines and store into array
    // Max number of lines
	const int MAX_LINES = 100;
    
    // String array to hold lines and use getline function
	string lines[MAX_LINES];
    
    // Line counter
    int lineCount = 0;

    // Adds to line counter until end of file reached
    while (getline(inputFile, lines[lineCount]) && lineCount < MAX_LINES)
    {
		lineCount++;
    }

	// Close file
    inputFile.close();

    // Loops through each line, converting strings to interget
    for (int i = 0; i < lineCount; i++)
    {
        // Converts string to interget at index i, then divides by 1000
		// to get number of astericks to print
        int numberOfAstericks = stoi(lines[i])/1000;

        // Sets year based on line number
        const int yearInterval = 20;
        
        // Year starts at 1900, and adds 20 for each line
        int year = 1900 + (i * yearInterval);

        // Print year with a colon
        cout << year << " : ";
        
        // Loop to print one asterick for each 1000 in the number
        for (int j = 0; j < numberOfAstericks; j++)
        {
            cout << "*";
        }
		
        // Print a new line for every year
        cout << endl;
	}
    
    return 0;

}
