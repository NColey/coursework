//Natalie Coley
//23263431
//MAC125
//Assignment 1
//Write a program that breaks down a given number of cents into units of currency.

#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	//declare and initialize the appropriate variabls
	
	int x, dollars, quarters, dimes, nickels, pennies;
	
	cout << "Please enter the number of cents to break down and press ENTER: " <<endl<<endl;
	cin >> x;
	cout <<endl;
	
	//find the number of each type of currency
	
	dollars = x/100;
	quarters = (x-(100*dollars))/25;
	dimes = (x- (100*dollars) - (25*quarters))/10;
	nickels = (x- (100*dollars) - (25*quarters) - (10*dimes))/5;
	pennies = (x - (100*dollars) - (25*quarters) - (10*dimes) - (5*nickels));
	
	//display the results
	
	cout << "This corresponds to "<<dollars<<" dollars, "<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels, and "<<pennies<<" pennies."<<endl<<endl;
	
	system("PAUSE");
	return 0;
}
