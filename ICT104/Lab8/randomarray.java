/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Zael
 */
import java.util.*;

public class randomarray {


    public static void main(String[] args)
    {

    Scanner kb = new Scanner(System.in);
    int store[];
    int input;
    double average;
    int largest;
    int smallest;
    
    System.out.println("Enter amount of random numbers to generate: ");
    input = kb.nextInt();
    store = new int[input];
    
    fillArrayRandom(store);
    largest = findLargestNumber(store);
    smallest = findSmallestNumber(store);
    average = findAverageNumber(store);
    sortArrayAscending(store);
    printArray(store);

    System.out.println();
    System.out.println("Average number is: " + average);
    System.out.println("Smallest number is: " + smallest);
    System.out.println("Largest number is: " + largest);
            
    }
    public static void fillArrayRandom(int[] input)
    {
        Random rand = new Random();
        for(int i = 0; i < input.length; i++ )
        {
            input[i] = (rand.nextInt(999) + 1);
        }
    }
    public static double findAverageNumber(int[] input)
    {
        double average;
        int sum = 0;

        for(int i = 0; i < input.length; i++)
        {
            sum = sum + input[i];
        }
        average = (double)sum / input.length;
        return(average);

    }
    public static int findSmallestNumber(int[] input)
    {
        int smallest = input[0];
        for(int i = 1; i < input.length; i++)
        {
            if(input[i] < smallest)
                smallest = input[i];
        }
        return(smallest);
    }
    public static int findLargestNumber(int[] input)
    {
        int largest = input[0];
        for(int i = 1; i < input.length; i++)
        {
            if(input[i] > largest)
                largest = input[i];
        }
        return(largest);
    }

    public static void sortArrayAscending(int[] store)
    {
        int Largest, last, temp;

        for(last = store.length -1; last >=1; last--)
        {
            Largest = 0;
            for(int i = 1; i <= last; i++)
            {
                if(store[i] > store[Largest])
                    Largest = i;
            }
            temp = store[last];
            store[last] = store[Largest];
            store[Largest] = temp;
        }

    }

    public static void printArray(int[] store)
    {
        int count = 0;
        for(int i = 0; i < store.length; i++)
        {
            if(count == 5)
            {
                System.out.println();
                count = 0;
            }

            count++;
            System.out.print(store[i] + " ");
        }
    }
}
