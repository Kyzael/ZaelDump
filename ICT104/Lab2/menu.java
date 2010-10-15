/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.*;
/**
 *
 * @author Zael
 */
public class menu
{


 public static void main(String[] args)
    {
        char ch;
        Scanner input = new Scanner (System.in);
       do
       {
           printMenu();

          ch = input.nextLine().trim().toLowerCase().charAt(0);

         switch(ch)
            {
            case 'a':
                unitDetails();
                break;
            case 'b':
                largestOfThree();
                break;
            case 'c':
                powerOfNum();
                break;
            case 'd':
                sumOfOdd();
                break;
            case 'e':
                checkTriangle();
                break;
            case 'q':
                System.out.println("Goodbye!");
                break;
            default:
                System.out.println("Pick an option!");
              }
          } while (ch != 'q');
    }





public static void printMenu()
    {
        System.out.println();
        System.out.println("a) Print out Unit Details.");
        System.out.println("b) Find the Greatest of three numbers.");
        System.out.println("c) Largest power <= x.");
        System.out.println("d) Total of odd numbers between two numbers.");
        System.out.println("e) Check triangle.");
        System.out.println("q) To Quit.");
    }

public static void unitDetails()
    {
        System.out.println("Philip Kealley.");
        System.out.println("Tutor: ______");
        System.out.println("Wednesday, 12:30");

    }

public static void largestOfThree()
    {
        Scanner input = new Scanner (System.in);
        int num1, num2, num3;
        int largest;

        System.out.println("Enter first number: ");
        num1 = input.nextInt();
        System.out.println("Enter second number: ");
        num2 = input.nextInt();
        System.out.println("Enter third number: ");
        num3 = input.nextInt();

        if (num1 > num2 && num1 > num3)
            largest = num1;
        else if(num2 > num3)
            largest = num2;
        else
            largest = num3;

        System.out.println("The Largest is " + largest + ".");
    }

public static void powerOfNum()
    {
        int x;
        int k = 1;
        double test= 0.0;
        boolean flag = true;
        Scanner input = new Scanner (System.in);
            do
            {
                System.out.println("Enter a number > 1: ");
                x = input.nextInt();

            } while (x < 1);

        while(flag)
        {
               test = Math.pow(2.0,((double)k));
               if(test < (double)x)
               {
                   k++;
                 }
               else{
                   if(test == (double)x)
                   {
                       k++;
                       flag = false;
                   }
                    else{
                       k--;
                        flag = false;
                        }
                    }
        }
        System.out.println("2^" + (k) + " is the largest that is <=  " + x);

}

public static void sumOfOdd()
    {
        Scanner input = new Scanner (System.in);
        int num1, num2;
        int count = 0;
        int start;
        int end;
        int total=0;

        System.out.println("Enter first number: ");
        num1 = input.nextInt();
        System.out.println("Enter second number: ");
        num2 = input.nextInt();

        if (num1 < num2)
        {
            start = num1;
            end = num2;
        }
        else
        {
            start = num2;
            end = num1;
        }

        for(;start <= end; start++)
        {
            if(start%2 != 0)
                total = total + start;

            System.out.print(start+ " ");
            count++;
            if(count == 6)
            {
                System.out.println();
            count = 0;
            }
        }
        System.out.println("\nSum of odd numbers = " + total);
    }

public static void checkTriangle()
    {
        Scanner input = new Scanner (System.in);
        int s1,s2,s3;

        System.out.println("Enter Side1: ");
        s1 = input.nextInt();
        System.out.println("Enter Side2: ");
        s2 = input.nextInt();
        System.out.println("Enter Side3 ");
        s3 = input.nextInt();

        if(s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1)
            System.out.println(s1 + ", " + s2 + ", " + s3 + ": Its a triangle!");
        else
            System.out.println(s1 + ", " + s2 + ", " + s3 + ": Its NOT a triangle!");

    }

}
