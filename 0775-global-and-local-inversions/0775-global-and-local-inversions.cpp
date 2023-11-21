
class Solution {
public:
         long long count=0;
         vector<int> temp;
      void merge(vector<int>&a,int low,int high){
          temp.clear();
        int mid=(low+high)/2;
        int i=low;
        int j=mid+1;
        while(i<=mid&&j<=high){
            if(a[i]<=a[j]){
                temp.push_back(a[i]);
                i++;
            }
            else {
                count+=(mid-i+1);
                temp.push_back(a[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(a[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(a[j]);
            j++;
        }
        for(int i=low;i<=high;i++){
            a[i]=temp[i-low];
        }
        
      }
      void merge_sort(vector<int>&a,int low,int high){
          if(low>=high)return ;
       int mid=(low+high)/2;
       merge_sort(a,low,mid);
       merge_sort(a,mid+1,high);
       merge(a,low,high);
       
      }
     long long global_inversion(vector<int>&nums){
      int low=0;
      int high=nums.size()-1;
      merge_sort(nums,low,high);
      return count;
     }

     int local_inversion(vector<int>&a){
         int n=a.size();
         int c=0;
         for(int i=0;i<n-1;i++){
           if(a[i]>a[i+1]){
               c++;
           }
         }
          return c;
     }
    bool isIdealPermutation(vector<int>&nums) {
        // use merge sort to find global inversion in nlogn 
        //  local inversion can directly be found in n
        return local_inversion(nums)==global_inversion(nums);

    }
};