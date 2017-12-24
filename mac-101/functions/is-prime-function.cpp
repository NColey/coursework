#include <iostream>

using namespace std;
bool prime(int);

int main(int argc, char *argv[]) {
	int x;
	cout<<"Enter a number"<<endl<<endl;
	cin>>x;
	
	int result=prime(x);
	if(result==true)
	{
		cout<<"Number is prime";
	}
	else
	{
		cout<<"Number is not prime";
	}
				return 0;
}


bool prime(int x)
{
	int i=2;
	bool isprime=true;
	while(i<x)
	{
		if(x%i==0) {
			isprime =false;
		}
		i++;
	}
	return isprime;
}


