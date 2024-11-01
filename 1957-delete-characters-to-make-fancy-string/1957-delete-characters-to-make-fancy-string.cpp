class Solution {
public:
    string makeFancyString(string s) {
        string temp="";
        int n=s.size();
        for(int i=0;i<n;i++){
            int curr_freq=1;
            char c=s[i];
            while(i+1<n && s[i]==s[i+1]){
                curr_freq++;i++;
            }
            if(curr_freq>=2){
               temp+=c;temp+=c;
            }
            else {
              temp+=c;
            }
        }
        return temp;
    }
};