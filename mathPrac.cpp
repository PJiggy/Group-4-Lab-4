#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include <fstream>

using namespace std;

int main(){
    // must keep track of right and wrong answers
    int correct = 0, wrong = 0;
    
    // keeps track of the choice for the user
    int choice;
    ofstream outputFile("results.txt");
    
    // random
    random_device rd ; // generates seed
    mt19937 gen(rd()); // Mersenne Twister Engine
    uniform_int_distribution<> distr(1,500); // sets range

    // use in form "int rand = distr(gen);"

    // displays menu and prompts user for math problem
    while (true){ // will break within loop depending on user choice
        
        cout << " --------------" << endl;
        cout << "| Menu Options |" << endl << " --------------"<<endl;
        cout << "1) Addition" << endl << "2) Subtraction" << endl << "3) Multiplication" << endl << "4) Division" << endl << "5) Statistics" << endl << "-999) Exit\n" << endl;

        cout << "Enter a number to select an option: ";
        cin >> choice;

        //Exit Condition
        if (choice ==  -999) {
            break;
        }

        //Addition
        else if (choice == 1){

            
        }

        //Subtraction, Paul
        else if (choice == 2){
            int minuend = distr(gen); // random number for minuend
            int subtrahend = distr(gen); // random for subtrahend
            int answer;
            cout << "What is " << minuend << " - " << subtrahend << "?" << endl;
            cin >> answer;
            if(answer == minuend - subtrahend){
            if(answer == (minuend - subtrahend)){
                cout << "Correct!" << endl;
                correct++; 
            }
            else{
                cout << "Oh no..... wrong!" << endl;
                cout << "The correct answer was: " << (minuend - subtrahend) << endl;

                wrong++; 
            }
        }

        //Multiplication
        else if (choice == 3){
            //Generate two numbers
            int a = rand() % 10 + 1;
            int b = rand() % 10 + 1;
            int answer = a * b;
            int userAnswer;

            cout << "What is " << a << " * " << b << "?\n"<< endl;
            cout << "Enter your answer: " << endl;
            cin >> userAnswer;

            if (userAnswer == answer){
                correct++;
                cout << "Correct!" << endl;

            }
            else{
                wrong++;
                cout << "Incorrect!" << endl;
                cout << "Your answer: " << userAnswer << endl;
                cout << "Correct answer: " << answer << endl;
                cout << endl << endl;
            }
            continue;
            
        }

        //Division
        else if (choice == 4){
            
            
        }
        
        //Statistics
        else if (choice == 5){

            
        }
        else {
           cout << "Please enter a valid option. " << endl;
        }
    }




        





    














    return 0;
}