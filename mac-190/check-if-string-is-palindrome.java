//Natalie Coley
//ID: 23263431
//MAC 190 Section 5431
//Homework 2
//Write a program to check if a string is palindrome

import java.util.Scanner;
public class StringPalindrome {
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        
        String sentence;
        int i;
        
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a string");
        sentence = input.nextLine();
        
        int length = sentence.length();
        int n = (length - 1);
        
        for(i=0; i<=n; i++){
            
            if (sentence.charAt(i) != sentence.charAt(length - i - 1)) {
            	
            	System.out.print("String is not a palindrome");
            	
            }
            else {
            	
            	System.out.print("String is a palindrome");
            }
        }
        
    }
}
    
