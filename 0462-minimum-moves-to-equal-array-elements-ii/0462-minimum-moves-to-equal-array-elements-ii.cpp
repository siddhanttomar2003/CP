class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=0;
        int mid1=0;
        int moves=0;
        if(nums.size()%2!=0){
           mid=nums[nums.size()/2];
           
           for(int i=0;i<nums.size();i++){
               moves+=abs(nums[i]-mid);
           }
        }
          else{
              mid=nums[nums.size()/2];
              mid1=nums[nums.size()/2-1];
              int moves1=0;
              int moves2=0;
              for(int i=0;i<nums.size();i++){
                  moves1+=abs(nums[i]-mid);
                  moves2+=abs(nums[i]-mid1);
              }
              moves=min(moves1,moves2);
          }
   return moves;

    }
};