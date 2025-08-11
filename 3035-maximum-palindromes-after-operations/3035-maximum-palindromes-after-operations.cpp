class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int>sz;
        for(auto it : words){
            sz.push_back((int)it.size());
        }
        sort(sz.begin(), sz.end());
        vector<int>freq(26, 0);
        for(auto it : words){
            for(auto it2 : it)freq[it2 - 97]++;
        }
        int count = 0;
        for(auto it : sz){
            int req = it;
            if(req & 1)req--;
            for(auto & it2 : freq){
                 int avail = it2;
                 if(it2 & 1)avail--;
                 if(avail <= req){
                    it2 -= avail;
                    req -= avail;
                 }
                 else {
                    it2 -= req;
                    req = 0;
                 }
                 if(req == 0){
                    count++;
                    break;
                 }
            }
        }
        return count;
    }
};