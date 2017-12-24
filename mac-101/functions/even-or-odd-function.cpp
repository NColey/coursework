#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int even_odd(int);

int main(int argc, char *argv[]) {
	 
	 int x;
	 cout<<"Enter a number"<<endl<<endl;
	 cin>>x;
	 cout<<endl<<endl;
	 
	 int result = even_odd(x);
	 cout<<result<<endl;
}


int even_odd(int x){
	
	if ((x%2)==0)
	{ 
	return true; 
    }
	else 
		{
	return false; 
	}
	
}


