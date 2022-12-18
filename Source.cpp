#include <iostream>
#include <iomanip>

using namespace std;

//create the menu
void DisplayMenu() {
	cout << "*************************************" << endl;
	cout << "************ Data Input *************" << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of years:" << endl;
}

int main() {
	//create float variables 
	float initialInvest;
	float monthlyDeposit;
	float annualInterest;
	float years;
	float totalAmount;
	float interestAmount;
	float yearlyTotalInterest;

	//display menu to user
	DisplayMenu();
	//use pause for "Press any key to continue" 
	system("PAUSE");

	//obtain user input for each variable
	cout << endl;
	cout << "*************************************" << endl;
	cout << "************ Data Input *************" << endl;
	cout << "Initial Investment Amount:" << endl;
	cin >> initialInvest;
	cout << "Monthly Deposit:" << endl;
	cin >> monthlyDeposit;
	cout << "Annual Interest:" << endl;
	cin >> annualInterest;
	cout << "Number of years:" << endl;
	cin >> years;

	//total amount is set to the initial amount 
	totalAmount = initialInvest;

	system("CLS");

	//create the top of the chart
	cout << endl;
	cout << "  Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "============================================================" << endl;
	cout << "Year        Year End Balance        Year End Earned Interest" << endl;
	cout << "-------------------------------------------------------------" << endl;

	//use a for loop to continue calculations until the number of years entered has been reached
	for (int i = 0; i < years; i++) {
		//calculate the variables over the time period set by user input
		interestAmount = (totalAmount * (annualInterest / 100));
		totalAmount = totalAmount + interestAmount;

		//output the calculated information into the format of the chart
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interestAmount << endl;
	}
	//set total amount to the starting amount
	totalAmount = initialInvest;

	//create the top of the chart
	cout << endl;
	cout << "   Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "============================================================" << endl;
	cout << "Year        Year End Balance        Year End Earned Interest" << endl;
	cout << "-------------------------------------------------------------" << endl;

	//use a for loop to continue calculations until the number of years entered has been reached
	for (int i = 0; i < years; i++) {
		yearlyTotalInterest = 0;

		for (int j = 0; j < 12; j++) {
			//calculate the variables over the time period set by user input
			interestAmount = (((totalAmount + monthlyDeposit) * (annualInterest / 100)) / 12);

			yearlyTotalInterest = yearlyTotalInterest + interestAmount;

			totalAmount = totalAmount + monthlyDeposit + interestAmount;
		}
		//output the calculated information into the format of the chart
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << setw(5) << " " << "\t\t$" << yearlyTotalInterest << endl;
	}
	cout << endl;
	cout << "Thank you for using Airgead Banking";
	return 0;
}