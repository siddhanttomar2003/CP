class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int>diff;
        for(int i=0;i<n;i++){
            diff.push_back(gas[i]-cost[i]);
        }
        vector<int>temp=diff;
        temp.insert(temp.end(),diff.begin(),diff.end());
        int sum=0;
        int start=0;
        int fix=0;
        int maxi=0;
        for(int i=0;i<temp.size();i++){
            sum+=temp[i];
            if(sum<0){
                sum=0;
                start=i+1;
            }
            if(sum>maxi){
                maxi=sum;
                fix=start;
            }
        }
        int times=n;
        int ind=fix;
        int delta=0;
        while(times--){
          delta+=(gas[ind]-cost[ind]);
          ind=(ind+1)%n;
          if(delta<0)return -1;
        }
        return fix;
    }
};
