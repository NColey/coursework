#include <iostream>
using namespace std;

int main()
{	
	int y, res=1;
	cout << "Enter a number" <<endl;
	cin>>y;
	int i=1;
	while(i<=y)
	{
		res=res*i;
		i++;
	}
	cout<<res;
	
	return 0;
	
}




