class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        queue<int> q;
        q.push(0);
        int n = s.size();
        int farthest = 0; 
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            int start = max(curr + minJump, farthest + 1);
            int end = min(curr + maxJump, n - 1);
            for (int i = start; i <= end; i++) {
                if (s[i] == '0') {
                    if (i == n - 1) return true; 
                    q.push(i);
                }
            }
            farthest = max(farthest, end);
        }
        return false;
    }
};