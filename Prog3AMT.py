"""
Angelina Toste
1399403
angelina.toste@und.edu

Program 3:
This program consists of the following functions
    square - returns the square of the given value ( square(3) returns 9)
    summation - returns the summation of 1 to the value passed to the function. It will be assumed that
        this value is positive
    sumOfSquare - This function  returns the sum of the squares from 1 to value
        rectangle - draws the outline on the screen of a rectangle with the specified width and height. uses character
        to draw the outline. Uses fillChar for all characters inside the outline. Uses a blank space as the fill
        character when not specified.
    inputWithinRange - will ask for an integer value, using the provided prompt. The value must be
        inclusively within lowerLimit and upperLimit, if not, continue to ask for a value until the entered
        value is within the provided range. Once a valid value has been entered return it from the function
    isAFactor -  This function will return True (Python) if the second argument is a factor of (divides evenly into)
        the first argument
    

"""


def square(value):
    """
    This function will take a value and return the product of the value with itself (the square of the value)
    :param value: the value passed into the function, the value being squared
    :return: the square of the value being passed into the function
    """
    result = value * value
    return result


def summation(value):
    """
    This function will return the summation of 1 to the value passed to the function. It will be assumed that
     this value is positive
    :param value: value being passed into the function; the maximum value in the summation
    :return: the summation of 1 to the integer value passed into the function
    """
    x = 1
    sum = 0

    while x <= value:
        sum = sum + x
        x += 1
    return sum


def sumOfSquare(value):
    """
    This function  returns the sum of the squares from 1 to value
    :param value: maximum value being squared in the sum of squares.
    :return: the sum of the squares from 1 to the value
    """
    x = 1
    sum = 0

    while x <= value:
        sum = sum + square(x)
        x += 1

    return sum


def rectangle(width, height, character, fillChar=' '):
    """
    This function will draw the outline on the screen of a rectangle with the specified width and height. Use character
    to draw the outline. Use fillChar for all characters inside the outline. Use a blank space as the fill character
    when not specified.
    :param width: the width of the rectangle, the number of characters needed for the width of the rectangle
    :param height: the height of the rectangle, number of characters needed to make up the height of the rectangle
    :param character: char being used to draw the outside of the rectangle
    :param fillChar: char being used to fill the inside of the rectangle (optional, default is a blank space)
    :return: none, the output will be a series of print statements using strings of chars for each line of output
    """
    # the following code will print the characters for the width of the rectangle (row 1)
    print(width * character)

    # the following for loop will print the fillChar characters for the height of the rectangle
    for x in range(height - 2):
        for i in range(width):
            i += 1
            if i == 1:
                print(character, end='')
            elif i == width:
                print(character, end='\n')
            else:
                print(fillChar, end='')

    # the following code will print the characters for the width of the rectangle (last row of the rectangle)
    print(width * character)


def inputWithinRange(prompt, lowerLimit, upperLimit=None):
    """
    This function will ask for an integer value, using the provided prompt. The value must be
    inclusively within lowerLimit and upperLimit, if not, continue to ask for a value until the entered
    value is within the provided range. Once a valid value has been entered return it from the function
    :param prompt: a string that will ask the user to input a value
    :param lowerLimit: the minimum value of the range
    :param upperLimit: the maximum value of the range, this value does not have to be specified. if it is not, the
        lower limit param will be used as the upper limit, making the new lower limit 0.
    :return: the value that was inputted by the user and valid for the specified range
    """
    value = int(input(prompt))
    if upperLimit:
        while value < lowerLimit or value > upperLimit:
            value = int(input(prompt))
        return value
    else:
        while value < 0 or value > lowerLimit:
            value = int(input(prompt))
        return value


def isAFactor(value1, value2):
    """
    This function will return True (Python) if the second argument is a factor of (divides evenly into)
        the first argument
    :param value1: the first argument that will be the dividend for the division operation
    :param value2: the value acting as the divisor of the division operation
    :return: True or False depending on if the second argument is a factor of the first argument
    """

    if value1 % value2 == 0:
        return True
    else:
        return False


def main():
    # math functions
    x = 3
    
    print(square(x))
    print(summation(x))
    print(sumOfSquare(x))
    
    print()

    # rectangle function
    width = 5
    height = 5
    character = "*"
    fillChar = "0"
    
    rectangle(width, height, character, fillChar)
    print()
    rectangle(width, height, character)

    # number comparisons
    print(inputWithinRange("Enter an integer value: ", 2, 8))
    print(inputWithinRange("Enter an integer value: ", 8))

    print()
    print(isAFactor(45, 9))
    print(isAFactor(225, 7))


main()
