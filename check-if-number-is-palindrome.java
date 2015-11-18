//Natalie Coley
//ID: 23263431
//MAC 190 Section 5431
//Homework 2
//Write a program to check if a number is palindrome

import java.util.Scanner;

public class NumberPalindrome {
	
	public static void main(String[] args) {
		
		int number, reverse = 0;
		
		
		System.out.println("Enter a number");
		Scanner integer = new Scanner(System.in);
		number=integer.nextInt();
		
		int palindrome = number;
		
		while (number > 0) {
			int remainder = number % 10;
			reverse = reverse * 10 + remainder;
			number = number/10;
		}
		
		if (palindrome == reverse) {
			System.out.println("Number is a palindrome");
		}
		else if (number != reverse) {
			System.out.println("Number is not a palindrome");
		}

}

}
