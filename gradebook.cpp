#include <iostream>
#include <fstream> // for files
#include <iomanip> // for setw
#include <string>
using namespace std; 

int main(){
    // variables
    int total,testNum;
    double average;
    char grade; 

   // must read in a file 
   string filename; 
   cout << "Enter filename: "; 
   cin >> filename;

   string line;

   // open the file
    ifstream file(filename); 
    if(!file.is_open()){
        cerr << "Error: Could not open file!" << endl; // error message
        return 1;
    }


    // read their fullname from the file

    string line;
    string student;
    
    getline(file,line); // read first line since student name is first
    student = line; // student is set to this line

    // now we loop through the text scores until we reach -1
    while(getline(file, line)){ // read each line until end
        if(stoi(line) == -1){ // exit if we reach sentinel value
            break;
        }
        total += stoi(line); // add the score to the total
        testNum++; // increment number of tests
    }

    // at this point should have all scores loaded up
    average = total / testNum; // average: total score / # of tests

    switch(grade){
        case 1:
            if(average < 60){
                grade = 'F';
            }
        case 2:
            if(60 < average < 70){
                grade = 'D';
            }
        case 3:
            if(70 < average < 80){
                grade = 'C';
            } 
        case 4:
            if(80 < average < 90){
                grade = 'B';
            }  
        case 5:
            if(90 < average < 100){
                grade = 'A';
            }
        default:
            cout << "Something went wrong. No scores read.";     
    } 
    
    
    // setup table, use table default box size of 25
    cout << "__________________________________________________" << endl; // top of box, 50 underscores;
    cout << setw(50) << "| Student name " << "| Grade |"; // label
    cout << setw(50) << "| " << student << "| " << grade << " |"; // filled in info

    
}