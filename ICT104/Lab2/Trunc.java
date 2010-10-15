/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.*;
/**
 *
 * @author Zael
 */
public class Trunc
{

    public static void main (String[] args)
    {
        System.out.println("Use out of range entry to quit.");
        double total = 0;
        boolean flag = true;
                Scanner input = new Scanner (System.in);

        while (flag)
        {
            System.out.println("Enter a number: ");

            double a = input.nextDouble();

            if(outOfRange(a))
                flag = false;
            else {
                dispWholeNum("Rounded to ",a);
                total = total + a;
                dispWholeNum("The total is ", total);

                System.out.println();
                System.out.println("Next.");
                }
        }
    }

    public static boolean outOfRange(double d)
    {
            if (d < - 100 || d > 100)
                return(true);
            else
                return(false);
    }

    public static void dispWholeNum(String msg, double num)
    {
        boolean neg = (num < 0);
        double posNum = num;
        if (neg)
            posNum = -num;
        int whole = (int)posNum;
        double rem = posNum - whole;

        if(rem >= 0.5)
            whole++;

        String sign ="";
        if (neg)
            sign = "-";

        System.out.println(msg + " " + sign + whole + ".");

    }
}
