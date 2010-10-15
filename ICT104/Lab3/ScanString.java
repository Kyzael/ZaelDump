/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.*;
/**
 *
 * @author Zael
 */
public class ScanString {

    public static void main(String[] args)
    {
    System.out.println("Enter String: ");
    Scanner kb = new Scanner (System.in);
    String input = new String();
    input = kb.nextLine();
    boolean test = false;


        for(int i=0; i < input.length(); i++)
        {
            for (int c = i + 1; c < input.length(); c++)
            {
               if(input.charAt(i) == input.charAt(c))
                {
                        test = true;
                        
                }
             }

          }
    if(test)
        System.out.println("Multiple characters found!");
    else
        System.out.println("No multiple characters found.");
     }
}


