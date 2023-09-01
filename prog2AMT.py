"""
Angelina Toste
1399403
angelina.toste@und.edu

Program 2:
    The following program prompts the user for a "major" and compares that inputted
    value to the strings "CS", "DATA", "CYBER", and if there is no match, the input for
    major will be counted as "OTHER".

    If "CS" is inputted as the major, the program will ask the user for a "minor" and compare
    the inputted value to the strings "DATA", "CYBER", "MATH",and, if there is a different input,
    the input for the minor will be counted as "OTHER".

    If the string "DONE" is inputted for major, the program will stop and print out the output.
    output:
    - total number of students inputted
    - the different majors of the students (total students for each and percentage of total students)
    - the different minors of the cs students (total students for each and percentage of total cs students)

    *Note: this program is case-INSENSITIVE

"""


def main():
    # initializing counters
    cs = 0
    data = 0
    cyber = 0
    math = 0
    other = 0
    total = 0

    csMin = 0
    dataMin = 0
    cyberMin = 0
    mathMin = 0
    otherMin = 0
    totalMin = 0

    major = input("Enter major: ")

    while major.upper() != "DONE":

        if major.upper() == "CS":
            # ask for the minor if CS has been inputted as the major
            cs += 1
            total += 1

            minor = input("Enter minor: ")
            if minor.upper() == "DATA":
                dataMin += 1
                totalMin += 1

            elif minor.upper() == "CYBER":
                cyberMin += 1
                totalMin += 1

            elif minor.upper() == "MATH":
                mathMin += 1
                totalMin += 1

            else:
                otherMin += 1
                totalMin += 1

        elif major.upper() == "DATA":
            data += 1
            total += 1

        elif major.upper() == "CYBER":
            cyber += 1
            total += 1

        else:
            other += 1
            total += 1

        print()
        major = input("Enter major: ")

    # percents
    pct_cs = (cs / total) * 100
    pct_data = (data / total) * 100
    pct_cyber = (cyber / total) * 100
    pct_other = (other / total) * 100

    
    pct_dataMin = (dataMin / totalMin) * 100
    pct_cyberMin = (cyberMin / totalMin) * 100
    pct_mathMin = (mathMin / totalMin) * 100
    pct_otherMin = (otherMin / totalMin) * 100

    # OUTPUT
    print()
    print("Total number of students ", total)
    print()
    print("Majors of students in CS160")
    print(format("Computer Science", "<15s"), format(cs, ">4d"), format(pct_cs, ">7.2f"))
    print(format("Data Science", "<16s"), format(data, ">4d"), format(pct_data, ">7.2f"))
    print(format("Cyber Security", "<16s"), format(cyber, ">4d"), format(pct_cyber, ">7.2f"))
    print(format("Other Majors", "<16s"), format(other, ">4d"), format(pct_other, ">7.2f"))

    print()
    print("Minors for Computer Science Majors in CS160")
    print(format("Data Science", "<16s"), format(dataMin, ">4d"), format(pct_dataMin, ">7.2f"))
    print(format("Cyber Security", "<16s"), format(cyberMin, ">4d"), format(pct_cyberMin, ">7.2f"))
    print(format("Mathematics", "<16s"), format(mathMin, ">4d"), format(pct_mathMin, ">7.2f"))
    print(format("Other Minors", "<16s"), format(otherMin, ">4d"), format(pct_otherMin, ">7.2f"))


main()
