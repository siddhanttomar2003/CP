typedef long long ll;
class Solution {
public:
    void merge(vector<int>&nums, int i, int mid, int j, int &c){
        int s1 = i;
        int s2 = mid + 1;
        while(s1 <= mid && s2 <= j){
            if(nums[s1] <= 2 * 1ll * nums[s2]){
                s1++;
            }
            else {
                c += mid - s1 + 1;
                s2++;
            }
        }
        s1 = i;
        s2 = mid + 1;
        vector<int>temp;
        while(s1 <= mid && s2 <= j){
            if(nums[s1] <= nums[s2]){
                temp.push_back(nums[s1]);
                s1++;
            }
            else {
                temp.push_back(nums[s2]);
                s2++;
            }
        }
        while(s1 <= mid){
            temp.push_back(nums[s1]);
            s1++;
        }
        while(s2 <= j){
            temp.push_back(nums[s2]);
            s2++;
        }

        for(int k = 0 ; k < temp.size() ; k++){
            nums[i] = temp[k];
            i++;
        }

    }
    void merge_sort(vector<int>&nums, int i, int j, int &c){
        if(j <= i)return;
        int mid = (i + j) / 2;
        merge_sort(nums, i , mid, c);
        merge_sort(nums, mid + 1, j, c);
        merge(nums, i , mid , j, c);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        merge_sort(nums, 0 , n-1, count);
        return count;
    }
};