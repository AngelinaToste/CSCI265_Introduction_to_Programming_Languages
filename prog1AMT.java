/*
 * Angelina Toste
 * 1399403
 * angelina.toste@und.edu
 *
 * Program 1:
 *     Part 1- convert from seconds
 *     Part 2- convert to dollars
 *     Part 3- work with output
 *
*/

import java.util.Scanner;

public class prog1AMT {

	public static void main (String[] args){
		Scanner keyboard = new Scanner(System.in);

		//PART 1
		System.out.println("PART 1");
		
		System.out.print("Seconds: ");
		int seconds = keyboard.nextInt();

		int hours = seconds/3600;
		int minutes = (seconds % 3600) / 60;
		seconds = (seconds % 3600) % 60;

		System.out.println("This is " + hours + " hours, " + minutes + " minutes, and " + seconds + " seconds.");

		System.out.println();
		
		//PART 2
		System.out.println("PART 2");

		System.out.print("Quarters: ");
		int quarters = keyboard.nextInt();

		System.out.print("Dimes: ");
		int dimes = keyboard.nextInt();

		System.out.print("Nickels: ");
		int nickels = keyboard.nextInt();

		System.out.print("Pennies: ");
		int pennies = keyboard.nextInt();

		float total = (quarters * 25) + (dimes * 10) + (nickels * 5) + pennies;
		total = total/100;

		System.out.println("This is equal to $" + total);

		System.out.println();
		
		//PART 3
		System.out.println("PART 3");
		String firstName, lastName, address, city, state, zipcode, junk;
		
		junk = keyboard.nextLine();
		System.out.print("First Name: ");
		firstName = keyboard.nextLine();
		

		//junk = keyboard.nextLine();
		System.out.print("Last Name: ");
		lastName = keyboard.nextLine();
		

		//junk = keyboard.nextLine();
		System.out.print("Address: ");
		address = keyboard.nextLine();
		

		//junk = keyboard.nextLine();
		System.out.print("City: ");
		city = keyboard.nextLine();
		

		//junk = keyboard.nextLine();
		System.out.print("State: ");
		state = keyboard.nextLine();


		//junk = keyboard.nextLine();
		System.out.print("Zipcode: ");
		zipcode = keyboard.nextLine();


		System.out.println();

		// using 1 print statement
		System.out.println( firstName + " " + lastName + "\n" + address + "\n" + city + ", " + state + "  " + zipcode);

		System.out.println();
		
		// using 6 print statement
		System.out.print(firstName + " " );
		System.out.println(lastName );
		System.out.println(address);
		System.out.print(city + ", ");
		System.out.print(state + "  ");
		System.out.print(zipcode);

		
	}

}
