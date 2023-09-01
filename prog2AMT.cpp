//Angelina Toste
/* 1399403
 * angelina.toste@und.edu
 *
 *Program 2:
 *  The following program prompts the user for a "major" and compares that inputed
 *  value to the strings "CS", "Data", "Cyber", and if there is no match, the input for
 *  major will be counted as "Other".
 *
 *  If "CS" is inputed as the major, the program will ask the user for a "minor" and compare
 *  the inputed value to the strings "Data", "Cyber", "Math",and, if there is a different input,
 *  the input for the minor will be counted as "Other".
 *
 *  If the string "Done" is inputed for major, the program will stop and print out the output.
 *  output:
 *  - total number of students inputed
 *  - the different majors of the students (total students for each and percentage of total students)
 *  - the different minors of the cs students (total students for each and percentage of total cs students)
 *
 *  *Note: this program is case-SENSITIVE
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (){

    //initializing counters
	int cs = 0, data = 0, cyber = 0, other = 0 , total = 0;
	int dataMin = 0, cyberMin = 0, mathMin = 0, otherMin = 0 , totalMin = 0;

	char major[20];


    cout << "Enter major: " ;
    cin >> major;


    int result = strcmp(major,"Done");


    while ( result ){

    	int csresult = strcmp(major, "CS");
    	int dataresult = strcmp(major, "Data");
    	int cyberresult = strcmp(major, "Cyber");


    	if (csresult == 0) {
    		cs++;
    		total++;

    		char minor[20];
    		cout << "Enter minor: ";
    		cin >> minor;


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

        cout << endl;

        cout << "Enter major: " ;
        cin >> major;

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
    cout << endl;
    cout << "Total number of students " << total << endl;
    cout << endl;
    cout << "Majors of students in CS160\r";
    cout << left << setw(14) << "Computer Science" << right << setw(4) << cs << right << fixed << setw(9) << setprecision(2) << pct_cs << "\r";
    cout << left << setw(16) << "Data Science" << right << setw(4) << data << right << fixed << setw(9) << setprecision(2) << pct_data << "\r";
    cout << left << setw(16) << "Cyber Security" << right << setw(4) << cyber << right << fixed << setw(9) << setprecision(2) << pct_cyber << "\r";
    cout << left << setw(16) << "Other Majors" << right << setw(4) << other << right << fixed << setw(9) << setprecision(2) << pct_other << "\r";

    cout << endl;
    cout << "Minors for Computer Science Majors in CS160\r";
    cout << left << setw(16) << "Data Science" << right << setw(4) << dataMin << right << fixed << setw(9) << setprecision(2) << pct_dataMin << "\r";
    cout << left << setw(16) << "Cyber Security" << right << setw(4) << cyberMin << right << fixed << setw(9) << setprecision(2) << pct_cyberMin << "\r";
    cout << left << setw(16) << "Mathematics" << right << setw(4) << mathMin << right << fixed << setw(9) << setprecision(2) << pct_mathMin << "\r";
    cout << left << setw(16) << "Other Minors" << right << setw(4) << otherMin << right << fixed << setw(9) << setprecision(2) << pct_otherMin << "\r";


}



