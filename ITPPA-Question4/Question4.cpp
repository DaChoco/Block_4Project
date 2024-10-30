#include <iostream>
#include <string>

using namespace std;

void createAccount(string &name,int &accountNumber, double &balance) { //Question 4.1.1 (Udacity Team, 2024)
	cout << "Hello user, can you please type your full name: ";
	getline(cin >> ws, name);
	cout << endl;

	cout << "Now you must type a 10 digit account number: ";
	cin >> accountNumber;
	cout << endl;

	cout << "Now type your initial deposit please (Make sure it is greater than 0): ";
	cin >> balance;

	while (balance <= 0) {
		cout << "Now type your initial deposit please: ";
		cin >> balance;
	}
	cout << endl;

	cout << "Accout created successfully\n" << endl;
	
}

double depositMoney(double &balance) { //Question 4.2.1
	double userDeposit = 0;
	
	while (userDeposit <= 0) {
		cout << "How much money would you like to input into your account? (Input must be greater than 0): ";
		cin >> userDeposit;
		cout << endl;
	}
	balance = balance + userDeposit;
	return balance;
}

double withdrawMoney(double &balance) { //Questions 4.3.1
	double userWithdraw = 0;

	while (userWithdraw <= 0) {
		cout << "How much money would you like to withdraw from your account? (Must be greater than 0): ";
		cin >> userWithdraw;
		cout << endl;

	}
	balance = balance - userWithdraw;
	return balance;
}

string checkBalance(double& balance) { //Question 4.4.1
	return "Account Balance: " + to_string(balance);
}

string displayAccountDetails(const string& name, const int& accountNumber, const double& balance) {
	return "---Account Details--- \nAccount Holder: " + name + "\nAccount Number: " + to_string(accountNumber) + "\nCurrent Balance: " + to_string(balance);
}

void drawMenu() {
	cout << "\n--- Bank Account Management system --- \n" << endl;
	cout << "1. Create Account \n2.Deposit Money \n3.Withdraw Money \n4.Check Balance \n5.Display Account Details \n6.Exit" << endl;
}

int main() {
	int choice = 0;

	string name = ""; //(W3Schools, 2024)
	int accountNumber = 0;
	double balance = 0;

	while (choice != 6) {
		drawMenu();
		cout << "Enter your choice (1-6): ";
		cin >> choice;

		if (choice == 1) {
			createAccount(name, accountNumber, balance);
		}	
		else if (choice == 2) {
			cout << "Current Balance: R" + to_string(depositMoney(balance)) << endl;

		}
		else if (choice == 3) {
			cout << "Current Balance: R" + to_string(withdrawMoney(balance)) << endl;;
		}
		else if (choice == 4) {
			cout << "Current Balance: R" + checkBalance(balance) << endl;

		}
		else if (choice == 5) {
			cout << displayAccountDetails(name, accountNumber, balance) << endl;

		}
		
	}
	cout << "\nExiting this system, goodbye kind individual";
	return 0;
}