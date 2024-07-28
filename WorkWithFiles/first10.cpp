#include <iostream>
#include<fstream>
#include<string>
using namespace std;


void overwriteFile(const string& filename) {
    ofstream myFile(filename); // using ofstream for writing (overwrites by default)
    if (myFile.is_open()) {
        myFile << 1234564 << endl; // will write this in the first line
        myFile << 12335466 << endl; // write this in the second line
    }
     // automatically close the file
}

void appendToFile(const string& filename) {
    ofstream myFile(filename, ios::app); // using ofstream for appending
    if (myFile.is_open()) {
        myFile << 123456 << endl; // will write this in the third line
        myFile << 446 << endl; // write this in the fourth line
    }
    // automatically close the file
}

void readNumbersFromFile(const string& filename) {
    ifstream myFile(filename); // using ifstream for reading
    if (myFile.is_open()) {
        long long number; // variable to store the read number
        while (myFile >> number) { // read number by number
            cout << number << endl; // print each number to the console
        }
    }
     // automatically close the file

}

void appendTextToFile(const string& filename) {
    ofstream myFile(filename, ios::app); // using ofstream for appending text
    if (myFile.is_open()) {
        myFile << "this is some text\n";
        myFile << "for test how to take strings from a file\n";
    }
     // automatically close the file
}

void readLinesFromFile(const string& filename) {
    ifstream myFile(filename); // using ifstream for reading
    if (myFile.is_open()) {
        string line;
        while (getline(myFile, line)) {
            cout << line<<endl; // print each line to the console
        }
    }
    // automatically close the file
}

void basicOverwriteFile(const string& filename)
{
    // Overwrite file content
    fstream myFile;
    myFile.open(filename, ios::out); // write out from my code to the file
    if (myFile.is_open()) { // check if it is open successfully
        myFile << 1234564 << endl; // will write this in the first line
        myFile << 12335466 << endl; // write this in the second line
        myFile.close(); // close the file
    }
  
}



void basicAppendToFile(const string& filename)
{
    // Read from the file
    fstream myFile;
    myFile.open(filename, ios::in); // input from my code to the file
    if (myFile.is_open()) {
        long long number; // variable to store the read number
        while (myFile >> number) { // read number by number
            cout << number << endl; // print each number to the console
        }
        myFile.close(); // close the file
    }
  
}

void basicAppendStringToFile(const string& filename)
{
    
    // append some string to the file
    fstream myFile;
    myFile.open("test.txt" , ios::out);
    if(myFile.is_open())
    {
        myFile << "this is some text"<<endl;
        myFile << "for test how to take strings from a file"<<endl;
    }
    myFile.close();
  
}

void basicReadStrignFromFile(const string& filename)
{
    // get line in the #string lib only
    fstream myFile;
    myFile.open(filename, ios::in);
    string line;
    while(getline(myFile, line))
    {
        cout<<line;
    }
}



signed main()
{
    basicOverwriteFile("text.txt");
    readLinesFromFile("text.txt");
}