#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

int main(){
	
	char the_string[81], *p;
	
	double sum=0;
	
	cout<< "Input a string to parse: ";
	cin.getline(the_string, 81);
	p = strtok(the_string, ", "); 
	while (p !=NULL) {            
		sum=sum+atof(p);
	p=strtok(NULL, ", ");  
	}
	
	cout<<sum<<" ";
	
	
	system("PAUSE");
	return 0;
	
}

