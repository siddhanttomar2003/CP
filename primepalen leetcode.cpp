class Solution {
public:
       bool isPrime(int n){  if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;}
      bool checkpalendrome(int z){
                 string s=to_string(z);
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
  
}
    int primePalindrome(int n) {
          int i=n;
          int ans=INT_MIN;
        int count=0;
        
         if(n>=9989900)return 100030001;
            while(count<1){
        if(isPrime(i)&&checkpalendrome(i)){      
            count++;   
            ans=i;       
        }
        i++;   
    }
    return ans;
    
    }
};