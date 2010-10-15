/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;      // jdk 1.5 upwards only
/**
 *
 * @author Zael
 */
public class SmallIO {
    public static void main(String[] args){
		Scanner keyboard = new Scanner (System.in);
		int a = 1;
                int count = 1;
                double average;
                int total = 0;
                int large = 0;
                int small = 0;
		while (a != 0){
			

			System.out.println("Enter a Number:");

			a= keyboard.nextInt();
                        total = total + a;
                        average = (double)total / count;
                        if(count == 1)
                            small = a;
                        if (a > large)
                            large = a;
                        if (a < small)
                            small = a;
                        count++;
			System.out.println("Total:");
			System.out.println(total);
                        System.out.println("Average:");
			System.out.println(average);
                        System.out.println("Largest:");
                        System.out.println(large);
                        System.out.println("Smallest");
                        System.out.println(small);
		}//end of while
	}//end of main
}//end of class
