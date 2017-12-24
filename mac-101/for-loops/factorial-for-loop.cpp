#include <iostream>
using namespace std;

int main()
{	
	int y, res=1;
	cout << "Enter a number" <<endl;
	cin>>y;
	for (int i=1;i<=y;i++)
	{
			
		res=res*i;	
		
	}
	
	cout<<res;
	
}

