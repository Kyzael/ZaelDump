/*
 *ICT 104 - Principles of Computer Science
 * Assignment 1 - Question 3
 * Philip Kealley - 31247952
 * 16/09/2010
 * Survey.class
 *
 * Purpose: Used by Question3 to store survey results, calculate percentages and print.
 *
 */

public class Survey
{
       //survey results
    private int femaleUnder,femaleOver, maleOver, maleUnder, total;
    private String showName;

    public void clear()
    {
        //clears all the survey values
       femaleUnder = 0;
       femaleOver = 0;
       maleOver = 0;
       maleUnder = 0;
       total = 0;

    }

    public void setName(String input)
    {
        //set the survey name
        showName = input;
    }

    public void addTotal()
    {
        //incerement total
       total++;
    }

    //basic variable calls
    public int getTotal()
    {
        return(total);
    }

    public String getName()
    {
        return(showName);
    }


    public void addStatistic(int age, char gender)
    {
    // passes the survey details of individual users through the logic to
    // increment the correct variable
      if(age <35 )
        if(gender == 'm')
            maleUnder++;
        else
            femaleUnder++;
      else
        if(gender=='m')
            maleOver++;
        else
            femaleOver++;
    }

    public int getTotalRegular()
    {
        //adds up the variables to find the total off all regular.
        return(femaleUnder + femaleOver + maleOver + maleUnder);
    }

    public int percentage(int num1, int num2)
    {
        //calculates num1 percent of num2 and rounds to return an integer.
        double percent = ((double)num1 / num2 * 100);
		int whole = (int) percent;
		percent = percent - whole;
		whole = whole + (int)(percent + 0.5);

        return(whole);
    }

    //the next 3 functions print the percentages of regular users with
    // a specified gap between the values.
    public void printMalePercentages(String spacing)
    {
        int totalMale = maleUnder + maleOver;
        int regular = getTotalRegular();

        System.out.print(spacing);
        System.out.print(percentage(maleUnder, regular));
        System.out.print(spacing);
        System.out.print(percentage(maleOver, regular));
        System.out.print(spacing);
        System.out.print(percentage(totalMale, regular));
      }

    public void printfemalePercentages(String spacing)
    {
        int totalFemale = femaleUnder + femaleOver;
        int regular = getTotalRegular();

        System.out.print(spacing);
        System.out.print(percentage(femaleUnder, regular));
        System.out.print(spacing);
        System.out.print(percentage(femaleOver, regular));
        System.out.print(spacing);
        System.out.print(percentage(totalFemale, regular));
      }

    public void printTotalPercentages(String spacing)
    {
        int totalUnder = femaleUnder + maleUnder;
        int totalOver = femaleOver + maleOver;
        int regular = getTotalRegular();

        System.out.print(spacing);
        System.out.print(percentage(totalUnder, regular));
        System.out.print(spacing);
        System.out.print(percentage(totalOver, regular));
        System.out.print(spacing);
        System.out.print(percentage(totalOver + totalUnder, regular));  // to check accuracy 100 should be calculated here.
     }
}