
/* 
 * Angelina Toste
 * 1399403
 * angelina.toste@und.edu
 *
 *Program 2:
 *  The following program prompts the user for a "major" and compares that inputed
 *  value to the strings "CS", "DATA", "CYBER", and if there is no match, the input for
 *  major will be counted as "OTHER".
 *
 *  If "CS" is inputed as the major, the program will ask the user for a "minor" and compare
 *  the inputed value to the strings "DATA", "CYBER", "MATH",and, if there is a different input,
 *  the input for the minor will be counted as "OTHER".
 *
 *  If the string "DONE" is inputed for major, the program will stop and print out the output.
 *  output:
 *  - total number of students inputed
 *  - the different majors of the students (total students for each and percentage of total students)
 *  - the different minors of the cs students (total students for each and percentage of total cs students)
 *
 *  *Note: this program is case-INSENSITIVE
 * 
 *
*/

import java.util.Scanner;

public class prog2AMT {

	public static void main (String[] args){
		Scanner keyboard = new Scanner(System.in);

	    //initializing counters
		int cs = 0, data = 0, cyber = 0, other = 0 , total = 0;
		int dataMin = 0, cyberMin = 0, mathMin = 0, otherMin = 0 , totalMin = 0;

		String major;


	    System.out.print("Enter major: ");
	    major  = keyboard.nextLine();
	    


	    Boolean result = major.toUpperCase().equals("DONE");


	    while ( !result ){

	    	Boolean csresult = major.toUpperCase().equals("CS");
	    	Boolean dataresult = major.toUpperCase().equals("DATA");
	    	Boolean cyberresult = major.toUpperCase().equals("CYBER");


	    	if (csresult) {
	    		cs++;
	    		total++;

	    		String minor;
	    		System.out.print("Enter minor: ");
	    		minor = keyboard.nextLine();

	    		Boolean dataMinresult = minor.toUpperCase().equals("DATA");
	    		Boolean cyberMinresult = minor.toUpperCase().equals("CYBER");
	    		Boolean mathMinresult = minor.toUpperCase().equals("MATH");

	    		if (dataMinresult){
	    			dataMin++;
	    			totalMin++;
	    		}
	    		else if (cyberMinresult){
	    		    cyberMin++;
	    		    totalMin++;
	    		}
	    		else if (mathMinresult){
	    		    mathMin++;
	    		    totalMin++;
	    		}
	    		else {
	    		    otherMin++;
	    		    totalMin++;
	    		}

	    	}
	    	else if (dataresult) {
	    	    data++;
	    	    total++;
	    	}
	    	else if (cyberresult){
	    	    cyber++;
	    	    total++;
	    	}

	    	else {
	    		other++;
	    		total++;
	    	}

	        System.out.println();

	        System.out.print("Enter major: ");
	        major = keyboard.nextLine();

	    	result = major.toUpperCase().equals("DONE");

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
	    System.out.println();
	    System.out.print("Total number of students " + total);
	    System.out.println();
	    System.out.print("Majors of students in CS160\r");
	    System.out.printf("%-14s %4d %7.2f\r","Computer Science",cs, pct_cs );
	    System.out.printf("%-16s %4d %7.2f\r","Data Science",data, pct_data );
	    System.out.printf("%-16s %4d %7.2f\r","Cyber Security",cyber, pct_cyber );
	    System.out.printf("%-16s %4d %7.2f\r","Other Majors",other, pct_other );
	    System.out.println();
	    System.out.println();
	    System.out.print("Minors for Computer Science Majors in CS160\r");
	    System.out.printf("%-16s %4d %7.2f\r","Data Science",dataMin, pct_dataMin );
	    System.out.printf("%-16s %4d %7.2f\r","Cyber Security",cyberMin, pct_cyberMin );
	    System.out.printf("%-16s %4d %7.2f\r","Mathematics",mathMin, pct_mathMin );
	    System.out.printf("%-16s %4d %7.2f\r","Other Minors",otherMin, pct_otherMin );


	}
	
}
