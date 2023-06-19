#include <iostream>
#include "InvestmentAccount.h"

using namespace std;


//Main Class function prototypes
void pressAnyKeyToContinue(); //Press any key to continue after initial inputs.
void displayMenu(); //displays menu output
int menuChoice(double amount, double deposit, double interest, int years); //acts on menu input from user
void printFullOutput(InvestmentAccount newAccountWith, InvestmentAccount newAccountWithout); //compiles output together
void updateInvestmentAccount(double amount, double deposit, double interest, int years); //updates investment account




int main()
{
    double initialAmount = 0;
    double monthlyDeposit = 0;
    double annualInterest = 0;
    int numberOfYears = 0;

    //Getting the input...validate that the values are non-negative.
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "-------------------------------- Data Input --------------------------------" << endl;
    cout << "Initial Investment Amount: ";
    cin >> initialAmount;
    while (cin.fail() || initialAmount < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please Enter a positive number." << endl;
        cout << "Initial Investment Amount: ";
        cin >> initialAmount;
    }
    cout << "Monthly Deposit: ";
    cin >> monthlyDeposit;
    while (cin.fail() || monthlyDeposit < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please Enter a positive number." << endl;
        cout << "Initial Investment Amount: ";
        cin >> monthlyDeposit;
    }
    cout << "Annual Interest: ";
    cin >> annualInterest;
    while (cin.fail() || annualInterest < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please Enter a positive number." << endl;
        cout << "Initial Investment Amount: ";
        cin >> annualInterest;
    }
    cout << "Number of Years: ";
    cin >> numberOfYears;
    while (cin.fail() || numberOfYears < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please Enter a positive number." << endl;
        cout << "Initial Investment Amount: ";
        cin >> numberOfYears;
    }

    pressAnyKeyToContinue();
        
    //Create two InvestmentAccount variables...one with monthly deposit and one without monthly deposit
    InvestmentAccount newAccountWith(initialAmount, annualInterest, monthlyDeposit, numberOfYears);
    InvestmentAccount newAccountWithout(initialAmount, annualInterest, numberOfYears);

    //update Investment Account variables and output tables
    updateInvestmentAccount(initialAmount, monthlyDeposit, annualInterest, numberOfYears);
    

}
void printFullOutput(InvestmentAccount newAccountWith, InvestmentAccount newAccountWithout) {
    //prints full output for investment accounts with and without monthly investments

    newAccountWith.printWithMonthlyDeposit();

    cout << endl;
    cout << endl;

    newAccountWithout.printWithoutMonthlyDeposit();
    cout << "----------------------------------------------------------------------------" << endl;
    cout << endl;
    displayMenu();
}

void pressAnyKeyToContinue() {
    //waits for user to press a key to continue to next step
    cout << "Press Enter to Continue";
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

void displayMenu() {
    //displays menu for user to update values
    cout << "1. Change Initial Investment  ";
    cout << "2. Change Monthly Deposit  ";
    cout << "3. Change Annual Interest  ";
    cout << "4. Change Number Of Years  ";
    cout << "5. Exit" << endl;
}
int menuChoice(double amount, double deposit, double interest, int years)
{
    string confirm;
    //updates the values for the user based on menu choice

    int userChoice;
    double initialAmount = amount;
    double monthlyDeposit = deposit;
    double annualInterest = interest;
    int numberOfYears = years;

    cout << "What would you like to do? ";
    cin >> userChoice;
    switch (userChoice)
    {
    case 1:
        cout << "Enter New Initial Investment: ";
        cin >> initialAmount;
        while (cin.fail() || initialAmount < 0) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please Enter a positive number." << endl;
            cout << "Initial Investment Amount: ";
            cin >> initialAmount;
        }
        updateInvestmentAccount(initialAmount, monthlyDeposit, annualInterest, numberOfYears);
    case 2:
        cout << "Enter New Monthly Deposit: ";
        cin >> monthlyDeposit;
        while (cin.fail() || monthlyDeposit < 0) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please Enter a positive number." << endl;
            cout << "Initial Investment Amount: ";
            cin >> monthlyDeposit;
        }
        updateInvestmentAccount(initialAmount, monthlyDeposit, annualInterest, numberOfYears);
    case 3:
        cout << "Enter New Annual Interest: ";
        cin >> annualInterest;
        while (cin.fail() || annualInterest < 0) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please Enter a positive number." << endl;
            cout << "Initial Investment Amount: ";
            cin >> annualInterest;
        }
        updateInvestmentAccount(initialAmount, monthlyDeposit, annualInterest, numberOfYears);
    case 4:
        cout << "Enter New Number Of Years: ";
        cin >> numberOfYears;
        while (cin.fail() || numberOfYears < 0) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please Enter a positive number." << endl;
            cout << "Initial Investment Amount: ";
            cin >> numberOfYears;
        }
        updateInvestmentAccount(initialAmount, monthlyDeposit, annualInterest, numberOfYears);
    case 5:
        cout << "Exiting Program.";
        exit(1);
    default: cout << "Invalid entry. Please select again." << endl;
        displayMenu();
        menuChoice(initialAmount, monthlyDeposit, annualInterest, numberOfYears);

    }

    return 0;
}

void updateInvestmentAccount(double amount, double deposit, double interest, int years) {
    double initialAmount = amount;
    double annualInterest = interest;
    double monthlyDeposit = deposit;
    int numberOfYears = years;

    InvestmentAccount newAccountWith(initialAmount, annualInterest, monthlyDeposit, numberOfYears);
    InvestmentAccount newAccountWithout(initialAmount, annualInterest, numberOfYears);
    printFullOutput(newAccountWith, newAccountWithout);
    menuChoice(initialAmount, monthlyDeposit, annualInterest, numberOfYears);
}