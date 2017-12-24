#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

int main(){
	
	char the_string[81], *p;
	
	cout<< "Input a string to parse: ";
	cin.getline(the_string, 81);
	p = strtok(the_string, "+ "); 
	while (p !=NULL) {            
		cout<<p<<endl;
	p=strtok(NULL, ", ");  
	}
	system("PAUSE");
	return 0;
	
}

/*

if the input is a,s,d,f
in this scenario the output will be a,s,d,f because there is no plus used as a tokenizer

if the input is a,s,d,f+a,w,q,p
the output will be:
	
	a,s,d,f
	a
	w
	q
	p
	
	because it needs the + to get into the loop

*/
