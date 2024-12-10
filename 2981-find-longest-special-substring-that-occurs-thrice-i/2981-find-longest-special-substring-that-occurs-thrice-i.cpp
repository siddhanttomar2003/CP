class Solution {
public:
    int maximumLength(string s) {
        map<string,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
             string temp="";
            for(int j=i;j<n;j++){
               temp+=s[j];
               mp[temp]++;
            }
        }
        int len= -1;
        for(auto it:mp){
            cout<<it.first.size()<<" "<<it.second<<endl;
            int s=it.first.size();
            bool check=true;
            for(int i=1;i<s;i++){
                if(it.first[i]!=it.first[i-1])check=false;
            }
            if(it.second>=3 && s>len && check){
                len=s;
            }
        }
        return len;
    }
};