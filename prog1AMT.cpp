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

#include <iostream>
using namespace std;

int main(){


	//PART 1
	cout << "PART 1" << endl;

	int seconds;
	cout << "Seconds: ";
	cin >> seconds;

	int hours = seconds/3600;
	int minutes = (seconds % 3600) / 60;
	seconds = (seconds % 3600) % 60;

	cout << "This is " << hours << " hours, " << minutes << " minutes, " << "and " << seconds << " seconds.\n" << endl;

	//PART 2
	cout << "PART 2" << endl;

	int quarters;
	cout << "Quarters: ";
	cin >> quarters;

	int dimes;
	cout << "Dimes: ";
	cin >> dimes;

	int nickels;
	cout << "Nickels: ";
	cin >> nickels;

	int pennies;
	cout << "Pennies: ";
	cin >> pennies;

	float total = (quarters * 25) + (dimes * 10) + (nickels * 5) + pennies;
	total = total/100;

	cout << "This is equal to $" << total << endl << endl;



	//PART 3
	cin.ignore(256, '\n');

	cout << "PART 3" << endl;
	string firstName = "", lastName = "", address = "", city = "", state = "", zipcode = "";

	cout << "First Name: ";
	getline(cin, firstName);

	cout << "Last Name: ";
	getline(cin, lastName);;

	cout << "Address: ";
	getline(cin, address);

	cout << "City: ";
	getline(cin, city);

	cout << "State: ";
	getline(cin, state);

	cout << "Zipcode: ";
	getline(cin, zipcode);

	cout << endl;


	// using 1 print statement
	cout << firstName << " " << lastName << endl << address << endl << city << ", " << state << "  " << zipcode << endl;

	cout << endl;

	// using 6 print statement
	cout << firstName;
	cout << " " << lastName << endl;
	cout << address << endl;
	cout << city << ", ";
	cout << state << "  ";
	cout << zipcode << endl;


	return 0;
}
