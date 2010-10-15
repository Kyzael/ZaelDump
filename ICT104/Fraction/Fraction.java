/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.*;
/**
 *
 * @author Philip Kealley
 */
public class Fraction {
   private int d, n;

   public Fraction()
    {
       //default constructor.
       n = 0;
       d = 1;
   }

    public Fraction (int num1, int num2)
    {
        //overloading constructor for arguments.
            n = num1;
            d = num2;
    }
 public void input()
     {
       Scanner input = new Scanner(System.in);
       //Keyboard input.
       System.out.println("Enter Numerator");
       n = input.nextInt();
       System.out.println("Enter Denominator");
       d = input.nextInt();
       if(d < 0)
       {
           d = -d; // forces positive inputs.
           n = -n;
       }
    }

    public double dblValue()
    {
        return((double)n / d);
    }
    public double valOf(double num1, double num2)
    {
        return(num1/num2);
    }
   public boolean equals(Fraction b)
    {
      if(n * b.d == d * b.n ) //checks if fraction in decimal = fraction b in decimal.
          return(true);
      else
          return(false);
   }
   private int getN()
    {
       return(n);
   }
   private int getD()
    {
       return(d);
    }

    public boolean isZero()
    {
        if (n == 0 || d == 0) //if the denmoninator or numerator is 0.
            return(true);
        else
            return(false);
    }

    public Fraction add ( Fraction b)
    {
        int denominator = d * b.d;
        int numerator = (n * b.d) + (b.n * d);
        return(new Fraction(numerator, denominator)); //passes new fraction after sum.

    }
    public void output()
    {
        System.out.print(n + "/" + d);
    }

}
