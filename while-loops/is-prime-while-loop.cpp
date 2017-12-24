#include <iostream>
#include<stdlib.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int y;
	cout << "Find out if a number is prime" <<endl<<endl<<endl;
	cin>> y;
	
	int i=2, flag=0;
	while (i<y)
	{
		if(y%i==0)
		{
			flag=1;
						
		}
		i++;
		
	}
		
		if(flag==0)
		{
			cout<< "its prime" <<endl;
		}
		else
		{
			cout<< "its not prime" <<endl;
		}
		

	
	system ("PAUSE");
	
	return 0;
}
