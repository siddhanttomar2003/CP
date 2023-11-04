class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int count=-1;
        for(int i=0;i<left.size();i++){
            count=max(count,left[i]);
        }
        for(int i=0;i<right.size();i++){
            count=max(count,abs(n-right[i]));
        }
        return count;
    }
};