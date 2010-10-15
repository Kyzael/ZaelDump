/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Zael
 */
public class FractionDemo2 {

     public static void main(String[] args)
    {
        Fraction a = new Fraction();
        Fraction b = new Fraction();
        boolean flag = true;
        do
        {
            System.out.println("Enter First Fraction");
            a.input();
            if(a.isZero())
            {
                flag = false;
                System.out.println("Fraction is 0!");
            }
            else
            {
                System.out.println("Enter Second Fraction");
                b.input();
                if (a.equals(b))
                {
                    System.out.println("Fractions are Equal");
                }
                Fraction result = a.add(b);
                result.output();
                System.out.println();
            }
        }while(flag);
     }
}
