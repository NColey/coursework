#include<iostream>
using namespace std;

int main()
{
	int input, result=0, x, comp;
	cout<"Enter number\n";
	cin>>input;
	comp=input; //save the initial value even when it is modified later in the code
	
	for(int i=0;i<3;i++)
	{
		x=input%10; //to extract the last digit ex. 5 is last digit of 235
		x=x*x*x; //cube the number
		result = result+x; //store the sum (result =1, result =1=125, result = 126+27)
		input=input/10;  //to get the remaining part
	}
	
	//cout<<result;  //ex. 153 - 1^3 =1, 5^3 = 125, 3^3 = 27 -- 1+125=27 = 153
	
	if(comp==result)
	{
		cout<<result<<" is an armstrong number\n";
	}
	else
	{
		cout<<comp<<" is not an armstrong number\n";
	}
		
return 0;

}
