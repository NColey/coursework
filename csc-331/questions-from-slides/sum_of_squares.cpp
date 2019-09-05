/*
 * CSC331-1900
 *
 * Write a function that uses a loop to find the sum of the squares of all integers between 1 and n. What is the order of your function?
 * The program below assumes that the integers squared & summed includes 1 and n.
 */
#include <iostream>
using namespace std;

int find_sum_of_squares(int n) {
    int sum = 0;

    for(int x = 1; x <= n; x++) {
        sum += x*x;
    }

    cout << sum << endl;
    return 0;
}

int main() {
    int n;

    cout << "Please enter a value for n: ";
    cin >> n;

    find_sum_of_squares(n);
}