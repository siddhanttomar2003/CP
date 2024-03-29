class Solution {
public:
    bool check(vector<int> &v){
        bool ans=true;
        for(int i=0;i<3;i++){
            if(v[i]<1){
                ans=false;
                break;
            }
        }
        return ans;
    }
    int numberOfSubstrings(string s) {
        int count=0;
        int i=0;
        int j=0;
        vector<int>v(3,0);
        while(j<s.length()){
            v[s[j]-'a']++;
            if(!check(v)){
             j++;
            }
            else {
                while(check(v)){
                    count+=s.length()-j;
                    v[s[i]-'a']--;i++;
                }
                j++;
            }
        }
        return count;
    }
    
};