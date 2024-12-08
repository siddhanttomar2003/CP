class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>freq(101,0);
        sort(logs.begin(),logs.end());
        for(int i=0;i<logs.size();i++){
            int start=logs[i][0];
            int end=logs[i][1];
            freq[start-1950]+=1;
            freq[end-1950]-=1;
        }
        for(int i=1;i<101;i++){
            freq[i]+=freq[i-1];
        }
        int maxi=0;
        int year=1950;
        for(int i=0;i<101;i++){
            if(freq[i]>maxi){
                maxi=freq[i];
                year=i+1950;
            }
        }
        return year;
    }
};