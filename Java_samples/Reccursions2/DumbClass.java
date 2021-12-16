public class DumbClass
{
    private int move;
    public void datang(int numdisks, char from, char to, char extra){
        if(numdisks != 1)
        datang(numdisks-1,from,extra,to);
        move++;
        System.out.println("Move " + move + ": disk from " + from + " to " + to);
        if(numdisks != 1)
        datang(numdisks-1,extra,to,from);
    }
    public boolean isPalindrome(String str)
    {
        if (str.length() <= 2 && str.substring(0,1).equals(str.substring(str.length()-1,str.length())))
            return true;
        if(str.substring(0,1).equals(str.substring(str.length()-1,str.length())))
            return isPalindrome(str.substring(1,str.length()-1));
        else
            return false;
    }
    public boolean isAlphabetical(String str){         
        if(str.length() == 1){
            return true;
        }
        if(str.compareTo(str.substring(1,2))<0)
        return isAlphabetical(str.substring(1));
        else
        return false;
    }
}
