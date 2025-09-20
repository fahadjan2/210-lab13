// COMSC-210 | Lab 11 | Fahad Fawad Ahmad
// IDE used: Visual Studio
//Program uses an array to read off a file containing student IDs. It will read off the file and display a bunch of information based on it
#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
using namespace std;

const int SIZE = 30;

int main() {
	cout << "test" << endl;
    //File Opening
	ifstream file;
	file.open("elements.txt");
	if (!file.is_open()) {
	    cout << "Failed to open file" << endl;
	    return 1;
	}
    
	//Array Initialization
	array<int, SIZE> studentIDs;
	array<int, SIZE> ages;
	string sID;
	int count = 0;

    while (getline(file, sID)) {
		studentIDs[count] = stoi(sID.substr(0, 7));
		ages[count] = stoi(sID.substr(8, 2));
		count++;
    }
	file.close();

	//Display
	cout << "Student IDS:" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << studentIDs[i] << " ";
	}
	cout << endl;

	//Outputting different elements
	cout << "First Student ID Inputted: " << studentIDs.front() << endl;
	cout << "Last Student ID Inputted: " << studentIDs.back() << endl;
	cout << "5th Student ID Inputted: " << studentIDs.at(5) << endl;

	//Age w/ Student ID
	cout << "\n\nStudent IDs paired with age: " << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << "Student ID: " << studentIDs[i] << " -- Age: " << ages[i] << endl;
	}

	//Sorted
	sort(studentIDs.begin(), studentIDs.end());
	cout << "\nStudents sorted by ID: " << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << studentIDs[i] << " ";
	}
	cout << endl;

	//Find value
	int IDToFind = 2225255;
	array <int, SIZE>::iterator finder;
	finder = find(studentIDs.begin(), studentIDs.end(), IDToFind);
	if (finder != studentIDs.end()) {
		cout << IDToFind << " was found" << endl;
	} else {
		cout << IDToFind << " wasn't found" << endl;
	}
}

