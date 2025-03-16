class Solution {
public:
    int totalNumbers(vector<int>& digits) {
     set<int>st;
     int n=digits.size();
     for(int i=0;i<n;i++){
       if(digits[i]%2==0){
       for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
           if(i!=j && i!=k && j!=k && digits[j]!=0)
           st.insert(digits[j]*100+digits[k]*10+digits[i]);
        }
       }
       }
     }
     return st.size();

    }
};