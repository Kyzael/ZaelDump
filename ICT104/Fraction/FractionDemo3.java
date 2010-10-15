/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * Author: Philip Kealley
 * Unit ICT 104
* 14/09/2010
 */
public class FractionDemo3 {

    public static void main(String[] args)
    {
    boolean flag = true;
    Fraction a = new Fraction();
    Fraction sum = new Fraction(0,1);
    double total;
     do
        {
         System.out.println("\nEnter Fraction:");
         a.input();
         if(a.isZero())
             flag = false;
         else
         {
             sum = sum.add(a);
             System.out.print("\nFraction total: ");
             sum.output();
             total = sum.dblValue();
             System.out.print(" Decimal value: " + total);
          }
        }while(flag);

}
}
