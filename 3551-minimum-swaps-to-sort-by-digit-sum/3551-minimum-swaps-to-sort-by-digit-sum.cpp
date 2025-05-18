class Solution {
public:
    int find_sum(int a){
        int sum=0;
        while(a>0){
            sum+=a%10;
            a/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        vector<vector<int>>temp;
        vector<pair<int,int>>arr;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            nums[i]=find_sum(nums[i]);
            temp.push_back({nums[i],num,i});
        }
        sort(temp.begin(),temp.end(),[](vector<int>&a, vector<int>&b){
            if(a[0]!=b[0])return a[0]<b[0];
            return a[1]<b[1];
        });
        int c=0;
        vector<int>ind;
        for(int i=0;i<nums.size();i++)ind.push_back(temp[i][2]);
        for(int i=0;i<nums.size();i++){
            if(i!=ind[i]){
                c++;
                swap(ind[i],ind[ind[i]]);
                i--;
            }
        }
        return c;

        
        
    }
};