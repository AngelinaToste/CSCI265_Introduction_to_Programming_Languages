//Angelina Toste
/* 1399403
 * angelina.toste@und.edu
 *
 * Program 3:
 * This program consists of the following functions
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
 *  isAFactor -  This function will return true or 1 if the second argument is a factor of (divides evenly into)
 *       the first argument, otherwise, false or 0 is returned
 *
 */

#include <string.h>

#include <iostream>
using namespace std;


int square(int value)
{
	int result = value * value;
	return result;
}


int summation (int value)
{

    int sum = 0;

	for(int x = value; x <= value && x!=0; x--){

		sum = sum + x;
	}

	return sum;
}


int sumOfSquare(int value)
{
	int sum = 0;

		for(int x = value; x <= value && x!=0; x--){

			sum = sum + square(x);

		}

		return sum;
}


void rectangle(int width, int height, char character, char fillChar)
{
       //prints the characters for the first row of the rectangle using width
	   for(int x = 1; x <= width; x++){

		  cout << character;

	   }
	   cout << endl;

       // prints the next rows using the values for height to determine how many rows and width for the number of chars per row
	   for(int h = 2; h < height; h++){

	       for(int y = 1; y <= width; y++){

		       if (y == 1 ) {
	   		       cout << character;
		       }
		       else if (y == width){
			       cout << character << endl;
		       }
		       else{
			       cout << fillChar;
		       }
	       }
	   }
	   // works the same as the for loop for row 1. prints the last row of the rectangle
	   for(int x = 1; x <= width; x++){

	   		   cout << character;

	   	   }

}


void rectangle(int width, int height, char character)
{
	// adds flexibility to the previous function by allowing fillChar to have default value of ' '
	rectangle(width, height, character, ' ');
}


int inputWithinRange(string prompt, int lowerLimit, int upperLimit){

	cout << prompt;
	int value;
	cin >> value;

	while (value < lowerLimit || value > upperLimit){
		cout << prompt;
	    cin >> value;
	}
	return value;

}


int inputWithinRange(string prompt, int upperLimit)
{
	// adds flexibility to the previous function by allowing lowerLimit to default to 0
	return inputWithinRange(prompt, 0, upperLimit);
}


bool isAFactor(int value1, int value2)
{
    if(value1 % value2 == 0){
    	return true;
    }
    else{
    	return false;
    }
}


int main()
{
	int A = 3;

	cout << square(A) << endl;

	cout << summation(A) << endl;

	cout << sumOfSquare(A) << endl;

	rectangle(6, 8,'A', '.');
	cout << endl << endl;
	rectangle(6, 8,'A');

	cout << endl << endl;

	cout << inputWithinRange("Enter an Integer: ", 0, 5) << endl << endl;
	cout << inputWithinRange("Enter an Integer: ", 5 ) << endl << endl;

	cout << isAFactor(25,5) << endl;
	cout << isAFactor(25,3) << endl;

	return 0;

}




