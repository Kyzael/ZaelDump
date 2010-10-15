/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Zael
 */
public class FractionDemo {

    public static void main(String[] args)
    {
        Fraction input = new Fraction();
        boolean flag = true;
        do
        {
            input.input();
            //creates input fraction with default constructor.
            if(input.isZero())
                flag = false;
            else
                input.output();

        }while(flag);
     }
}

