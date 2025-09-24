#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Stats {
    int totalQuestions;
    int correctAnswers;
    int wrongAnswers;
};

void showStatistics(Stats stats) {
    cout << "\n===== Statistics Summary =====\n";
    cout << setw(20) << left << "Total Questions: " << stats.totalQuestions << endl;
    cout << setw(20) << left << "Correct Answers: " << stats.correctAnswers << endl;
    cout << setw(20) << left << "Wrong Answers: " << stats.wrongAnswers << endl;

    double percentage = 0.0;
    if (stats.totalQuestions > 0) {
        percentage = (static_cast<double>(stats.correctAnswers) / stats.totalQuestions) * 100;
    }
    cout << setw(20) << left << "Accuracy: " << fixed << setprecision(2) << percentage << "%" << endl;

    ofstream outFile("results.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "===== Statistics Summary =====\n";
        outFile << "Total Questions: " << stats.totalQuestions << "\n";
        outFile << "Correct Answers: " << stats.correctAnswers << "\n";
        outFile << "Wrong Answers: " << stats.wrongAnswers << "\n";
        outFile << "Accuracy: " << fixed << setprecision(2) << percentage << "%\n";
        outFile << "==============================\n\n";
        outFile.close();
        cout << "\n(Statistics saved to results.txt)\n";
    } else {
        cout << "\nError: Could not save results to file.\n";
    }
}
