import java.lang.*;

public class Solution
{
    public int addDigits(int num)
    {
        // Find the digital root of the number
        return (int)(num - 9*Math.floor((num-1)/9));
    }
}