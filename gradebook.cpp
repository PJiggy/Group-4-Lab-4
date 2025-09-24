#include <iostream>
#include <fstream> // for files
#include <iomanip> // for setw
#include <string>

using namespace std; 

int main(){
    // variables
    int total = 0,testNum = 0;
    double average = 0.0;
    char grade, ch; 

   // must read in/open a file 
   ifstream file("student.txt"); 
   string line;

    if(!file.is_open()){
        cerr << "Error: Could not open file!" << endl; // error message
        return 1;
    }


    // read their fullname from the file
    string student="";
    

    
    if (file.is_open()) {
        //Read student name from file into student variable
        getline(file,student);
    }



    // now we loop through the text scores until we reach -1
    while(getline(file, line)){ // read each line until end
        
        if(stoi(line) == -1){ // exit if we reach sentinel value
            break;
        }
        total += stoi(line); // add the score to the total
        testNum++; // increment number of tests
    }

    // at this point should have all scores loaded up
        if (testNum > 0) {
        average = static_cast<double>(total) / testNum;
        cout << testNum << " tests read." << endl;

        } else {
        cerr << "Error: no tests read (division by zero)" << endl;
        return 1;
        }

        
        if (average >=90){
        grade = 1;
        }
        else if (average >=80){
            grade = 2;
        }
        else if (average >=70){
            grade = 3;
        }
        else if (average >=60){
            grade = 4;
        }
        else if (average <60){
            grade = 5;
        }


        switch(grade){
            case 1:{
                    grade = 'A';
                    break;
                }
            case 2:{
                    grade = 'B';
                    break;
                }
            case 3:
                {
                    grade = 'C';
                    break;
                } 
            case 4:
                {
                    grade = 'D';
                    break;
                }  
            case 5:
                {
                    grade = 'F';
                    break;
                }
            default:
                cout << "Something went wrong. No scores read.";     
        } 

    
    string status = (average >= 60) ? "PASS" : "FAIL";
    
    

    // setup table, use table default box size of 25
    cout << "----------------------------------------------------" << endl;
    cout << left << setw(20) << "Student name:" << setw(10) << "Grade" << setw(15) << "Avg Score" << setw(10) << "Status" << endl; // label
    cout << "----------------------------------------------------" << endl;
    cout << left << setw(20) << student << setw(10) << grade << setw(15) << average << setw(10) << status << endl; // label    
    cout << "----------------------------------------------------" << endl;
    
    cout << "Enter 'Y' to save to a file." << endl;
    cout << "Otherwise, enter any other key to exit without saving." << endl;

    cin.get(ch);

        if (ch == 'y' || ch == 'Y'){
            ofstream outFile("results.txt");
            if (outFile.is_open()){
                    outFile << "----------------------------------------------------" << endl;
                    outFile << left << setw(20) << "Student name:" << setw(10) << "Grade" << setw(15) << "Avg Score" << setw(10) << "Status" << endl; // label
                    outFile << "----------------------------------------------------" << endl;
                    outFile << left << setw(20) << student << setw(10) << grade << setw(15) << average << setw(10) << status << endl; // label    
                    outFile << "----------------------------------------------------" << endl;
                outFile.close();
                cout << "Reults saved into results.txt" << endl;
            }
            else{
                cerr << "Error: Could not open file for writing!" << endl;
                return 1;
            }
        }
        else {
            cout << "Exiting without saving." << endl;
        }
        return 0;
}
