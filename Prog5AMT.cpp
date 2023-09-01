/*
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
*/
 
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

    // research how to add to unordered map
    bool addPart(unordered_map <string, double>& parts, string part, double cost)
    {
        /*
        Ensures that the specified part/cost key/value pair is in the data structure.
        Returns a true value if the pair is a new pair/added to the data structure.
        Returns a false value if the pair is not new, with the cost being updated.
        :param parts:an unordered map containing all of the parts and their prices
        :param part: the part that will be searched for in the parts map/ dictionary
        :param cost: the cost associated with the part that will be searched for in the map/dictionary
        :return: true if the pair is new to the data structure, false if it exists already
            and the cost will be changed if it is specified differently
        */

        for (auto item : parts) 
        {
            if (part == item.first)
            {
                if(cost == item.second)
                {
                    return false;
                }
                else
                {
                    parts.at(part) = cost;
                    
                    return false;
                }
            }
        }
        parts.insert(pair<string, double>(part, cost));
        return true;
    }


    int totalParts(unordered_map <string, double>& parts)
    {
        /*
        Returns the number of unique parts (int) in the data structure.
        :param parts: the unordered map of parts
        :return: an integer number representing the number of parts in the data structure
        */
        
        //initializing counter
        int x = 0;

        for (auto item:parts)
        {
            x++;
        }    
        return x;
    }


    vector<string> partsGreaterThan(unordered_map <string, double> &parts, double upperLimit)
    {
        /*
        Returns a list/array of the part names with a price greater than or equal to the upperLimit variable.
        The list should be created in the function.
        :param parts: an unordered map containing all of the parts and their prices
        :param upperLimit: a double indicating the limit that the part prices must exceed
        :return:a list of the part names that have prices greater or equal to the upperLimit
        */
        
        vector<string> greaterList;
        
        for (auto item: parts)
        {
            if (item.second >= upperLimit)
            {
                greaterList.push_back(item.first);
            }
        }
        return greaterList;
    }


    bool isPart(unordered_map <string, double>& parts, string part)
    {
        /*
        Returns a true value if part is a valid part in data structure, otherwise return a false value.
        The case of the parts should not matter.
        :param parts:the unordered map of prices and their corresponding costs
        :param part:the part that is being searched for in the data structure
        :return: true if the part exists in the data structure, 
            false if the part does NOT exist in the data structure
        */
        
        for (auto x:part)
        {
            x = tolower(x);
        }
        
        for (auto item:parts)
        {
            for (auto x:item.first)
            {
                x = tolower(x);
            }
            
            if(part == item.first)
            {
                return true;
                
            }
        }
        return false;
    }
    
    

    string leastExpensivePart(unordered_map <string, double>& parts)
    {
        /*
        Returns the part name with the least expensive price.
        You can assume that there will be only one part with the least expensive price.
        :param parts:the unordered map containing the parts and their corresponding prices
        :return: the name of the part that has the least expensive price
        */
        
       // set least to the first value in the list
        double least = -1;
        
        for (auto item:parts)
        {
           least = item.second;
           
           break;
        }
        
        string leastPart = "";
        for (auto item:parts)
        {
           if (item.second < least)
           {
                least = item.second;
                leastPart = item.first;
           }
        }
        
        return leastPart;
    }

    string mostExpensivePart(unordered_map <string, double>& parts)
    {
        /*
        Returns the part name with the most expensive price. 
        You can assume that there will be only one part with the most expensive price.
        :param parts: the unordered map containing the parts and their corresponding prices
        :return:the part name with the most expensive price
        */
        // set most to the first value in the list
        double most = -1;
        
        for (auto item:parts)
        {
            most = item.second;
           
           break;
        }
        
        
        string mostPart = "";
        for (auto item:parts)
        {
            if (item.second > most)
            {
                most = item.second;
                mostPart = item.first;
            }
                
        }
        return mostPart;
    }


    double averagePrice(unordered_map <string, double> parts)
    {
        /*
        Returns the average of all parts in the dictionary. 
        Return -1 if you are unable to determine the average.
        :param parts: the unordered map containing the parts and their corresponding prices
        :return: average of all the part prices in the dictionary
        */

        double sum = 0.0;

        for (auto item:parts)
        {
            sum = sum + item.second;
        }
        
        double average = sum / double(totalParts(parts));
            
        if (totalParts(parts) == 0)
        {
            // zero division error
            return -1;
        }

        return average;
        
    }
    
    void printParts(unordered_map <string, double> parts)
    {
        /*
        This function WILL write to the display a table of each part and its price. 
        Include column headers in the output. Make sure the price 
        has two places after the decimal point. Also make sure the columns are neatly aligned, 
        with the part column being left justified and the price column being right justified. 
        This function/method should not return a value
        
        :param parts: the unordered map containing the parts and their corresponding prices
        :return: does not return anything, this is a void function
        */
        
        int length = 11;
        for (auto item:parts)
        {
            cout << setw(length) << left << item.first << fixed << right << setw(6) << setprecision(2) << double(item.second) << endl;
        }
        
    }


int main(int argc, char** argv)
{
    unordered_map <string, double> parts;
    
    parts["Hammer"] = 5.0;
    parts["Nails"] = 3.0;
    parts["Drill"] = 7.0;
    parts["Wrench"] = 8.0;
    parts["Handsaw"] = 15.0;
    
    cout << addPart(parts, "Nails", 3.0) << endl;
    cout << addPart(parts, "Nails", 4.0) << endl;
    cout << addPart(parts, "Drill Bits", 5.0) << endl;
    cout << endl;
    
    cout << totalParts(parts) << endl;
    cout << endl;
    
    vector<string> greaterList = partsGreaterThan(parts, 6.0);
    
    for(auto x:greaterList)
    {
        cout << x << " ";
    }
    
    cout << endl;
    cout << endl;
    
    cout << isPart(parts, "Nails") << endl;
    cout << isPart(parts, "Screws") << endl;
    cout << endl;
    
    cout << leastExpensivePart(parts) << endl;
    cout << endl;
    
    cout << mostExpensivePart(parts) << endl;
    cout << endl;
    
    cout << averagePrice(parts) << endl;
    cout << endl;
    
    printParts(parts);
    
    return 0;
}