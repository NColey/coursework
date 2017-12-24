#include<iostream>
using namespace std;

int main()
{
	int i, space, rows, k=0;
	cout<<"Enter the number of rows: ";
	cin>>rows;
	for(i=1; i<=rows;++i)
	{
	
		for(space=1; space<=rows-i;++space)
		{
			cout<<"  ";
		}
		while (k!=2*i-1)
		{
			cout<<"* ";
			++k;
		}
		k=0;
		cout<<"\n";
	}

		for(i=rows-1;i>0;i--)
		{
			for(space=rows-i;space>0;--space)
			{
				cout<<"  ";
	
			}
			while(k!=2*i-1)
			{
				cout<<"* ";
				++k;
			}
			k=0;
			cout<<"\n";
		}
		
return 0;

}
