class Solution {
public:
    void cal(vector<int>&ans, int n, string i){
        int num=stoi(i);
        if(num>n)return;
        ans.push_back(num);
        for(char c='0';c<='9';c++){
            cal(ans,n,i+c);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            string temp=to_string(i);
            cal(ans,n,temp);
        }
        return ans;
    }
};