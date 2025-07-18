#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long> A_sum(3 * n + 1, 0);
        vector<long long> B_sum(3 * n + 1, 0);
        
        priority_queue<int> maxHeap;
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            maxHeap.push(nums[j]);
        }
        A_sum[n] = sum;
        
        for (int i = n + 1; i <= 2 * n; i++) {
            int x = nums[i - 1];
            if (x < maxHeap.top()) {
                sum = sum - maxHeap.top() + x;
                maxHeap.pop();
                maxHeap.push(x);
            }
            A_sum[i] = sum;
        }
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;
        for (int j = 2 * n; j < 3 * n; j++) {
            sum += nums[j];
            minHeap.push(nums[j]);
        }
        B_sum[2 * n] = sum;
        
        for (int i = 2 * n - 1; i >= n; i--) {
            int x = nums[i];
            if (x > minHeap.top()) {
                sum = sum - minHeap.top() + x;
                minHeap.pop();
                minHeap.push(x);
            }
            B_sum[i] = sum;
        }
        
        long long ans = LLONG_MAX;
        for (int i = n; i <= 2 * n; i++) {
            ans = min(ans, A_sum[i] - B_sum[i]);
        }
        return ans;
    }
};