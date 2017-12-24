#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
	
	char the_string[81]="5,2,3,4,5", *p;
	clock_t begin=clock();
	
	double sum=0;
	
	cout<< "Input a string to parse: ";

	p = strtok(the_string, ", "); 
	while (p !=NULL) {            
		sum=sum+atof(p);
	p=strtok(NULL, ", ");  
	}
	
	cout<<sum<<" ";
	clock_t end=clock();
	cout<<"total time is"<<double(end-begin);
	
		
	system("PAUSE");
	return 0;
	
}

