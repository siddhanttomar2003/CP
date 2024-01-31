class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>s;
        vector<int>ans(temperatures.size(),0);
        s.push(temperatures.size()-1);
        for(int i=temperatures.size()-1;i>=0;i--){
            while(!s.empty()){
                if(temperatures[i]<temperatures[s.top()]){
                    ans[i]=s.top()-i;
                    break;
                }
                else{
                    s.pop();
                }
            }
            s.push(i);
        }
        return ans;
    }
};