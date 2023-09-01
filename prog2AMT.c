//Angelina Toste
/* 1399403
 * angelina.toste@und.edu
 *
 * Program 2:
 *   The following program prompts the user for a "major" and compares that inputed
 *   value to the strings "CS", "Data", "Cyber", and if there is no match, the input for
 *   major will be counted as "Other".
 *
 *   If "CS" is inputed as the major, the program will ask the user for a "minor" and compare
 *  the inputed value to the strings "Data", "Cyber", "Math",and, if there is a different input,
 *  the input for the minor will be counted as "Other".
 *
 *  If the string "DONE" is inputed for major, the program will stop and print out the output.
 *  output:
 *  - total number of students inputed
 *  - the different majors of the students (total students for each and percentage of total students)
 *  - the different minors of the cs students (total students for each and percentage of total cs students)
 *
 *   *Note: this program is case-SENSITIVE
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (){

    //initializing counters
	int cs = 0, data = 0, cyber = 0, other = 0 , total = 0;
	int dataMin = 0, cyberMin = 0, mathMin = 0, otherMin = 0 , totalMin = 0;

	char major[20];


    printf("Enter major: ");
    fgets(major, 19, stdin);
    major[strcspn(major, "[\r\n]")] = 0;


    int result = strcmp(major,"Done");


    while ( result ){

    	int csresult = strcmp(major, "CS");
    	int dataresult = strcmp(major, "Data");
    	int cyberresult = strcmp(major, "Cyber");


    	if (csresult == 0) {
    		cs++;
    		total++;

    		char minor[20];
    		printf("Enter minor: ");
    		fgets(minor, 19, stdin);
    		minor[strcspn( minor, "[\r\n]")] = 0;

    		int dataMinresult = strcmp(minor, "Data");
    		int cyberMinresult = strcmp(minor, "Cyber");
    		int mathMinresult = strcmp(minor, "Math");

    		if (dataMinresult == 0){
    			dataMin++;
    			totalMin++;
    		}
    		else if (cyberMinresult == 0){
    		    cyberMin++;
    		    totalMin++;
    		}
    		else if (mathMinresult == 0){
    		    mathMin++;
    		    totalMin++;
    		}
    		else {
    		    otherMin++;
    		    totalMin++;
    		}

    	}
    	else if (dataresult == 0) {
    	    data++;
    	    total++;
    	}
    	else if (cyberresult == 0){
    	    cyber++;
    	    total++;
    	}

    	else {
    		other++;
    		total++;
    	}

        printf("\n");

        printf("Enter major: ");
        fgets(major, 19, stdin);
        major[strcspn(major, "[\r\n]")] = 0;

    	result = strcmp(major, "Done");

    }

    //percents
    float pct_cs = ((float)cs / (float)total) * 100;
    float pct_data = ((float)data/ (float)total) * 100;
    float pct_cyber = ((float)cyber / (float)total) * 100;
    float pct_other = ((float)other / (float)total) * 100;

    float pct_dataMin = ((float)dataMin / (float)totalMin) * 100;
    float pct_cyberMin = ((float)cyberMin / (float)totalMin) * 100;
    float pct_mathMin = ((float)mathMin / (float)totalMin) * 100;
    float pct_otherMin = ((float)otherMin / (float)totalMin) * 100;

    //OUTPUT
    printf("\n");
    printf("Total number of students %d\n", total);
    printf("\n");
    printf("Majors of students in CS160\r");
    printf("%-14s %4d %7.2f\r","Computer Science",cs, pct_cs );
    printf("%-16s %4d %7.2f\r","Data Science",data, pct_data );
    printf("%-16s %4d %7.2f\r","Cyber Security",cyber, pct_cyber );
    printf("%-16s %4d %7.2f\r","Other Majors",other, pct_other );

    printf("\n");
    printf("Minors for Computer Science Majors in CS160\r");
    printf("%-16s %4d %7.2f\r","Data Science",dataMin, pct_dataMin );
    printf("%-16s %4d %7.2f\r","Cyber Security",cyberMin, pct_cyberMin );
    printf("%-16s %4d %7.2f\r","Mathematics",mathMin, pct_mathMin );
    printf("%-16s %4d %7.2f\r","Other Minors",otherMin, pct_otherMin );


}
