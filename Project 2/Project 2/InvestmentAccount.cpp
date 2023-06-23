#include "InvestmentAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Implementation for InvestmentAccount
InvestmentAccount::InvestmentAccount() 
{
	//default constructor for InvestmentAccount
	
	this -> initialAmount = 0;
	this -> annualInterestRate = 0;
	this -> monthlyDeposit = 0;
	this -> numberOfYears = 0;
}
InvestmentAccount::InvestmentAccount(double amount, double interestRate, int years)
{
	//main constructor for InvestmentAccount with proper parameters, without monthly deposit
	
	this -> initialAmount = amount;
	this -> annualInterestRate = interestRate;
	this -> numberOfYears = years;
	this -> monthlyDeposit = 0;

}

InvestmentAccount::InvestmentAccount(double amount, double interestRate, double deposit, int years)
{
	//main constructor for InvestmentAccount with proper parameters, with monthly deposit
	
	this -> initialAmount = amount;
	this -> annualInterestRate = interestRate;
	this -> monthlyDeposit = deposit;
	this -> numberOfYears = years;

}

double InvestmentAccount::getEndingBalance(int numberOfYears)
{
	//function to calculate and return the ending balance for each year for numberOfYears
	
	double endingBalance = getInitialAmount();
	double monthlyInterest = getAnnualInterestRate() / 100 /12;
	double totalMonthlyDeposits = getMonthlyDeposit();
	double interestEarned = 0;
	int i;
	int years = numberOfYears;
	int months = years * 12;

		for (i = 1; i <= months; i++) {
			interestEarned = (endingBalance + getMonthlyDeposit()) * (getAnnualInterestRate() / 100 / 12);
			endingBalance = endingBalance + getMonthlyDeposit() + interestEarned;
		}
			

	return endingBalance;
	
}

double InvestmentAccount::getInterestEarned(int numberOfYears)
{
	//function to calculate and return annualized InterestEarned for numberOfYears
	
	double interestEarned = 0;
	double endingBalance = getInitialAmount();
	int i;
	int years = numberOfYears;
	int months = numberOfYears * 12;

	if (years != 1) {
		for (i = 1; i <= years; i++) {
			interestEarned = (getEndingBalance(i) - getEndingBalance(i - 1)) - (getMonthlyDeposit() * 12);
		}
	}
	else {
		interestEarned = (getEndingBalance(1) - (getMonthlyDeposit() * 12) - getInitialAmount());
	}
	return interestEarned;
}

std::string InvestmentAccount::getEndingBalanceFormatted(int numberOfYears)
{
	//returns formatted and rounded balance for output of EndingBalance
	
	int years = numberOfYears;
	return std::string("$" + format(round(getEndingBalance(years), 2)));
}

std::string InvestmentAccount::getInterestEarnedFormatted(int numberOfYears)
{
	//returns formated and rounded balance for output of InterestEarned
	int years = numberOfYears;
	return std::string("$" + format(round(getInterestEarned(years), 2)));
}

double InvestmentAccount::getInitialAmount()
{
	//returns the user entered initialAmount
	
	return initialAmount;
}

double InvestmentAccount::getMonthlyDeposit()
{
	//returns the user entered monthlyDeposit
	
	return monthlyDeposit;
}

double InvestmentAccount::getAnnualInterestRate()
{
	//returns the user entered annualInterestRate
	
	return annualInterestRate;
}

int InvestmentAccount::getNumberOfYears()
{
	//returns the user entered numberOfYears
	
	return numberOfYears;
}

void InvestmentAccount::setInitialAmount(double amount)
{
	//sets a new user entered initialAmount
	
	double initalAmount = amount;
}

void InvestmentAccount::setMonthlyDeposit(double deposit)
{
	//sets a new user entered monthlyDeposit
	
	double monthlyDeposit = deposit;
}

void InvestmentAccount::setAnnualInterestRate(double interest)
{
	//sets a new user entered annualInterestRate
	
	double annualInterestRate = interest;
}

void InvestmentAccount::setNumberOfYears(int years)
{
	////sets a new user entered numberOfYears
	
	int numberOfYears = years;
}

template<typename T> void InvestmentAccount::printElement(T t, const int& t_width) {

	//formats the output into tabular format for ease of viewing
	
	const char separator = ' ';
	cout << left << setw(t_width) << setfill(separator) << t;
}

void InvestmentAccount::printWithoutMonthlyDeposit()
{
	//function to set headers and output table for user account totals WITHOUT monthlyDeposit
	
	int i;
	const int numWidth = 30;
	const int titleWidth = 25;

	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	printElement("Year", titleWidth);
	printElement("Year End Balance", titleWidth);
	printElement("Year End Earned Interest", titleWidth);
	cout << endl;
	cout << "----------------------------------------------------------------------------" << endl;


	for (int i = 1; i <= getNumberOfYears(); i++) {
		printElement(i, numWidth);
		printElement(getEndingBalanceFormatted(i), numWidth);
		printElement(getInterestEarnedFormatted(i), numWidth);
		cout << endl;
	}

	cout << endl;
	cout << endl;
}

void InvestmentAccount::printWithMonthlyDeposit()
{
	
	//function to set headers and output table for user account totals WITH monthlyDeposit
	
	int i;
	const int numWidth = 30;
	const int titleWidth = 25;

	system("CLS");

	cout << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	printElement("Year", titleWidth);
	printElement("Year End Balance", titleWidth);
	printElement("Year End Earned Interest", titleWidth);
	cout << endl;
	cout << "----------------------------------------------------------------------------" << endl;


	for (int i = 1; i <= getNumberOfYears(); i++) {
		printElement(i, numWidth);
		printElement(getEndingBalanceFormatted(i), numWidth);
		printElement(getInterestEarnedFormatted(i), numWidth);
		cout << endl;
	}


}


//The following method rounds a value to the specified number of places.
//NOTE: It works for most values...but is not guaranteed to work for all values!
//@param value - the value to round
//@param places - the number of places to round
//@returns - the rounded number
double InvestmentAccount::round(double value, int places) {
	const int multiplier = pow(10, places);

	double roundedValue = (int)(value * multiplier + 0.5);
	roundedValue = (double)roundedValue / multiplier;
	return roundedValue;
}

//Formats a double value for output purposes.
//This method will not append with any 0s...so the value should be rounded prior to use.
//@param value - the value to format
//@returns - the formatted value.
std::string InvestmentAccount::format(double value) {
	std::string valueAsString = std::to_string(value);
	std::string formatted;

	bool decimalFound = false;
	int decimalCount = 0;

	int i;
	for (i = 0; i < valueAsString.size(); i++) {
		char currentChar = valueAsString[i];

		if (decimalCount == 2) {
			break;
		}

		if (currentChar == '.') {
			decimalFound = true;
		}
		else if (decimalFound && decimalCount != 2) {
			decimalCount++;
		}

		formatted.append(std::string(1, currentChar));
	}

	return formatted;
}
