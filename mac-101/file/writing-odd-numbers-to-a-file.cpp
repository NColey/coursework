#include<iostream>
#include <fstream>
using namespace std;

int even(int x);

int main() {
    char filename[200];

    cout << "Enter a file name and press ENTER: ";
    cin.getline(filename, 199); //the name of the file that you want to create
    ofstream file_out(filename);
    if (! file_out) {   //if the file is not created
        cout << "File " << filename << " could not be opened.";  //then the file cannot be opened
        return -1;
    }
    
      
    cout << "File " << filename << " was opened.";
    
    	for (int i=1; i<=100; i=i+2)
			{
			file_out<<i<<endl;
			}
			
    file_out.close();
    return 0;
}


