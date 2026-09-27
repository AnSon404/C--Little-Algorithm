#include <iostream>
using namespace std;

// calculates the GPA of a few subjects, without error checking

int main() {
    float credit, gp;
    float totalC, totalG;
    string grade;

    totalC = 0;
    totalG = 0;
    while (true) { // always repeat
        cout << "Please enter the grade and credit of a subject (Q to quit)" << endl;
        cin >> grade; // get the grade
        if (grade == "Q") break; // end of data, get out of loop
        cin >> credit; // get the credit
        // calculate grade point based on the grade
        if (grade[0] == 'A') gp = 4;
        if (grade[0] == 'B') gp = 3;
        if (grade[0] == 'C') gp = 2;
        if (grade[0] == 'D') gp = 1;
        if (grade[0] == 'F') gp = 0;
        // adjustment with + / - of the grade
        if (grade[1] == '+') gp = gp+0.3;
        if (grade[1] == '-') gp = gp-0.3;
        // accumulate GP and credits
        totalG = totalG + gp*credit;
        totalC = totalC + credit;
        // can you handle grade input in lower case?
    }
    cout << "The GPA for " << totalC << " credits is " << totalG/totalC << endl;
}
