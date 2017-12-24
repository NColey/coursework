#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int main() {
	char str[100];
	char name[50];
		
	//Get three strings from the user.
	
	cout<<"Enter a word and press ENTER: ";
	cin.getline(name, 99);
	
	strcpy(str, name);

	int length = strlen(str);
	for(int i=length; i>=0; i--)
	{
		cout<<str[i];
	}
	
}

