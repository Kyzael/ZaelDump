/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Zael
 */
public class baby {

    private String name;
    private int age;

    public void setName(String input)
    {
        name = input;
    }
    public void setAge(int input)
    {
        age = input;
    }
    public String getName()
    {
        return(name);
    }
    public int getAge()
    {
        return(age);
    }
    public boolean equals(baby baby2)
    {
        if(name.equalsIgnoreCase(baby2.name) && age == baby2.age)
            return(true);
        else
            return(false);
    }
    



 
}
