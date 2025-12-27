#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdlib.h> 
#include <stdexcept>

using namespace std;

void validateN(int n) {
    if (n <= 0) throw "n must be a positive integer!";
}

void validateRange(double a, double b) {
    if (a > b) throw "Start of range (a) cannot be greater than (b)!";
}

void validateStep(double step) {
    if (step <= 0) throw "Step must be greater than zero!";
}

double calculateY(double x, int n) {
    double y = 0.0;

    if (x == -1.0) throw "Division by zero (x cannot be -1)";

    if (x < 0) {
        double sum = 0;
        for (int i = 2; i <= n; i++) {
            sum += pow((i - 3 + x), 2);
        }
        y = sum - 5 * x;
    }
    else {
        double denominator = 2 * pow(1 + x, 2);
        if (abs(denominator) < 1e-9) throw "Division by zero (denominator is zero)";

        double outerSum = 0;
        for (int i = 0; i <= n; i++) {
            double innerProd = 1.0;
            if (n - 1 >= 1) {
                for (int j = 1; j <= n - 1; j++) {
                    innerProd *= (double)(i + j) / denominator;
                }
            }
            outerSum += innerProd;
        }
        y = outerSum;
    }
    return y;
}

int getValidInt(const string& prompt) {
    int value;
    string line;
    while (true) {
        cout << prompt;
        getline(cin, line);
        stringstream ss(line);
        if (ss >> value && ss.eof()) break;
        cout << "Error: Invalid input. Enter an integer.\n";
    }
    return value;
}

double getValidDouble(const string& prompt) {
    double value;
    string line;
    while (true) {
        cout << prompt;
        getline(cin, line);
        stringstream ss(line);
        if (ss >> value && ss.eof()) break;
        cout << "Error: Invalid input. Enter a number.\n";
    }
    return value;
}

void waitForEnter() {
    cout << "\nPress [Enter] to return...";
    cin.ignore(1000, '\n');
    cin.get();
}

bool exitConfirmation() {
    cout << "\nExit? (Y/N): ";
    string line;
    getline(cin, line);
    return (!line.empty() && toupper(line[0]) == 'Y');
}

#ifndef UNIT_TESTING 
int main() {
    while (true) {
        system("cls");
        cout << "1. Calculate Range\n2. Calculate Single Value\n3. Exit\nSelect: ";
        int choice = getValidInt("");

        if (choice == 3) {
            if (exitConfirmation()) break;
            continue;
        }

        try {
            if (choice == 1) {
                int n = getValidInt("Enter n: ");
                validateN(n);

                double a = getValidDouble("Enter a: ");
                double b = getValidDouble("Enter b: ");
                validateRange(a, b);

                double step = getValidDouble("Enter step: ");
                validateStep(step);

                cout << "\n--- Results ---\n";
                for (double x = a; x <= b; x += step) {
                    try {
                        cout << "x=" << x << " | y=" << calculateY(x, n) << endl;
                    }
                    catch (const char* msg) {
                        cout << "x=" << x << " | Error: " << msg << endl;
                    }
                }
            }
            else if (choice == 2) {
                int n = getValidInt("Enter n: ");
                validateN(n);
                double x = getValidDouble("Enter x: ");
                cout << "\nResult: y = " << calculateY(x, n) << endl;
            }
        }
        catch (const char* msg) {
            cout << "\nError: " << msg << endl;
        }

        waitForEnter();
    }
    return 0;
}
#endif