class Solution {
public:
    vector<int> lexicalOrder(int n) {
       vector<int>temp;
       for(int i=1;i<=n;i++)temp.push_back(i);
       sort(temp.begin(),temp.end(),[](int a, int b){
            string f=to_string(a);
            string s=to_string(b);
            int size=min((int)f.size(),(int)s.size());
            for(int i=0;i<size;i++){
                if(f[i]<s[i])return true;
                else if(f[i]>s[i])return false;
            }
            if(f.size()<s.size())return true;
            return false;
       });
    return temp;
    }
};