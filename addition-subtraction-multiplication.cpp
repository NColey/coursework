#include <iostream>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main() {
	
	// Declare numberA and numberB as floating point variables.
	
	double numberA, numberB;
	
	//Prompt and input two values to be added together.
	
	cout << "Input two numbers for addition and press ENTER: " <<endl;
	cout << endl;
	cout << "First number: "; //prompt first number
	cin >> numberA; 
	cout << endl;
	cout << "Second number: "; //prompt second number
	cin >> numberB;
	cout << endl;
	 
	//Add numberA and numberB and output results.
	
	cout << "The result is:" << endl << endl << (numberA + numberB) <<endl <<endl;
	
	
	//Prompt and input two values to be subtracted.
	
	cout << "Input two numbers for subtraction and press ENTER: " <<endl;
	cout << endl;
	cout << "First number: "; //prompt first number
	cin >> numberA; 
	cout << endl;
	cout << "Second number: "; //prompt second number
	cin >> numberB;
	cout << endl; 
	
	//Subtract numberB from numberA and output results.
	
	cout << "The result is:" << endl << endl << (numberA - numberB) <<endl <<endl;
	
	//Prompt and input two values to be multiplied.
	
	cout << "Input two numbers for multiplication and press ENTER: " <<endl;
	cout << endl;
	cout << "First number: "; //prompt first number
	cin >> numberA; 
	cout << endl;
	cout << "Second number: "; //prompt second number
	cin >> numberB;
	cout << endl;
	 
	//Multiply numberA and numberB and output results.
	
	cout << "The result is:" << endl << endl << (numberA * numberB) <<endl <<endl;
	
	//system ("PAUSE");
		
	return 0;
	
	
}