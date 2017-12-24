//Natalie Coley
//ID: 23263431
//MAC 125 Section 5243
//Assignment 2
//Write a program to perform simple arithmetic operations using functions.

#include <iostream>

using namespace std;

//declare functions

int add(int a, int b);
int subtract(int a, int b);
int multiply (int a, int b);
double divide (double a, double b);
int mod(int a, int b);

int main(int arc, char *argv[]) {

char response;

//loop for calculator menu	

do {
	
	//Display menu
	
	int option, x, y;
	
	cout<<"MENU"<<endl<<endl<<endl<<endl<<"1. Add"<<endl<<endl<<"2. Subtract"<<endl<<endl<<"3. Multiply"<<endl<<endl<<"4. Divide"<<endl<<endl<<"5. Mod"<<endl<<endl<<endl;
	cout<<"Select your choice, enter the corresponding number and press ENTER."<<endl<<endl<<endl;
	cin>>option;
	cout<<endl<<endl;
	cout<<"Enter two integers"<<endl<<endl;
	cin>>x;
	cout<<endl;
	cin>>y;
	cout<<endl<<endl;
	
	//Addition option
	
	if (option==1) {
		
		int addition;
		addition = add(x, y); //call function
		cout<<"The result is "<<addition;
		cout<<endl<<endl;
		
	}
	
	//Subtraction option
	
	else if (option==2) {
		
		int subtraction;
		subtraction = subtract(x, y); //call function
		cout<<"The result is "<<subtraction;
		cout<<endl<<endl;
		
	}
	
	//Multiplication option
	
	else if (option==3) {
		
		int multiplication;
		multiplication = multiply(x, y); //call function
		cout<<"The result is "<<multiplication;
		cout<<endl<<endl;
		
	}
	
	//Division option
	
	else if (option==4) {
		
		double division;
		division = divide(x, y); //call function
		cout<<"The result is "<<division;
		cout<<endl<<endl;
		
	}
	
	//Modulo option
	
	else if (option==5) {
		
		int modulo;
		modulo = mod(x, y); //call function
		cout<<"The result is "<<modulo;
		cout<<endl<<endl;
		
	}
	
	else {
		
		cout<<"ERROR. Must select an option between 1 and 5.";
	}
	
	//Decide whether to Quit or Continue
	
	cout<<"Press C to continue and select another option or enter any other letter to quit"<<endl<<endl;
	cin>>response;
	cout<<endl<<endl;
	
}

//continue calculator loop
	
while (response =='c'||response =='C');

return 0;

}

//Define addition function

int add (int a, int b)
{
	int result;
	result = a+b;
	return result;	
}

//Define subtraction function

int subtract (int a, int b)
{
	int result;
	result = a-b;
	return result;
}

//Define multiplication function

int multiply (int a, int b)
{
	int result;
	result = a*b;
	return result;
}

//Define division function

double divide (double a, double b)
{
	int result;
	result = a/b;
	return result;
}

//Define modulo function

int mod (int a, int b)
{
	int result;
	result = a%b;
	return result;
}

