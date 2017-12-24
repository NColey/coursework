#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

int main(){
	
	char the_string[81]="5,2,3,4,5", *p;
	
	double sum=0;
	
	cout<< "Input a string to parse: ";
	
	p = strtok(the_string, ", "); 
	while (p !=NULL) {            
		sum=sum+atof(p);
	p=strtok(NULL, ", ");  
	}
	
	cout<<sum<<" ";
	
	
	system("PAUSE");
	return 0;
	
}

