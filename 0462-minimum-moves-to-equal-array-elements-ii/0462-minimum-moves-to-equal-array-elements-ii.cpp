class Solution {
public:
    int minMoves2(vector<int>& nums) {
       
        int moves=0;
        if(nums.size()%2!=0){
          nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());
           
           for(int i=0;i<nums.size();i++){
               moves+=abs(nums[i]-nums[nums.size()/2]);
           }
        }
          else{
              
              int moves1=0;
              int moves2=0;
              nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());
              nth_element(nums.begin(),nums.begin()+nums.size()/2-1,nums.end());
              for(int i=0;i<nums.size();i++){
                  moves1+=abs(nums[i]-nums[nums.size()/2]);
                  moves2+=abs(nums[i]-nums[nums.size()/2-1]);
              }
              moves=min(moves1,moves2);
          }
   return moves;

    }
};