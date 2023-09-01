/*
 *
 * Angelina Toste
 * 1399403
 * angelina.toste@und.edu
 * 
 * Program 3:
 *This program consists of the following functions
 *  square - returns the square of the given value ( square(3) returns 9)
 *  summation - returns the summation of 1 to the value passed to the function. It will be assumed that
 *      this value is positive
 *  sumOfSquare - This function  returns the sum of the squares from 1 to value
 *  rectangle - draws the outline on the screen of a rectangle with the specified width and height. uses character
 *      to draw the outline. Uses fillChar for all characters inside the outline. Uses a blank space as the fill
 *      character when not specified. (there are two instances of this function for this flexibility)
 *  inputWithinRange - will ask for an integer value, using the provided prompt. The value must be
 *       inclusively within lowerLimit and upperLimit, if not, continue to ask for a value until the entered
 *       value is within the provided range. Once a valid value has been entered return it from the function
 *       (There are two instances of this function to account for when lowerLimit is not provided which makes
 *       upperLimit = lowerLimit and the lowerLimit is reset to 0.
 *  isAFactor -  This function will return true if the second argument is a factor of (divides evenly into)
 *       the first argument, otherwise, false is returned
 */


import java.util.Scanner;

public class Prog3AMT
{
	public static Scanner keyboard = new Scanner(System.in);
			
    public static int square(int value)
    {
	    int result = value * value;
	    return result;
    }


    public static int summation (int value)
    {

        int sum = 0;

	    for(int x = value; x <= value && x!=0; x--)
	    {

		    sum = sum + x;
	    }

	    return sum;
    }


    public static int sumOfSquare(int value)
    {
	    int sum = 0;

		for(int x = value; x <= value && x!=0; x--)
		{

			sum = sum + square(x);

		}

		return sum;
    }


    public static void rectangle(int width, int height, char character, char fillChar)
    {
    	//prints the characters for the first row of the rectangle using width
	    for(int x = 1; x <= width; x++)
	    {

		   System.out.print(character);

	    }
	    System.out.println();

	    //prints the next rows using the values for height to determine how many rows and width for the number of chars per row
	    for(int h = 2; h < height; h++)
	    {

	        for(int y = 1; y <= width; y++)
	        {

		        if (y == 1 ) 
		        {
	   		        System.out.print(character);
		        }
		        else if (y == width)
		        {
			        System.out.println(character);
		        }
		        else
		        {
			        System.out.print(fillChar);
		        }
	        }
	    }
	    // works the same as the for loop for row 1. prints the last row of the rectangle
	    for(int x = 1; x <= width; x++)
	    {

	   	    System.out.print(character);

	   	}

     }


    public static void rectangle(int width, int height, char character)
    {
    	// adds flexibility to the previous function by allowing fillChar to have default value of ' '
	    rectangle(width, height, character, ' ');
    }

    
    public static int inputWithinRange(String prompt, int lowerLimit, int upperLimit)
    {
    	
	    int value = 0;
	    System.out.print(prompt);
	    value = keyboard.nextInt();

	    while (value < lowerLimit || value > upperLimit)
	    {
		    System.out.print(prompt);
	        value = keyboard.nextInt();
	    }
	    
	    return value;
	    
    }


    public static int inputWithinRange(String prompt, int upperLimit)
    {
    	// adds flexibility to the previous function by allowing lowerLimit to default to 0
	    return inputWithinRange(prompt, 0, upperLimit);
    }
    
    
    
    public static boolean isAFactor(int value1, int value2)
    {
        if(value1 % value2 == 0)
        {
    	    return true;
        }
        else
        {
    	    return false;
        }
    }


    public static void main(String[] args)
    {
	
	    int A = 3;
    
        System.out.println(square(A));

	    System.out.println(summation(A));

	    System.out.println(sumOfSquare(A));

	    rectangle(6, 8,'A', '.');
	    System.out.println();
	    rectangle(6, 8,'A');

	    System.out.println();

	    System.out.println(inputWithinRange("Enter an Integer: ", 0, 5));
	    System.out.println(inputWithinRange("Enter an Integer: ", 5 ));

	    System.out.println(isAFactor(25,5));
	    System.out.println(isAFactor(25,3));


    }
}
