class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n=s.size();
        for(int i=0;i<=n-k;i++){
            string temp=s.substr(i,k);
            set<char>st;
            for(int j=0;j<temp.size();j++){
                st.insert(temp[j]);
            }
            if(st.size()==1){
                char c=*st.begin();
                if(i-1>=0 && s[i-1]==c)continue;
                if(i+k<n && s[i+k]==c)continue;
                return true;
            }
        }
        return false;
    }
};