"""
Angelina Toste
1399403
angelina.toste@und.edu

Program 4
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

"""


def findMaxScore (scoresList):
    """
    Return the largest integer value (int) found in the list.DO NOT make any assumptions about the
    range of values in the list. size is the number of items in the list/array
    :param scoresList: the list containing the scores
    :return maxScore: the largest integer value in the list
    """
    maxScore = 0
    length = len(scoresList)

    for i in range(length):
        if maxScore < scoresList[i]:
            maxScore = scoresList[i]

    return maxScore


def findMinScore (scoresList):
    """
    Return the smallest integer value (int) found in the list.DO NOT make any assumptions about the
    range of values in the list. size is the number of items in the list/array.
    :param scoresList: the list containing the scores
    :return minScore: the smallest integer value found in the list
    """
    minScore = 100
    length = len(scoresList)

    for i in range(length):
        if minScore > scoresList[i]:
            minScore = scoresList[i]

    return minScore


def hasPerfectScore(scoresList):
    """
    Returns the appropriate true reserved word if any of the scores is 100 or greater, otherwise
    returns the appropriate false reserved word.
    :param scoresList: the list containing the scores
    :return: true or false is returned depending on if any score is greater than 100
    """
    for score in scoresList:
        if score >= 100:
            return True

    return False


def calcAverage(scoresList):
    """
    Return the average (double) of all the scores found in the list. Return -1 if unable to determine
    an array – don’t let the program crash.
    :param scoresList: the list containing the scores
    :return average: the average of all the scores in the list
    """
    sum = 0
    length = len(scoresList)

    for score in scoresList:
        sum = sum + score

    average = sum / length

    return average


def findStudentWithMax (scoresList, namesList):
    """
    Return the name of the student with the largest score. You can assume there will be only one
    student with the largest score. IF there were two students with the largest score (there won’t be)
    you can return the name of the first student with that score.
    :param scoresList: the list of scores
    :param namesList: the list of names
    :return: student name that matches with the same index as the largest score.
    """
    length = len(scoresList)

    for i in range(length):
        if scoresList[i] == findMaxScore(scoresList):
            return namesList[i]


def mergeLists (list1, list2):
    """
    Return a new array/list made up of the values from the two lists, values from list1 first, then the
    values from list2. This might not find into the theme of the other functions, but we’ll still include it
    in the list of required functions
    :param list1: integer list 1
    :param list2: integer list 2
    :return newList: all the values from list1 and list 2 combined into one list
    """
    newList = list1 + list2

    return newList


def standardDeviation (scoresList):
    """
    Return the standard deviation of the values. To find the standard deviation start with the
    average of the list – DO NOT repeat the code for calculating the average. Then for each value
    in the list subtract the average from that value and square the result. Find the average of the
    squared differences and then take the square root of that average.
    :param scoresList: the list providing the score values
    :return standardDeviation: the standard deviation of the values in the provided list
    """
    length = len(scoresList)
    average = calcAverage(scoresList)
    squaredDifferences = []

    for i in range(length):
        difference = scoresList[i] - average
        squaredDifferences.append(difference ** 2)
    averageOfSD = calcAverage(squaredDifferences)

    standardDeviation = averageOfSD ** (1/2)

    return standardDeviation


def findInList(scoresList, valueToFind, startingIndex = 0):
    """
    Return the index of the first occurrence of valueToFind. IF specified, starting searching at the
    specified index, otherwise start searching at index 0. This requires a default parameter in
    Python and overloaded functions/methods in Java and C++. In any of the functions return -1 if
    the value is not found.
    :param scoresList: the list containing the scores and being searched through
    :param valueToFind:the value that is being searched for in the list
    :param startingIndex: the place at which the search will begin
    :return index or -1: index returned if the value is found, otherwise -1 is returned
    """
    end = len(scoresList)

    for index in range (startingIndex, end):
        if scoresList[index] == valueToFind:
            return index
    return -1


def main ():

    scoresList = [45, 53, 68, 88, 46, 99, 63, 78, 100, 65, 32, 98]
    namesList = ["Bob", "Tom", "Pam", "Sherry", "Elise", "Aaron", "Teddy", "Greg", "Travis", "Sarah", "Steven", "David"]

    print(findMaxScore(scoresList), "is the max score")
    print(findMinScore(scoresList), "is the min score")

    scoresList1 = [45, 53, 68, 88, 46, 99, 63, 78, 99, 65, 32, 98]
    print("the list has a perfect score:", hasPerfectScore(scoresList))
    print("the list has a perfect score:", hasPerfectScore(scoresList1))

    print(format(calcAverage(scoresList), "1.2f"), "is the average")
    print(findStudentWithMax(scoresList, namesList), "is the student with the max score")
    print(mergeLists(scoresList, namesList))

    scoresList2 = [4, 5, 6, 3]
    print(format(standardDeviation(scoresList2), "1.3f"), "is the standard deviation")

    print( findInList(scoresList, 100), "is the index for 100")
    print( findInList(scoresList, 88, 3), "is the index for 88 starting at index 3")


main()
