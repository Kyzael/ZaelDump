/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 31247952
 */
public class time {

    String time, hour, minute, mm;

 time()
 {
     time = "00:00:am";
 }

 time(String input)
{
    time = input;
    time.trim();
}

 void setTime(String input)
 {
     time = input;
     time.trim();
 }

 boolean checkValidTime()
 {
     boolean valid;
    String[] store;
    store = time.split(":", 2);
    hour = store[0];
        valid = checkhour();
    minute = store[1].substring(0, 2);
        valid = checkMinutes();
    mm = store[1].substring(2, store[1].length());

 }
 
 boolean checkhour()
 {
     Integer converthours;
     int hours, test;
     hour.trim();
     if(hour.length() != 2)
     {
         System.out.println("Invalid Hour!");    
     }
     else 
         do
         {
         test = (int)hour.charAt(0);
         
         if(  < 45 )
         hours = new Integer(converthours);
         hours = converthours.intValue();
         if(hour.)
 }






}