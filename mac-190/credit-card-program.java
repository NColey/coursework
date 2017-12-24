//Natalie Coley
//ID: 23263431
//MAC 190 Section 5431
//Homework 2
//Homework 2 Credit Card

import java.util.Scanner;
public class CreditCard {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//initialize variables
		String customerName;
		String memberLevel;
		String paymentTime;
		String interestRate = "";
		double lateFee = 0.0;
		double minPayment = 0.0;
		double currentBalance = 0.0;
		double percentToPrinciple = 0.0;
		
		Scanner number = new Scanner(System.in);
		Scanner input = new Scanner(System.in);
		
		//get customer information
		System.out.println("Credit Card program by Natalie Coley");
		System.out.println("Please enter a customer name: ");
		customerName = input.nextLine();
		System.out.println("Please enter the customer's member level: ");
		memberLevel = input.nextLine();
		
		if (!memberLevel.equalsIgnoreCase("Silver") && !memberLevel.equalsIgnoreCase("Platinum") && !memberLevel.equalsIgnoreCase("Gold")){
			System.out.println("Error! Invalid member level");
			System.exit(1);
		}
		
		System.out.println("Please enter the current balance: ");
		currentBalance=number.nextDouble();
		System.out.println("Was the payment made late?: ");
		paymentTime = input.nextLine();
		
		if(!paymentTime.equalsIgnoreCase("Yes") && !paymentTime.equalsIgnoreCase("No")){
			System.out.println("Error! Must enter if payment was late or on time");
			System.exit(1);
		}
		
		System.out.println("======================");
		
		//set late payment interest rates and fees and the minimum payment
		
		if(paymentTime.equalsIgnoreCase("Yes")){
		
			if (memberLevel.equalsIgnoreCase("Silver")){
			
			interestRate = "3% per month";
			lateFee = 20.0;
			minPayment = (currentBalance * 0.02) + (currentBalance * 0.03) + 20;
			
			}
			else if (memberLevel.equalsIgnoreCase("Platinum")){
			
			interestRate = "2% per month";
			lateFee = 0.0;
			minPayment = (currentBalance * 0.02) + (currentBalance * 0.02);
			}
			else if (memberLevel.equalsIgnoreCase("Gold")){
			
			interestRate = "4% per month";
			lateFee = 0.0;
			minPayment = (currentBalance * 0.02) + (currentBalance * 0.04);
			}
		}
		
		//set interest and minimum payment for on time payments
		
		else if(paymentTime.equalsIgnoreCase("No")){
			
			if (memberLevel.equalsIgnoreCase("Silver")){
				
				interestRate = "3% per month";
				minPayment = (currentBalance * 0.02) + (currentBalance * 0.03);
				
				}
				else if (memberLevel.equalsIgnoreCase("Platinum")){
				
				interestRate = "1% per month";
				minPayment = (currentBalance * 0.02) + (currentBalance * 0.01);
				}
				else if (memberLevel.equalsIgnoreCase("Gold")){
				
				interestRate = "2% per month";
				minPayment = (currentBalance * 0.02) + (currentBalance * 0.02);
				}
		}
		
		//calculate percentage of payment that goes to principal
		double paymentToPrinciple = currentBalance * 0.02;
		percentToPrinciple = 100 * (paymentToPrinciple / minPayment);
		
		//Display statement for late payment
		if(paymentTime.equalsIgnoreCase("Yes")){
			
		System.out.println("Statement");
		System.out.println("======================");
		System.out.println("Billing information for " +customerName);
		System.out.println("Customer level: " +memberLevel);
		System.out.printf("Credit card balance: $%.2f", currentBalance);
		System.out.println("\nInterest rate for late payment: " +interestRate);
		System.out.printf("Late fee: $%.2f", lateFee);
		System.out.printf("\nRequired minimum payment: $%.2f", minPayment);
		System.out.printf("\nAmount going to principle: $%.2f", paymentToPrinciple);
		System.out.printf("\nPercent of minimum payment going to principle: $%.1f%%", percentToPrinciple);
		
		}
		
		//Display statement for on time payment		
		else if(paymentTime.equalsIgnoreCase("No")){
			
			System.out.println("Statement");
			System.out.println("======================");
			System.out.println("Billing information for " +customerName);
			System.out.println("Customer level: " +memberLevel);
			System.out.printf("Credit card balance: $%.2f", currentBalance);
			System.out.println("\nInterest rate: " +interestRate);
			System.out.printf("Required minimum payment: $%.2f", minPayment);
			System.out.printf("\nAmount going to principle: $%.2f", paymentToPrinciple);
			System.out.printf("\nPercent of minimum payment going to principle: $%.1f%%", percentToPrinciple);
			
		}
	}

}
