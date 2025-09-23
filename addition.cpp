#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <limits>

using namespace std;

void additionPractice() {
    int correct = 0;
    int incorrect = 0;
    int userAnswer;
    const int sentinel = -999;

    // Random number
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 20); // Numbers between 0 and 20

    cout << "\n--- Addition Practice ---\n";
    cout << "Enter -999 to return to the main menu.\n";

    while (true) {
        int a = dist(gen);
        int b = dist(gen);
        int correctAnswer = a + b;

        cout << "What is " << a << " + " << b << "? ";
        cin >> userAnswer;

        if (cin.fail()) {
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number or -999 to quit.\n";
            continue;
        }

        if (userAnswer == sentinel) {
            break;
        }

        if (userAnswer == correctAnswer) {
            cout << "✅ Correct!\n";
            ++correct;
        } else {
            cout << "❌ Sorry, the right answer is " << correctAnswer << ".\n";
            ++incorrect;
        }
    }

    // Display summary
    cout << "\n--- Session Summary ---\n";
    cout << setw(15) << left << "Correct Answers:" << correct << "\n";
    cout << setw(15) << left << "Wrong Answers:" << incorrect << "\n";

    // Save to file
    ofstream outFile("results.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Addition Practice Session:\n";
        outFile << setw(15) << left << "Correct Answers:" << correct << "\n";
        outFile << setw(15) << left << "Wrong Answers:" << incorrect << "\n";
        outFile << "--------------------------\n";
        outFile.close();
        cout << "Results saved to results.txt\n";
    } else {
        cerr << "Unable to open results.txt for writing.\n";
    }
}

int main() {
    additionPractice();
    return 0;
}