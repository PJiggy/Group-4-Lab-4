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
   // open the file
    ifstream file(filename); 
    if(!file.is_open()){
        cerr << "Error: Could not open file!"; << endl; // error message
        return 1;
    }
  

    


    
}