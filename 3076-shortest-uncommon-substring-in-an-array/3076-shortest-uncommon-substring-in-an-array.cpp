class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        map<string,int>mp;
        for(int i=0;i<arr.size();i++){
            string t=arr[i];
            for(int j=0;j<t.size();j++){
                string temp="";
                for(int k=j;k<t.size();k++){
                    temp+=t[k];
                    mp[temp]++;
                }
            }
        }
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        string maxi="zzzzzzzzzzzzzzzzzzzzz";
        vector<string>f_ans;
        for(int i=0;i<arr.size();i++){
            string temp=arr[i];
            map<string,int>mp_temp;
            for(int j=0;j<temp.size();j++){
                string em="";
                for(int k=j;k<temp.size();k++){
                    em+=temp[k];
                    mp_temp[em]++;
                }
            }
            string ans=maxi;
            for(auto it:mp_temp){
                 string test=it.first;
                 int times=it.second;
                 mp[test]-=times;
                 if(mp[test]==0){
                    if(test.size()<ans.size()){
                        ans=test;
                    }
                    else if(test.size()==ans.size()){
                        ans=min(ans,test);
                    }
                 }
                 mp[test]+=times;
            }
            if(ans==maxi)ans="";
            f_ans.push_back(ans);

        }
        return f_ans;
    }
};