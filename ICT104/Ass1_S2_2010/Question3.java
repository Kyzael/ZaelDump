
/*
 *ICT 104 - Principles of Computer Science
 * Assignment 1 - Question 3
 * Philip Kealley - 31247952
 * 16/09/2010
 * Question3.class
 *
 * Purpose: Takes information surveyed from people and uses the Survey class to
 * find and print the survey results.
 *
 * Assumptions: The user inputs the correct type when asked.
 */

import java.util.*;

public class Question3
{


public static void main(String[] args)
{
    Scanner input = new Scanner(System.in);
    Survey tvShow = new Survey();
    
    do
    {
        //loops until user does not want to enter a new survey.
        System.out.print("Enter the Television show name:");
        tvShow.setName(input.nextLine());
        System.out.println();
        tvShow.clear(); // needed to start a new survey.
        tvShow = getUserInput(tvShow);
        outputDistribution(tvShow);
        
       System.out.println("Enter new Televison Show? (y/n): ");
    }while(yesOrNo());
    
 }


    public static Survey getUserInput(Survey user)
    {
           char gender;
            int age;

        do
        {
         //loops until user chooses to exit.
            user.addTotal();
            System.out.println("Enter person's age(1..110):");
                
                age = getAge();
                    
            System.out.println("Enter person's gender(m/f): ");
                
                gender = getGender();
                      
            System.out.println("Enter whether this person watches the show regularly (Y/N):");

                if(yesOrNo())
                {
                    user.addStatistic(age, gender);
                    
                }
                System.out.println("Enter another person? (Y/N)");
        }while(yesOrNo());
        
        return(user);
    }

public static void outputDistribution(Survey tvShow)
    {
    String spacer = "             ";
    int total = tvShow.getTotal();
    int regular = tvShow.getTotalRegular();
    //inital survey reults
    System.out.println("Survey of: " + tvShow.getName());
    System.out.println("The total number of people called = " + total);
    System.out.println("The number of people who watch the show regularly = " + regular);
    System.out.println("The percentage of those who watch the show regularly = " + tvShow.percentage(regular, total) + "%");

    //prints table headers then calls the print functions for each row.
    System.out.println("---------------------------------------------------------");
    System.out.println("Gender        %Under 35        %Over 35       %Total   ");
    System.out.println("---------------------------------------------------------");
    System.out.println();
    System.out.print("Male  ");
    tvShow.printMalePercentages(spacer);
    System.out.println();
    System.out.print("Female");
    tvShow.printfemalePercentages(spacer);
    System.out.println();
    System.out.println("---------------------------------------------------------");
    System.out.print("Total ");
    tvShow.printTotalPercentages(spacer);
    System.out.println();
    }

public static int getAge()
    {
    //input validation for age.
    Scanner input = new Scanner(System.in);
    int age;

    do
    {
            age = input.nextInt();
        } while(age < 1 || age > 110);
    
    return(age);
}

public static char getGender()
    {
    //input validation for gender.
    Scanner input = new Scanner(System.in);
    char gender;
    do
    {
        gender = input.nextLine().trim().toLowerCase().charAt(0);

     }while(gender != 'f' && gender != 'm');

    return(gender);

    }

public static boolean yesOrNo()
    {
    //input validation for y/n
    Scanner input = new Scanner(System.in);
    char ch;

        

        do
        {
         ch = input.nextLine().trim().toLowerCase().charAt(0);
        }while(ch != 'y' && ch != 'n');

        if(ch == 'y')
            return(true);
        else
            return(false);
}

}
