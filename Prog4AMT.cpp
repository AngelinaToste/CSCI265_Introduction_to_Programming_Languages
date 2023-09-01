/*
 * Angelina Toste
 * 1399403
 * angelina.toste@und.edu
 *
 * Program 4:
This program contains the following functions
    findMaxScore - Return the largest integer value (int) found in the list.DO NOT make any assumptions about the
         range of values in the list. size is the number of items in the list/array.
    findMinScore - Return the smaller integer value (int) found in the list.DO NOT make any assumptions about the
         range of values in the list. size is the number of items in the list/array
    hasPerfectScore - Returns the appropriate true reserved word if any of the scores is 100 or greater, otherwise
         returns the appropriate false reserved word.
    calcAverage - Return the average (double) of all the scores found in the list. Return -1 if unable to determine
         an array – don’t let the program crash.
    findStudentWithMax - Return the name of the student with the largest score. You can assume there will be only one
         student with the largest score. IF there were two students with the largest score (there won’t be)
         you can return the name of the first student with that score.
    mergeLists - Return a new array/list made up of the values from the two lists, values from list1 first, then the
         values from list2. This might not fit into the theme of the other functions, but we’ll still include it in
         the list of required functions
    standardDeviation - Return the standard deviation of the values. To find the standard deviation start with the
         average of the list – DO NOT repeat the code for calculating the average. Then for each value
         in the list subtract the average from that value and square the result. Find the average of the
         squared differences and then take the square root of that average.
    findInList - Return the index of the first occurrence of valueToFind. IF specified, starting searching at the
         specified index, otherwise start searching at index 0. This requires a default parameter in
         Python and overloaded functions/methods in Java and C++. In any of the functions return -1 if
         the value is not found.
 *
 *
 */

#include <iostream>
#include <string>
#include <math.h>
using namespace std;



int findMaxScore(int scoresList[], int size)
{
	/*
     *Return the largest integer value (int) found in the list.DO NOT make any assumptions about the
     *range of values in the list. size is the number of items in the list/array
     *:param scoresList: the list containing the scores
     *:param size: size of scoresList
     *:return maxScore: the largest integer value in the list
	 */
    int maxScore = 0;


    for (int x = 0; x < size; x++)
    {
    	if (maxScore < scoresList[x])
    	{
    		 maxScore = scoresList[x];
    	}
    }
    return maxScore;
}


int findMinScore(int scoresList[], int size)
{
	/*
     * Return the smallest integer value (int) found in the list.DO NOT make any assumptions about the
     * range of values in the list. size is the number of items in the list/array.
     *:param scoresList: the list containing the scores
     *:param size: size of scoresList
     *:return minScore: the smallest integer value found in the list
	 *
	*/
	int minScore = 100;


	    for (int x = 0; x < size; x++)
	    {
	    	if (minScore > scoresList[x])
	    	{
	    		 minScore = scoresList[x];
	    	}
	    }
	    return minScore;
    
}


bool hasPerfectScore(int scoresList[], int size)
{
	/*
	 * Returns the appropriate true reserved word if any of the scores is 100 or greater, otherwise
     * returns the appropriate false reserved word.
     * :param scoresList: the list containing the scores
     * :param size: size of scoresList
     * :return: true or false is returned depending on if any score is greater than 100
	 */

    for (int i = 0; i < size; i++)
    {
    	if (scoresList[i] >= 100)
    	{
    		return true;
    	}
    }
    return false;
}

double calcAverage(int scoresList[], int size)
{
	/*
	 * Return the average (double) of all the scores found in the list. Return -1 if unable to determine
     * an array – don’t let the program crash.
     * :param scoresList: the list containing the scores
     * :return average: the average of all the scores in the list
	 *
	 */
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + scoresList[i];
    }

    float average = float(sum) / size;
    return average;
}

string findStudentWithMax(int scoresList[], string namesList[], int size)
{
	/*
	 * Return the name of the student with the largest score. You can assume there will be only one
     * student with the largest score. IF there were two students with the largest score (there won’t be)
     * you can return the name of the first student with that score.
     * :param scoresList: the list of scores
     * :param namesList: the list of names
     * :param size: the size of scoresList
     * :return: student name that matches with the same index as the largest score.
	 */
	for (int i = 0; i < size; i++)
	{
	    if (scoresList[i] == findMaxScore(scoresList, size))
	    {
	        return namesList[i];
	    }
	}
	return "none";
}

