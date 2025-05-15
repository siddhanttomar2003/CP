class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1<num2)swap(num1,num2);
        int n=num1.size(),m=num2.size();
        vector<int>mat(n+m+1,0);
        for(int j=m-1;j>=0;j--){
            int curr_i=n+m-(m-1-(j));
            int carry=0;
            int a=num2[j]-48;
            for(int i=n-1;i>=0;i--){
                 int b=num1[i]-48;
                 mat[curr_i]+=(a*b+carry);
                 carry=mat[curr_i]/10;
                 mat[curr_i]%=10;
                 curr_i--;
            }
            if(carry)mat[curr_i]=carry;
        }
        string ans="";
        int i=0;
        while(i<n+m+1 && mat[i]==0)i++;
        while(i<n+m+1){
            ans+=to_string(mat[i]);
            i++;
        }
        if(ans.size()==0)return "0";
        return ans;
    }
};
