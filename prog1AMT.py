"""
Angelina Toste
1399403
angelina.toste@und.edu

Program 1:
    Part 1-convert from seconds
    Part 2-convert to dollars
    Part 3-work with output

"""


def main():
    
    #PART 1
    print("PART 1", end ="\n")
    seconds = int(input("Seconds: "))
    
    hours = seconds//3600
    minutes = (seconds % 3600) // 60
    seconds = (seconds % 3600) % 60

    print("This is ", hours, " hours,", minutes, "minutes, and", seconds, "seconds.", sep=" ")
    print()

    #PART 2
    print("PART 2", end ="\n")
    quarters = int(input("Quarters: "))
    dimes = int(input("Dimes: "))
    nickels = int(input("Nickels: "))
    pennies = int(input("Pennies: "))

    total = (quarters * 25) + (dimes * 10) + (nickels * 5) + pennies

    total = total / 100

    print("This is equal to $", total)
    print()

    #PART 3
    print("PART 3", end ="\n")

    firstName = input("First Name: ")
    lastName = input("Last Name: ")
    address = input("Address: ")
    city = input("City: ")
    state = input("State: ")
    zipcode = input("Zipcode: ")

    print()

    #using exactly 1 print statement
    print(firstName + " " + lastName, address, city + ", " + state + "  " + zipcode, sep='\n')
    
    print()

    #using exactly 6 print statements
    print(firstName, end=' ')
    print(lastName, end='\n')
    print(address, end='\n')
    print(city, end='')
    print(", " + state, end='  ')
    print(zipcode)
    

    

main()