int* mergeLists(int list1[], int size1, int list2[], int size2)
{
	/*
	 * Return a new array/list made up of the values from the two lists, values from list1 first, then the
    * values from list2. This might not find into the theme of the other functions, but we’ll still include it
    * in the list of required functions
    * :param list1: integer list 1
    * :param size1: size of list 1
    * :param list2: integer list 2
    * :param size2: size of list 2
    * :return newList: all the values from list1 and list 2 combined into one list
	 */
    int *newList = (int *) malloc ((size1 + size2) * sizeof(int));

    for (int i = 0; i < size1; i++)
    {
        newList[i] = list1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        newList[i + size1] = list2[i];
    }
    return newList;
}

double standardDeviation(int scoresList[], int size)
{
	/*
	 * Return the standard deviation of the values. To find the standard deviation start with the
     * average of the list – DO NOT repeat the code for calculating the average. Then for each value
     * in the list subtract the average from that value and square the result. Find the average of the
     * squared differences and then take the square root of that average.
     * :param scoresList: the list providing the score values
     * :param size: size of scoresList
     * :return standardDeviation: the standard deviation of the values in the provided list
	 */
    double average = calcAverage(scoresList, size);
    double squaredDifferences[size];

    for (int i = 0; i < size; i++)
    {
        double difference =  scoresList[i] - average;
        squaredDifferences[i] = difference * difference;
    }

    // calculating the average of Squared Differences
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + squaredDifferences[i];
    }
    double averageOfSD = sum / size;

    double standardDeviation  = sqrt(averageOfSD);

    return standardDeviation;
}


int findInList(int scoresList[], int size, int valueToFind, int startingIndex)
{
	/*
	 * Return the index of the first occurrence of valueToFind. IF specified, starting searching at the
     * specified index, otherwise start searching at index 0. This requires a default parameter in
     * Python and overloaded functions/methods in Java and C++. In any of the functions return -1 if
     * the value is not found.
     * :param scoresList: the list containing the scores and being searched through
     * :param size: the size of scoresList
     * :param valueToFind:the value that is being searched for in the list
     * :param startingIndex: the place at which the search will begin
     * :return index or -1: index returned if the value is found, otherwise -1 is returned
    */
	for (int i = startingIndex; i < size; i++)
	{
         if (scoresList[i] == valueToFind)
		 {
        	 cout << "Found " << valueToFind << " at index " << i << endl;
		     return i;
		 }
    }
    return -1;
}

int findInList(int scoresList[], int size, int valueToFind)
{
	/*
	 * This function is the version of the findInList that uses 0 as the default starting index
	 */
	findInList(scoresList, size, valueToFind, 0);
    return 0;
}

int main()
{
    int scoresList[12] = {45, 53, 68, 88, 46, 99, 63, 78, 100, 65, 32, 98};
	string namesList[12] = {"Bob", "Tom", "Pam", "Sherry", "Elise", "Aaron", "Teddy", "Greg", "Travis", "Sarah", "Steven", "David"};

	int size = sizeof(scoresList)/ sizeof(int);
    cout << size << endl;
    cout << findMaxScore(scoresList, size) << endl;
    cout << findMinScore(scoresList, size) << endl;
    cout << hasPerfectScore(scoresList, size) << endl;
    printf("%1.2f\n", calcAverage(scoresList, size));
    cout << findStudentWithMax(scoresList,namesList, size) << endl;

    int list1[5] = {1, 1, 1, 1, 1};
    int list2[5] = {9, 9, 9, 9, 9};
    int size1 = sizeof(list1)/ sizeof(int);
    int size2 = sizeof(list2)/ sizeof(int);

    int *newList = mergeLists(list1, size1, list2, size2);

    int newSize = size1 + size2;

    // prints merged array
    for (int f = 0; f < newSize; f++)
    {
        cout << newList[f] << " ";
    }
    cout << endl;

    int scoresList2[4] = {4, 5, 6, 3};
    int size3 = sizeof(scoresList2)/ sizeof(int);
    cout << standardDeviation(scoresList2, size3) << endl;
    cout << findInList(scoresList, size, 100, 0);

	return 0;
}


