class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int majority_1 = -1, majority_2 = -1;
        int curr_freq1 = -1, curr_freq2 = -1;
        int n=arr.size();
        for (int i = 0; i < n; i++) {
            if (majority_1 == -1) { 
                majority_1 = arr[i];
                curr_freq1 = 1;
            }
            else if (majority_1 == arr[i]) {
                curr_freq1++;
            }
            else if (majority_2 == -1) {
                majority_2 = arr[i];
                curr_freq2 = 1;
            }  else if (majority_2 == arr[i]) {
                curr_freq2++;
            } else {
                curr_freq1--;
                curr_freq2--;
                if (curr_freq1 < 0 && curr_freq2 < 0) {
                    curr_freq1 = -1;
                    curr_freq2 = -1;
                    majority_1 = arr[i];
                    majority_2 = -1;
                } else if (curr_freq1 < 0) {
                    majority_1=arr[i];
                    curr_freq1=1;

                } else if (curr_freq2 < 0) {
                    majority_2=arr[i];
                    curr_freq2=1;
                }
            }
        }
        int count1=0,count2=0;
        for(int i=0 ;i<n; i++){
            if(arr[i]==majority_1)count1++;
            else if(arr[i]==majority_2)count2++;
        }
        vector<int>ans;
        if(count1>n/3)ans.push_back(majority_1);
        if(count2>n/3)ans.push_back(majority_2);
        return ans;
    }
};