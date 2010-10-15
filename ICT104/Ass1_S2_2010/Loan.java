/*
 *ICT 104 - Principles of Computer Science
 * Assignment 1 - Question 1
 * Philip Kealley - 31247952
 * 16/09/2010
 * Loan.class
 *
 * Purpose: This class is used by Question1 to store loan amount and years
 *          and perform calculations on the loans.
 */

public class Loan
{
    private double Amount;
    private int Years;

    public Loan() {
        Amount = 10000;
        Years = 5;

    }

    public void setLoan(double loan)
        {
            Amount = loan;
        }
        
        public void setYears(int num)
    {
       Years = num;
    }
//variable calls below
    public int getYears() {
        return (Years);
    }

    public double getAmount() {
        return (Amount);
    }

    public double monthly(double interest) {

        //function calculates monthly interest

        double monthly;
        interest = (interest / 12) * 0.01; //converts whole number % into decimal for calculation

        monthly = (Amount * interest) / (1 - (1 / Math.pow((1 + interest), (Years * 12))));
        return (monthly);
    }

    public double total(double interest) {
        //function calls the monthly interest of the current object to calculate yearly interest.
        return (this.monthly(interest) * 12 * Years);
    }

}
