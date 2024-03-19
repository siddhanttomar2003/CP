class Solution {
public:
     int check(vector<int> &weights,int &mid,int &days){
        int count=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>mid){
                sum=weights[i];count++;
            }
            else sum+=weights[i];
        }
        if(count>days)return -1;
        else return 1;
     }
    int shipWithinDays(vector<int>& weights, int days) {
       int min_weight=0;
       for(int i=0;i<weights.size();i++){
        min_weight+=weights[i];
       } 
       int i=*max_element(weights.begin(),weights.end());
       int e=min_weight;
       while(i<=e){
        int mid=i+(e-i)/2;
        int f_ans=check(weights,mid,days);
        if(f_ans==1){
            min_weight=mid;
            e=mid-1;
        }
        else i=mid+1;
       }
       return min_weight;
    }
};