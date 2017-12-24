#include <iostream>
using namespace std;

int factorial(int);

int main()
{	
	int y, res;
	cout << "Enter a number" <<endl;
	cin>>y;
	
	int result=factorial(y);
	
	cout<<result;
	
}

int factorial (int y)
{
	int res=1;
	for (int i=1;i<=y;i++)
	{
			
		res=res*i;	
		
	}
	return res;
}
