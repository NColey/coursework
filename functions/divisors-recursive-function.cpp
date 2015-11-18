//this function prints all the divisors of n
//by finding the lowest divisor, i, and then
//rerunning itself on n/i, the remaining quotient

#include <iostream>
#include <cmath>

using namespace std;

void get_divisors(int n) {
	int i;
	double sqrt_of_n = sqrt((double) n);
	
	for(i=2; i<=sqrt_of_n; i++)
	if (n%i==0){   //If i divides n evenly
		cout<<i<<", ";  //print i
		get_divisors(n/i);  //factor n/i
		return;              //and exit
	}
	//If no divisor is found, then n is prime
	//Print n and make no further calls.
	
	cout<<n;
}

int main(){
    get_divisors(10); //prints: 2, 5
}
