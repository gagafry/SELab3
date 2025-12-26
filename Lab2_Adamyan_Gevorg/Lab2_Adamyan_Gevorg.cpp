#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdlib.h>  // For system("cls")

using namespace std;


//Safely reads an integer (int).
//Keeps asking until valid input is received.
//prompt The message to display to the user.
//The validated int value.

int getValidInt(const string& prompt) {
    int value;
    string line;

    while (true) {
        cout << prompt;
        getline(cin, line);
        stringstream ss(line);
        char remaining;

        if (ss >> value && !(ss >> remaining)) {
            break;
        }
        else {
            cout << "Error: Wrong data type. You entered: \"" << line << "\". Please enter an integer." << endl;
        }
    }
    return value;
}

//Safely reads a double.
//Keeps asking until valid input is received.
//prompt The message to display to the user.
//return The validated double value.

double getValidDouble(const string& prompt) {
    double value;
    string line;

    while (true) {
        cout << prompt;
        getline(cin, line);
        stringstream ss(line);
        char remaining;

        if (ss >> value && !(ss >> remaining)) {
            break;
        }
        else {
            cout << "Error: Wrong data type. You entered: \"" << line << "\". Please enter a number." << endl;
        }
    }
    return value;
}


//Calculates the Y value based on the individual formula.
//The input value x.
//The input value n.
//The resulting y value.

double calculateY(double x, int n) {
    double y = 0.0;
    if (x == -1.0) {
        cout << "Error: Division by zero (x cannot be -1)." << endl;
        return NAN;
    }
    if (x < 0) {
        double sum = 0;
        for (int i = 2; i <= n; i++) {
            sum += pow((i - 3 + x), 2);
        }
        y = sum - 5 * x;
    }
    else {
        double denominator = 2 * pow(1 + x, 2);
        if (denominator == 0) {
            cout << "Error: Division by zero (denominator is zero)." << endl;
            return NAN;
        }
        double outerSum = 0;
        for (int i = 0; i <= n; i++) {
            double innerProd = 1.0;
            if (n - 1 >= 1) {
                for (int j = 1; j <= n - 1; j++) {
                    innerProd *= (double)(i + j) / denominator;
                }
            }
            else {
                innerProd = 1.0;
            }
            outerSum += innerProd;
        }
        y = outerSum;
    }
    return y;
}

// Pauses the program until Enter is pressed.

void waitForEnter() {
    cout << "\nPress [Enter] to return to the main menu";
    string temp;
    getline(cin, temp);
}

// Displays the welcome screen.
void welcomeScreen() {
    system("cls");
    cout << "=================================================\n";
    cout << "  Welcome to the \"Function Calculator\" (Lab 2)\n";
    cout << "=================================================\n\n";
    cout << "This program will help you calculate the function values\n";
    cout << "for your individual task.\n\n";
    cout << "Press [Enter] to go to the Main Menu";
    string temp;
    getline(cin, temp);
}


//Shows the exit confirmation screen.
//return true if the user wants to exit, false otherwise.
bool exitConfirmation() {
    system("cls");
    cout << "Are you sure you want to exit? (Y/N): ";

    string line;
    while (true) {
        getline(cin, line);
        if (line.length() == 1) {
            char choice = toupper(line[0]);
            if (choice == 'Y') {
                system("cls");
                cout << "===============================================================\n\n";
                cout << "  Thank you for using the \"Function Calculator\"!\n";
                cout << "  Goodbye and have a great day!\n\n";
                cout << "===============================================================" << endl;
                return true;
            }
            if (choice == 'N') {
                return false;
            }
        }
        cout << "Please enter 'Y' for Yes or 'N' for No: ";
    }
}


int main() {
    welcomeScreen();

    bool isRunning = true;
    while (isRunning) {
        system("cls");

        cout << "\n==================== MAIN MENU ====================\n\n"
            << "  1. Enter Parameters & Calculate Range\n"
            << "  2. Calculate Single 'x' Value\n"
            << "  3. Exit\n\n"
            << "=================================================\n"
            << "Please select an option: ";

        string line;
        getline(cin, line);
        stringstream ss(line);
        int choice;
        char remaining;

        if (!(ss >> choice) || (ss >> remaining) || choice < 1 || choice > 3) {
            cout << "\nError: Invalid choice. Please press [Enter] and select 1, 2, or 3.";
            waitForEnter();
            continue;
        }

        // --- Handle the choice ---
        switch (choice) {
        case 1: {
            system("cls");
            cout << "--- ENTER PARAMETERS ---\n\n";

            //int n = getValidInt("Enter integer value for n: ");
            int n;
            while (true) {
                n = getValidInt("Enter positive value for n: ");
                if (n > 0) {
                    break;
                }
                cout << "Error: 'n' cannot be non-positive. Please enter a positive number.\n";
            }
            double a = getValidDouble("Enter start of range (a): ");
            double b = getValidDouble("Enter end of range (b): ");
            double step;

            while (true) {
                step = getValidDouble("Enter step: ");
                if (step > 0) break;
                cout << "Error: Step must be greater than zero. Please try again.\n";
            }
            while (a > b) {
                cout << "Error: Start (a) cannot be greater than end (b).\n";
                cout << "Please enter the range again.\n";
                a = getValidDouble("Enter start of range (a): ");
                b = getValidDouble("Enter end of range (b): ");
            }

            cout << "\n--- RESULTS TABLE ---\n\n";
            cout << "-------------------------------------------\n";
            cout << setw(5) << "#" << " |"
                << setw(15) << "x" << " |"
                << setw(15) << "y" << " |" << endl;
            cout << "-------------------------------------------\n";

            cout << fixed << setprecision(4);
            int count = 1;
            for (double x = a; x <= b; x += step) {
                double y = calculateY(x, n);
                if (!isnan(y)) {
                    cout << setw(5) << count++ << " |"
                        << setw(15) << x << " |"
                        << setw(15) << y << " |" << endl;
                }
            }
            cout << "-------------------------------------------\n";

            waitForEnter();
            break;
        }

        case 2: {
            system("cls");
            cout << "--- CALCULATE SINGLE VALUE ---\n\n";

            int n;
            while (true) {
                n = getValidInt("Enter positive value for n: ");
                if (n > 0) {
                    break;
                }
                cout << "Error: 'n' cannot be non-positive. Please enter a positive number.\n";
            }
            double x = getValidDouble("Enter a single value for x: ");

            double y = calculateY(x, n);

            cout << "\n--- Result ---\n";
            cout << fixed << setprecision(4);
            cout << "For n=" << n << " and x=" << x << ", the result y = " << y << endl;

            waitForEnter();
            break;
        }

        case 3: {
            if (exitConfirmation()) {
                isRunning = false;
            }
            break;
        }
        }
    }

    return 0;
}


