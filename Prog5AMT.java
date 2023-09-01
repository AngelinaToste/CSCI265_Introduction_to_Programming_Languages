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

import java.util.*;
public class Main
{

 
    public static Boolean addPart(HashMap <String, Double> parts, String part, double cost)
    {
        /*
        Ensures that the specified part/cost key/value pair is in the data structure.
        Returns a true value if the pair is a new pair/added to the data structure.
        Returns a false value if the pair is not new, with the cost being updated.
        :param parts: a hash map containing the parts and their corresponding prices
        :param part: the part that will be searched for in the parts map/ dictionary
        :param cost: the cost associated with the part that will be searched for in the map/dictionary
        :return: true if the pair is new to the data structure, false if it exists already
            and the cost will be changed if it is specified differently
        */

        for (String item : parts.keySet()) 
        {
            if (part.equals(item))
            {
                if(cost == parts.get(item))
                {
                    return false;
                }
                else
                {
                    parts.put(item, cost);
                    return false;
                }
            }
        }
        parts.put(part, cost);
        return true;
    }


    public static int totalParts(HashMap <String, Double> parts)
    {
        /*
        Returns the number of unique parts (int) in the data structure.
        :param parts:a hash map containing the parts and their corresponding prices
        :return: an integer number representing the number of parts in the data structure
        */
        
        //initializing counter
        int x = 0;

        for (String item:parts.keySet())
        {
            x++;
        }    
        return x;
    }


    public static ArrayList<String> partsGreaterThan(HashMap <String, Double> parts, Double upperLimit)
    {
        /*
        Returns a list/array of the part names with a price greater than or equal to the upperLimit variable.
        The list should be created in the function.
        :param parts:a hash map containing the parts and their corresponding prices
        :param upperLimit:a double indicating the limit that the part prices must exceed
        :return: a list of the part names that have prices greater or equal to the upperLimit
        */
        
        ArrayList<String> greaterList = new ArrayList<String>();
        
        for (String item: parts.keySet())
        {
            if (parts.get(item) > upperLimit)
            {
                greaterList.add(item);
            }
        }
        
        return greaterList;
    }


    public static Boolean isPart(HashMap <String, Double> parts, String part)
    {
        /*
        Returns a true value if part is a valid part in data structure, otherwise return a false value.
        The case of the parts should not matter.
        :param parts:a hash map containing the parts and their corresponding prices
        :param part:the part that is being searched for in the data structure
        :return: true if the part exists in the data structure, 
            false if the part does NOT exist in the data structure
        */
        
        
        String partLower = part.toLowerCase();
        
        
        for (String item:parts.keySet())
        {
            
            String itemLower = item.toLowerCase();
            
            if(partLower.equals(itemLower))
            {
                return true;
                
            }
        }
        return false;
    }
    

    public static String leastExpensivePart(HashMap <String, Double> parts)
    {
        /*
        Returns the part name with the least expensive price.
        You can assume that there will be only one part with the least expensive price.
        :param parts:a hash map containing the parts and their corresponding prices
        :return:the name of the part that has the least expensive price
        */
        
        // set least to the first value in the list
        
        
        double least = -1;
        
        for (String item:parts.keySet())
        {
            least = parts.get(item);
           
           break;
        }
        
        String leastPart = "";
        for (String item:parts.keySet())
        {
           if (parts.get(item) < least)
           {
                least = parts.get(item);
                leastPart = item;
           }
        }
        
        return leastPart;
    }

        
    public static String mostExpensivePart(HashMap <String, Double> parts)
    {
        /*
        Returns the part name with the least expensive price. 
        You can assume that there will be only one part with the least expensive price.
        :param parts:a hash map containing the parts and their corresponding prices
        :return:the part name with the most expensive price
        */
        
        // set most to the first value in the list
        
        double most = -1;
        
        for (String item:parts.keySet())
        {
            most = parts.get(item);
           
           break;
        }
        
        String mostPart = "";
        for (String item:parts.keySet())
        {
           if (parts.get(item) > most)
           {
                most = parts.get(item);
                mostPart = item;
           }
        }
        
        return mostPart;
    }

    public static double averagePrice(HashMap <String, Double> parts)
    {
        /*
        Returns the average of all parts in the dictionary. 
        Return -1 if you are unable to determine the average.
        :param parts:a hash map containing the parts and their corresponding prices
        :return:average of all the part prices in the dictionary
        */

        double sum = 0;

        for (String item:parts.keySet())
        {
            
            sum = sum + parts.get(item);
        }
        
        double average = sum / totalParts(parts);
            
        if (totalParts(parts) == 0)
        {
            // zero division error
            return -1;
        }

        return average;
        
    }
    
    
    public static void printParts(HashMap <String, Double> parts)
    {
        /*
        This function WILL write to the display a table of each part and its price. 
        Include column headers in the output. Make sure the price 
        has two places after the decimal point. Also make sure the columns are neatly aligned, 
        with the part column being left justified and the price column being right justified. 
        This function/method should not return a value
        
        :param parts: a hash map containing the parts and their corresponding prices
        :return: this function does not return anything, it is a void function
        */
        
        //find the longest part name for the width of the item column
        int length = 0;
        
        for (String item:parts.keySet())
        {
            int itemlen = item.length();
            if (itemlen > length)
            {
                length = itemlen;
            }
        }
        
    
        for (String item:parts.keySet())
        {
            System.out.printf("%-" + length + "s %5.2f\n", item, parts.get(item));
        }
        
    }

    public static void main (String[] args)
    {
       HashMap <String,Double> parts = new HashMap <String, Double>();
    
        parts.put("Hammer", 5.0);
        parts.put("Nails", 3.0);
        parts.put("Drill",7.0);
        parts.put("Wrench",8.0);
        parts.put("Handsaw",15.0);
    
        System.out.println(addPart(parts, "Nails", 3.0));
        System.out.println(addPart(parts, "Nails", 4.0));
        System.out.println(addPart(parts, "Drill Bits", 5));
        System.out.println();
        System.out.println(totalParts(parts));
        System.out.println();
        System.out.println(partsGreaterThan(parts, 6.0));
        System.out.println();
        System.out.println(isPart(parts, "Nails"));
        System.out.println(isPart(parts, "Screws"));
        System.out.println();
        System.out.println(averagePrice(parts));
        System.out.println();
        System.out.println(leastExpensivePart(parts));
        System.out.println(mostExpensivePart(parts));
        System.out.println();
        printParts(parts);

    }

}
