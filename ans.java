import java.util.ArrayList;
import java.util.*;
class ans{
    public static void main(String []args){
        ArrayList<Integer> temp=new ArrayList<Integer>();
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
           int a=sc.nextInt();
           temp.add(a);
        }
       for(int i=1;i<n;i++){
        int curr=i;
        int pos=i-1;
        while( pos>0 && temp.get(curr)<temp.get(pos)){
        int t=temp.get(curr);
        temp.set(curr,temp.get(pos));
        curr--;
        temp.set(pos,t);
               pos--;
        }
       
       }
    }
}

