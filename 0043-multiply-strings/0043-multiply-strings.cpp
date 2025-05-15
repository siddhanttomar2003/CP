class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1<num2)swap(num1,num2);
        int n=num1.size(),m=num2.size();
        vector<vector<int>>mat(m,vector<int>(n+m+1,0));
        for(int j=m-1;j>=0;j--){
            int curr_i=n+m-(m-1-(j));
            int carry=0;
            int a=num2[j]-48;
            for(int i=n-1;i>=0;i--){
                 int b=num1[i]-48;
                 mat[j][curr_i]=(a*b+carry)%10;
                 carry=(a*b+carry)/10;
                 curr_i--;
            }
            if(carry)mat[j][curr_i]=carry;
        }
        vector<int>f_ans(n+m+1,0);
        int c=0;
        for(int i=n+m;i>=0;i--){
            int sum=0;
            for(int j=0;j<m;j++){
                sum+=mat[j][i];
            }
            f_ans[i]=(sum+c)%10;
            c=(sum+c)/10;
        }
        string ans="";
        int i=0;
        while(i<n+m+1 && f_ans[i]==0)i++;
        while(i<n+m+1){
            ans+=to_string(f_ans[i]);
            i++;
        }
        if(ans.size()==0)return "0";
        return ans;
    }
};
