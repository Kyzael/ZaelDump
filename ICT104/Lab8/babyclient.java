/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Zael
 */

import java.util.*;

public class babyclient {

    public static void main(String args[])
    {
        baby[] babies = new baby[3];
        fillArray(babies);
        checkArrayDuplicates(babies);
        outputArray(babies);

    }
    public static void fillArray(baby[] babies)
    {
        for(int i = 0; i < babies.length; i++)
        {
            System.out.println("Enter details for baby " + (i + 1));
            babies[i] = inputBaby();
        }
    }
    public static baby inputBaby()
    {
        baby input = new baby();
        String name;
        int age;
        Scanner kb = new Scanner (System.in);

        System.out.println("Baby Name: ");
            name = kb.nextLine();
        System.out.println("Enter Baby Age: ");
            age = kb.nextInt();

          input.setName(name);
          input.setAge(age);

          return(input);
    }
    public static void checkArrayDuplicates(baby[] babies)
    {
        int i = 0;
        int test = 1;
        boolean found = false;

        while(i < babies.length && !found)
        {
            while(test < babies.length && !found )
            {
                if (babies[i].equals(babies[test]))
                {
                    found = true;
                    System.out.println("Duplicate baby was found!");
                }
                else
                    test++;
            }
            i++;
        }
    }

    public static void outputArray(baby[] babies)
    {
        for(int i = 0; i < babies.length; i++)
        {
            System.out.println();
            System.out.println("Baby " + (i + 1) + ": ");
            System.out.println("Name: " + babies[i].getName());
            System.out.println("Age: " + babies[i].getAge());
        }
    }
}
