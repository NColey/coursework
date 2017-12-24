#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

void even_odd(int);

int main(int arc, char *argv[]) {
	even_odd(99);
	return 0;
}

void even_odd (int a)
{
	if(a%2==0)
	{
		cout<<"even";
	}
	else
	{
		cout<<"odd";
	}
	//since we have void we dont need to return anything
}


