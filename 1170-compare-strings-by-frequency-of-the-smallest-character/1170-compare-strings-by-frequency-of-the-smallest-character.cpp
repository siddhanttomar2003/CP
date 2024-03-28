class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>q;
        for(int i=0;i<queries.size();i++){
            vector<int>a(26,0);
            for(int j=0;j<queries[i].length();j++){
                 a[queries[i][j]-'a']++;
            }
            for(int k=0;k<26;k++){
                if(a[k]>0){
                 q.push_back(a[k]);
                 break;
                }
            }

        }
        vector<int>w;
         for(int i=0;i<words.size();i++){
            vector<int>a(26,0);
            for(int j=0;j<words[i].length();j++){
                 a[words[i][j]-'a']++;
            }
            for(int k=0;k<26;k++){
                if(a[k]>0){
                 w.push_back(a[k]);
                 break;
                }
            }
        }
        sort(w.begin(),w.end());
        vector<int>ans;
        for(int i=0;i<q.size();i++){
            int a=q[i];
            int s=0;
            int e=w.size()-1;
            int ansi=0;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(w[mid]<=a)s=mid+1;
                else {
                e=mid-1;
                ansi=w.size()-mid;
                }
            }
            ans.push_back(ansi);
            
        }
        return ans;


    }
};