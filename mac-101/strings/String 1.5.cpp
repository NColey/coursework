#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int main() {
	string str, name, addr, work;
	
	//Get three strings from the user.
	
	cout<<"Enter name and press ENTER: ";
	cin.getline(cin, name);   //cin>>name
	cout <<"Enter address and press ENTER: ";
	cin.getline (cin, addr);
	cout<<"Enter workplace and press ENTER: ";
	cin.getline(cin, work);
	
	//Build the output string, and then print it
	

	
	str = "\nMy name is " + name + ", " + "I live at " + addr + "n\and I work at" + work + ".\n";
	cout <<str << endl;
	
	system("PAUSE");
	return 0;
}
