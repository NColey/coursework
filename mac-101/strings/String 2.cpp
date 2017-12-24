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
	
	strcpy(str, "\nMy name is ");
	strcat(str, name);
	
	int i=0;
	while(str[i]!='\0')
	{
		str[i]=toupper(str[i]);i++;
	}
	
	/* int j=0;
	while(str[j]!='\0')
	{
		str[j]=tolower(str[j]);j++;
	}	
	*/
	
	cout<<str<<endl;
	system("PAUSE");
	return 0;
}
