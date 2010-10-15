/*
 *
 * ICT 104 - Principles of Computer Science
 * Assignment 1 - Question 2
 * Philip Kealley - 31247952
 * 16/09/2010
 * Question2.class
 *
 *  Purpose: Find if a number is palindrome, if it is not  add the number to
 *           the reverse of that number and continue until a palindrome is found.
 *
 *      Assumptions: User enters an integer when asked.
 */

import java.util.*;

public class Question2
{

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int original;
        boolean quit = false;
        long reverse;
        int count;
        boolean test;

        do 
        {
            //loops until a -number is entered

            System.out.println();
            System.out.println("Enter number to find palindrome: ");
            original = input.nextInt();
            count = 0;
            test = false;

            
               if(original < 0)  //checks for negative input
                   quit = true;
               else
               {
                do
                {
                    //loops until palindrom is found
                    if(checkPalindrome(original))
                    {
                    System.out.println(original +" is a palindrome!");
                    System.out.println(count + " calculations.");
                    test = true;
                    }
                    else
                    {
                        // reverses input and adds to oiginal checking if the answer will still fit inside an int.
                        reverse = getReverse(original);
                        if(checkOverMax(original, reverse))
                            test = true;
                        else
                        {
                            original = sumAndPrint(original,(int)reverse);
                            count++; //increases count of calculations
                        }
                    }
                  
                }while(!test);
              }
        }while(!quit);
     }

        public static long getReverse(int remainder)
                //function reverses integers
        {
            long reverse = 0;
            while(remainder > 0)
            {
                reverse = reverse * 10;
                reverse= reverse + remainder % 10;
                remainder = remainder / 10;
            }
            return(reverse);
        }

        public static int sumAndPrint(int num1, int num2)
         {
            //function prints out the calculations it is performaing and performs the calculation.
            System.out.print(num1 + " + " + num2 + " = " );
                num1 = num1 + num2;
            System.out.println(num1);
            return(num1);
        }
            

        public static boolean checkPalindrome(int num)
            {
            //checks if the integer is a palindrome by reversing the int and
            //comparing the reverse value to the original value
            int reverse = (int)getReverse(num);

            if(reverse == num)
                return(true);
            else
                return(false);

            }

        public static boolean checkOverMax(int num1, long num2)
        {
            //performs addition of int and a double to check if the value can be stored inside an integer.
            long result = num1 + num2;
            int max = Integer.MAX_VALUE;
                        
            if(result > max)
            {
                System.out.println("Calculation will exceed Memory size!");
                return(true);
            }
            else
                return(false);

        }

}