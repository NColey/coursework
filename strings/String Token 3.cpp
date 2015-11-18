#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

int main(){

	char *p;
	string the_string;
	
	cout<<"Input a string to parse: ";
	cin.getline(the_string, 80);
	p=strtok(the_string, "+, ");
	while (p !=NULL) {
			cout << p << endl;
	p=strtok(NULL, ", ");
	}
		
	system ("PAUSE");
	return 0;
}
