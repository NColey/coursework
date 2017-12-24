#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

double get_number();

int main() {
	
	double x;
	
	while(true){
		cout<<"Enter a number (press ENTER to exit): ";
		x = get_number();
		if (x==0.0)
			break;
		cout<<"The square root of x is: "<<sqrt(x);
		cout<<endl;
	}
	system("PAUSE");
	return 0;
	
}

	
//Get-number function.
//Get number input by the user, taking only the first numeric input entered.
//If user pressses ENTER with no input, then return a default value of 0.0.
	
	double get_number() {
		char s[100];
		
		cin.getline(s, 99);
		if (strlen(s) == 0)
			return 0.0;
		return atof(s);
	}
