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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){

	//PART 1
	printf("PART 1 \n");

	printf("Seconds: ");
	int seconds;
	scanf("%d", &seconds);

	int hours = seconds/3600;
	int minutes = (seconds % 3600) / 60;
	seconds = (seconds % 3600) % 60;

	printf("This is %d hours, %d minutes, and %d seconds.\n\n", hours, minutes, seconds);


	//PART 2
	printf("PART 2 \n");

	printf("Quarters: ");
	int quarters;
	scanf("%d", &quarters);

	printf("Dimes: ");
	int dimes;
	scanf("%d", &dimes);

	printf("Nickels: ");
	int nickels;
	scanf("%d", &nickels);

	printf("Pennies: ");
	int pennies;
	scanf("%d", &pennies);

	float total = (quarters * 25) + (dimes * 10) + (nickels * 5) + pennies;
	total = total/100;

	printf("This is equal to $%1.2f.\n\n", total);


	//PART 3
	printf("PART 3\n");
	char firstName[20], lastName[20], address[30], city[30], state[20], zipcode[20], junk[10];

	fgets(junk, 10, stdin);
	printf("First Name: ");
	fgets(firstName, 19, stdin);
	firstName[strcspn(firstName, "[\r\n]")] = 0;

	fgets(junk, 10, stdin);
	printf("Last Name: ");
	fgets(lastName, 19, stdin);
	lastName[strcspn(lastName, "[\r\n]")] = 0;

	fgets(junk, 10, stdin);
	printf("Address: ");
	fgets(address, 29, stdin);
	lastName[strcspn(lastName, "[\r\n]")] = 0;

	fgets(junk, 10, stdin);
	printf("City: ");
	fgets(city, 29, stdin);
	city[strcspn(city, "[\r\n]")] = 0;

	fgets(junk, 10, stdin);
	printf("State: ");
	fgets(state, 19, stdin);
	state[strcspn(state, "[\r\n]")] = 0;

	fgets(junk, 10, stdin);
	printf("Zipcode: ");
	fgets(zipcode, 20, stdin);
	zipcode[strcspn(zipcode, "[\r\n]")] = 0;

	printf("\n");

	// using 1 print statement
	printf("%s %s\n%s%s, %s  %s\n\n", firstName, lastName, address, city, state, zipcode);

	// using 6 print statement
	printf("%s ", firstName );
	printf("%s\n", lastName );
	printf("%s", address);
	printf("%s, ", city);
	printf("%s  ", state);
	printf("%s", zipcode);

	return 0;

}
