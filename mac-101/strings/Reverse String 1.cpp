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

	
	int i=0;
	while(str[i]!='\0')
	{
		i++;
	}
	cout << endl<< endl;

	for(char a = i; i >= 0; i-- )
	cout << str[i];
	cout << endl;


}

