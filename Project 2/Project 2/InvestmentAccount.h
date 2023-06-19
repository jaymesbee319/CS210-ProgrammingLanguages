#pragma once

#include <string>

class InvestmentAccount
{

public:
	InvestmentAccount();
	InvestmentAccount(double amount, double interestRate, int years); //monthlyDeposit is 0!
	InvestmentAccount(double amount, double interestRate, double deposit, int years);

	double getEndingBalance(int numberOfYears);  //Calculate the ending balance after number of years
	// Use www.calculators.org/savings/monthly.php to test values
	double getInterestEarned(int numberOfYears); //Calculate the interest earned for number of years

	std::string getEndingBalanceFormatted(int numberOfYears);	//Use format and round to get the ending balance as a decimal to 2 places
	std::string getInterestEarnedFormatted(int numberOfYears);  //Use format and round to get the ending balance as a decimal to 2 places

	double getInitialAmount();
	double getMonthlyDeposit();
	double getAnnualInterestRate();
	int getNumberOfYears();
	void setInitialAmount(double amount);
	void setMonthlyDeposit(double deposit);
	void setAnnualInterestRate(double interest);
	void setNumberOfYears(int years);

	template<typename T> void printElement(T t, const int& width); //setting the template for the output.
	void printWithMonthlyDeposit();
	void printWithoutMonthlyDeposit();


	double round(double value, int places);
	std::string format(double value);


private:
	double initialAmount;
	double monthlyDeposit;
	double annualInterestRate;
	int numberOfYears;
	
};

