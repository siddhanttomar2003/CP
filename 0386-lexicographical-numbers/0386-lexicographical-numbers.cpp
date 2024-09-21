class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>temp;
        for(int i=1;i<=n;i++){
          temp.push_back(to_string(i));
        }
        sort(temp.begin(),temp.end(),[](string a, string b){
            int k=a.size();int m=b.size();
            for(int i=0;i<min(k,m);i++){
               if(a[i]<b[i])return true;
               else if(b[i]<a[i])return false;
            }
         if(k>m)return false;
          return true;
        }
        );
        vector<int>ans;
        for(int i=0;i<n;i++){
             ans.push_back(stoi(temp[i]));
        }
        return ans;
    }
};