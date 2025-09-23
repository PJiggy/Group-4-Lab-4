#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <iomanip> // for setw()

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Initialize random seed

    int correctAnswers = 0;
    int wrongAnswers = 0;
    int userAnswer;
    int num1, num2;

    cout << "Math Practice - Addition Mode" << endl;
    cout << "Enter -999 to exit and return to the menu." << endl;

    while (true) {
        // Generate two random numbers
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;

        cout << "What is " << num1 << " + " << num2 << "? ";
        cin >> userAnswer;

        // User exit
        if (userAnswer == -999) {
            break;
        }

        //Answer check
        if (userAnswer == (num1 + num2)) {
            cout << "Correct" << endl;
            correctAnswers++;
        } else {
            cout << "The correct answer is " << (num1 + num2) << "." << endl;
            wrongAnswers++;
        }
    }

    //summary of performance
    cout << "\nSummary of Your Performance:" << endl;
    cout << setw(20) << left << "Correct Answers: " << correctAnswers << endl;
    cout << setw(20) << left << "Wrong Answers: " << wrongAnswers << endl;
    cout << setw(20) << left << "Total Questions: " << (correctAnswers + wrongAnswers) << endl;

    // Save results
    ofstream outFile("results.txt");
    if (outFile.is_open()) {
        outFile << "Math Practice - Addition Mode Results\n";
        outFile << "Correct Answers: " << correctAnswers << endl;
        outFile << "Wrong Answers: " << wrongAnswers << endl;
        outFile << "Total Questions: " << (correctAnswers + wrongAnswers) << endl;
        outFile.close();
        cout << "\nYour results have been saved to 'results.txt'.\n";
    } else {
        cout << "Unable to open file for writing results." << endl;
    }

    return 0;
}
