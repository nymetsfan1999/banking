// Banking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
float balance;
void getBalance() {
	ifstream BalanceFile;
	BalanceFile.open("balance.txt");
	BalanceFile >> balance;
	BalanceFile.close();
}
void updateBalance() {
	ofstream balanceFile;
	balanceFile.open("balance.txt");
	balanceFile << balance;
	balanceFile.close();

}
int deposit() {
	float amount;
	cout << "Amount to Deposit: $";
	cin >> amount;
	balance = balance + amount;
	cout << "Your new balance is: $" << balance << "." << endl;
	return balance;
}
int withdraw() {
	float amount;
	cout << "Amount to Withdraw: $";
	cin >> amount;
	balance = balance - amount;
	cout << "Your new balance is: $" << balance << "." << endl;
	return balance;
}
void displayLogo() {
	ifstream logo;
	string line;
	logo.open("logo.txt");
	if (logo.is_open()) {
		while (getline(logo, line)) {
			cout << line << '\n';
		}
	}
}


int main()
{

	char again = 'y';
	int id, option;
	displayLogo();
	getBalance();
	cout << "You have $" << balance << " in your account." << endl;
	while (again = 'y') {
		cout << "What would you like to do today?" << '\n' << "[1]Deposit"
			"\n[2]Withdraw" << endl;
		cout << " Please select an option: ";
		cin >> option;
		if (option == 1) { deposit(); }
		if (option == 2) { withdraw(); }
		cout << "Is there anything else you'd like to do today? [y/n] ";
		cin >> again;
		if (again == 'n') {
			cout << "Have A Nice Day!" << endl;
			updateBalance();
			break;
		}
	}
	return 0;
}

