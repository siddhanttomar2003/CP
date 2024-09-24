class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string,int>mp;
        for(int i=0;i<arr1.size();i++){
            string curr=to_string(arr1[i]);
            string temp="";
            for(int j=0;j<curr.size();j++){
                temp+=curr[j];
                mp[temp]++;
            }
        }
        int len=0;
        for(int i=0;i<arr2.size();i++){
            string curr=to_string(arr2[i]);
            string temp="";
            for(int j=0;j<curr.size();j++){
                temp+=curr[j];
                if(mp.find(temp)!=mp.end()){
                    int s=temp.size();
                    len=max(len,s);
                }
            }
        }
        return len;
    }
};