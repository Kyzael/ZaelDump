/*
 * ICT 104 - Principles of Computer Science
 * Assignment 1 - Question 1
 * Philip Kealley - 31247952
 * 16/09/2010
 * Question1.class
 *
 * Purpose: Print Monthly and total repayments of a loan for a range of interest
 *          rates over x years.
 *
 * Assumptions: when asked for a character input the user does not enter null.
 *              when asking for a number the user enters a number.
 */

import java.util.*;

public class Question1
{

    public static void main(String[] args)
    {
        Loan User = new Loan(); //construc loan object  "see loan source"
        double rate1, rate2;

        do
        {
             /*Prints out input prompts specific to this program
              *calls input functions for each input*/

            System.out.println("Enter Loan Amount: ");
                User.setLoan(getPositiveNumber());
            System.out.println("Enter number of years:");
                User.setYears((int)getPositiveNumber());
            System.out.print("Enter starting interest rate: ");
                rate1 = getPositiveNumber();
            System.out.print("Enter ending interest rate: ");
                rate2 = getPositiveNumber();
            outputTable(rate1, rate2, User);
                System.out.println();
                System.out.print("Enter a new loan? (Y/N)");

        }while(yesOrNo());
    }

    public static double getPositiveNumber()
    {
        //Fuction takes a number input and only passes the variable to main when the input is positive.
        Scanner input = new Scanner(System.in);
        double num;
        boolean test = false;

        do
        {
            num = input.nextDouble();
            if(num < 1)
            {
                test = true;
                System.out.println("Enter a positive number!");
            }
            else
                test = false;
            
        }while(test);

        return(num);
    }

    public static void outputTable(double rate1, double rate2, Loan User)
    {

        System.out.println("Loan Amount: " + User.getAmount());
        System.out.println("Years: " + User.getYears());
        System.out.println("Interest Rate   Monthly payment     Total Payment"); //Headers

        //loops through each interest rate in .25 increments.
        for(double i = rate1; i <= rate2; i = i + 0.25)
        {
        //each loop is also printing a line of the table passing the interest value to the Loan class
        // then the result into the dispTwoDPs for printing.
            dispTwoDPs(i);
            System.out.print("%            ");

            dispTwoDPs(User.monthly(i));
            System.out.print("             ");

            dispTwoDPs(User.total(i));
            System.out.println();
          }
         
    }

    static void dispTwoDPs(double num)
    {
        /*this basic algorithm is from the unit lecture notes  to print a number with two decimal places.
         *this module has been changed so that it does not round and does not account for negative numbers.*/

        double num1 = num;

        int whole = (int) num1;
        double rest = num1 - whole;
        int temp = (int ) ( 100.0 * rest + 100.0 );

        String s = "" + temp;
        int l = s.length();

        System.out.print(whole + "." + s.substring(l-2,l));
    }



    public static boolean yesOrNo()
    {
    //this function forces user input of y or n and then returns boolean value
    // for true or false.
        Scanner input = new Scanner(System.in);
        char ch;

        

        do
        {
            ch = input.nextLine().toLowerCase().trim().charAt(0);
        }while(ch != 'y' && ch != 'n');

        if(ch == 'y')
            return(true);
        else
            return(false);
    }
}
