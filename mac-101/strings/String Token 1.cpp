#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

int main(){
	
	char the_string[81], *p;
	
	cout<< "Input a string to parse: ";
	cin.getline(the_string, 81);
	p = strtok(the_string, ", "); //strtok is the string tokenizer
	while (p !=NULL) {            //if the string is NULL it means there is no string at all. if p is not null p = string tokenizer(null, ", ")
		cout<<p<<endl;
	p=strtok(NULL, ", ");  //if you put the_string here instead of null it will just keep repeating the first character. null gets rid of the first and then gets the rest part of the string
	}
	system("PAUSE");
	return 0;
	
}

/*if s,a,e,r,t,y is entered it prints

s
a
e
r
t
y

because it prints p and then endline

delimiter separates the tokens. if you change the tokens it must match the program as well

*/
