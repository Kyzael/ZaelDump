/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.*;
/**
 *
 * @author Zael
 */
public class Buffer {

    public static void main(String[] args)
    {
        Scanner kb = new Scanner(System.in);
        String input = new String();
        System.out.println("Enter String: ");
        input = kb.nextLine();
        StringBuffer temp = new StringBuffer(input);
        char a, b;
        if (temp.length() > 1)
        {
            a = temp.charAt(temp.length()-1);
            b = temp.charAt(0);
           temp.setCharAt(temp.length()-1, b);
           temp.setCharAt(0, a);
           input = temp.toString();
        }
        else
            System.out.println("String not long enough!");

       System.out.println(input);
    }
}
