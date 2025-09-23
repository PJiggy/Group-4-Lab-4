<<<<<<< HEAD

#include <iostream>
#include <fstream> // for files
#include <string>
using namespace std; 

int main(){
   // must read in a file 
   string filename; 
   cout << "Enter filename: "; 
   cin >> filename;

   string line;

    ifstream file(filename); // open the file
    if(!file.is_open()){
        cerr << "Error: Could not open file!" << endl;
        return 1;
    }
  


=======
#include <iostream>
#include <fstream> // for files
#include <string>
using namespace std; 

int main(){
   // must read in a file 
   string filename; 
   cout << "Enter filename: "; 
   cin >> filename;

   string line;

    ifstream file(filename); // open the file
    if(!file.is_open()){
        cerr << "Error: Could not open file!" << endl; // error message
        return 1;
    }
  




>>>>>>> cc5fb958e99d21998464b87752bf33d4e9c4f9eb
}