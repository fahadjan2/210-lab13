// COMSC-210 | Lab 13 | Fahad Fawad Ahmad
// IDE used: Visual Studio
//Program uses a vector to read off a file containing student IDs. It will read off the file and display a bunch of information based on it
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cout << "test2" << endl;
    //File Opening
	ifstream file;
	file.open("elements.txt");
	if (!file.is_open()) {
	    cout << "Failed to open file" << endl;
	    return 1;
	}
    
	//Array Initialization
	vector<int> studentIDs;
	vector<int> ages;
	string sID;
	int count = 0;

    while (getline(file, sID)) {
		studentIDs.push_back(stoi(sID.substr(0, 7)));
		ages.push_back(stoi(sID.substr(8, 2)));
    }
	file.close();

	//Display
	cout << "Student IDS:" << endl;
	for (int id : studentIDs) {
		cout << id << " ";
	}
	cout << endl;

	//Outputting different elements
	cout << "First Student ID Inputted: " << studentIDs.front() << endl;
	cout << "Last Student ID Inputted: " << studentIDs.back() << endl;
	cout << "5th Student ID Inputted: " << studentIDs.at(5) << endl;

	//Age w/ Student ID
	cout << "\n\nStudent IDs paired with age: " << endl;
	for (int i = 0; i < studentIDs.size(); i++) {
		cout << "Student ID: " << studentIDs[i] << " -- Age: " << ages[i] << endl;
        count++;
	}

	//Sorted
	sort(studentIDs.begin(), studentIDs.end());
	cout << "\nStudents sorted by ID: " << endl;
	for (int id : studentIDs) {
		cout << id << " ";
	}
	cout << endl;

	//Find value
	int IDToFind = 2225255;
	vector <int>::iterator finder;
	finder = find(studentIDs.begin(), studentIDs.end(), IDToFind);
	if (finder != studentIDs.end()) {
		cout << IDToFind << " was found" << endl;
	} else {
		cout << IDToFind << " wasn't found" << endl;
	}
}

