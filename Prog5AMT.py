"""
Angelina Toste
1399403
angelina.toste@und.edu

Program 5

This program contains all of the following functions:
    addPart - Ensures that the specified part/cost key/value pair is in the data structure.
              Returns a true value if the pair is a new pair/added to the data structure.
              Returns a false value if the pair is not new, with the cost being updated. 
    totalParts - Returns the number of unique parts (int) in the data structure.
    
    partsGreaterThan -  Returns a list/array of the part names with a price greater than or equal to the upperLimit variable.
             The list should be created in the function.
    isPart - Returns a true value if part is a valid part in data structure, otherwise return a false value.
             The case of the parts should not matter.
    leastExpensivePart - Returns the part name with the least expensive price.
             You can assume that there will be only one part with the least expensive price.
    mostExpensivePart - Returns the part name with the least expensive price. 
             You can assume that there will be only one part with the least expensive price.
    averagePrice - Returns the average of all parts in the dictionary. 
             Return -1 if you are unable to determine the average.
    printParts - This function WILL write to the display a table of each part and its price. 
        Include column headers in the output. Make sure the price 
        has two places after the decimal point. Also make sure the columns are neatly aligned, 
        with the part column being left justified and the price column being right justified. 
        This function/method should not return a value

"""


def addPart(parts, part, cost):
    """
    Ensures that the specified part/cost key/value pair is in the data structure.
    Returns a true value if the pair is a new pair/added to the data structure.
    Returns a false value if the pair is not new, with the cost being updated.
    :param parts: the dictionary containing the part names and their corresponding prices
    :param part: the name of the part being searched for in the dictionary
    :param cost: the name of the price associated with the part being searched for in the dictionary
    :return: true if the part and cost are new to the data structre, false if the part and
        cost are not new to the data structure (resulting in the cost being update if it is different from
        the original)
    """
    if part in parts.keys():
        parts[part] = cost
        return False

    else:
        parts[part] = cost
        return True


def totalParts(parts):
    """
    Returns the number of unique parts (int) in the data structure.
    :param parts: the dictionary containing the part names and their corresponding prices
    :return: an integer representing the number of parts in the data structure
    """
    # initializing counter
    x = 0

    for part in parts:
        x += 1
    return x


def partsGreaterThan(parts, upperLimit):
    """
    Returns a list/array of the part names with a price greater than or equal to the upperLimit variable.
    The list should be created in the function.
    :param parts: the dictionary containing the part names and their corresponding prices
    :param upperLimit: a double indicating the limit that the part prices must exceed
    :return: a list of the part names that have prices greater or equal to the upperLimit
    """
    greaterList = []
    for part in parts:
        if parts[part] > upperLimit:
            greaterList.append(part)

    return greaterList


def isPart(parts, part):
    """
    Returns a true value if part is a valid part in data structure, otherwise return a false value.
    The case of the parts should not matter.
    :param parts: the dictionary containing the part names and their corresponding prices
    :param part:the part that is being searched for in the data structure
    :return: true if the part exists in the data structure, 
            false if the part does NOT exist in the data structure
    """
    for item in parts.keys():
        if part.lower() == item.lower():
            return True

    return False


def leastExpensivePart(parts):
    """
    Returns the part name with the least expensive price.
    You can assume that there will be only one part with the least expensive price.
    :param parts: the dictionary containing the part names and their corresponding prices
    :return: the name of the part that has the least expensive price
    """
    # set least to the first value in the dictionary
    for item in parts:
        least = parts[item]
        break
    
    leastPart = None
    for part in parts:
        if parts[part] < least:
            least = parts[part]
            leastPart = part
    return leastPart


def mostExpensivePart(parts):
    """
    Returns the part name with the most expensive price.
    You can assume that there will be only one part with the most expensive price.

   :param parts: the dictionary containing the part names and their corresponding prices
   :return: the part name with the most expensive price
   """
   # set most to the first value in the dictionary
    for item in parts:
        most = parts[item]
        break
    
    mostPart = None
    for part in parts:
        if parts[part] > most:
            most = parts[part]
            mostPart = part
    return mostPart


def averagePrice(parts):
    """
    Returns the average of all parts in the dictionary. Return -1 if you are unable to determine the average.
    :param parts: the dictionary containing the part names and their corresponding prices
    :return: average of all the part prices in the dictionary
    """

    sum = 0

    for part in parts:
        sum = sum + parts[part]

    try:
        average = sum / totalParts(parts)
    except ZeroDivisionError:
        return -1
    except Exception:
        return -1

    return average


def printParts(parts):
    """
    This function WILL write to the display a table of each part and its price. 
    Include column headers in the output. Make sure the price has two places after the decimal point. 
    Also make sure the columns are neatly aligned, with the part column being left justified and 
    the price column being right justified. 
    This function/method should not return a value
    
    :param parts:the dictionary containing the part names and their corresponding prices
    :return: this function is void, it should not return a value
    """
    #find the longest part name for the width of the item column
    length = 0
        
    for item in parts:
        itemlen = len(item)
        if itemlen > length:
            length = itemlen

    for part in parts:
        print(format(part, str(length) + "s"), format(parts[part],"5.2f") )


def main():
    # initialize parts dictionary
    parts = {"Hammer": 5, "Nails": 3, "Drill": 7, "Wrench": 8, "Handsaw": 15}

    print(addPart(parts, "Nails", 3))
    print(addPart(parts, "Nails", 4))
    print(addPart(parts, "Drill Bits", 5))
    print()
    print(partsGreaterThan(parts, 6.0))
    print()
    print(totalParts(parts))
    print()
    print(isPart(parts, "Nails"))
    print()
    print(isPart(parts, "Screws"))
    print()
    print(leastExpensivePart(parts))
    print(mostExpensivePart(parts))
    print()
    print(averagePrice(parts))
    print()
    printParts(parts)

main()
