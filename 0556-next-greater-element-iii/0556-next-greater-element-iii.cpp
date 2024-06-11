class Solution {
public:
    int nextGreaterElement(int n) {
        string temp=to_string(n);
        int i=temp.size()-1;
        while(i>=1 && temp[i]<temp[i-1])i--;
        if(i==0)return -1;
          int j=temp.size()-1;
          while(temp[j]<temp[i-1]){
            j--;
          }
          swap(temp[j],temp[i-1]);
          sort(temp.begin()+i,temp.end());
          long long ansi=stoll(temp);
          if(ansi>INT_MAX|| (int)ansi==n)return -1;
           return (int)ansi;

        
    }
};