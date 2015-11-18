#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    int c;   // input character
    int i;   // loop counter
    char filename[81];
    
    char input_line[81];
    cout << "Enter a file name and press ENTER: ";
    cin.getline(filename, 199); //the name of the file that you want to create
    ofstream file_out(filename);
    if (! file_out) {   //if the file is not created
        cout << "File " << filename << " could not be opened.";  //then the file cannot be opened
        return -1;
    }
    
      
    cout << "File " << filename << " was opened.";
    
    	for (int i=0; i<=100; i=i+2)
			{
			file_out<<i<<endl;
			}
			
    file_out.close();

    /*cout << "Enter a file name and press ENTER: ";
    cin.getline(filename, 80);  remove these lines as you already got the filename at the top*/

    ifstream file_in(filename); //open the input file stream */

    if (! file_in) {
        cout << "File " << filename << " could not be opened." << endl;
        system("PAUSE");
        return -1;
    }

    while (1) {  //while true
        for (i = 1; i <= 24 && ! file_in.eof(); i++) {  /*i equals one, i is less than or equal to 24 (assuming file has 24 lines) and not end of file*/
            file_in.getline(input_line, 80); //it will read one line at a time
            cout << input_line << endl;
        }
        if (file_in.eof())
            break;
        cout << "More? (Press 'Q' and ENTER to quit.)";
        cin.getline(input_line, 80);
        c = input_line[0];
        if (c == 'Q' || c == 'q')
            break;
    }
    system("PAUSE");
    return 0;
}
