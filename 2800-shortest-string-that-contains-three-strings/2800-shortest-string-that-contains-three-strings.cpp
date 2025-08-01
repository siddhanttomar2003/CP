class Solution {
public:
    string play(string a, string b, string c){
        int maxi1 = 0;
            for(int j = 0; j < a.size(); j++){
                int k = 0; int l = j;
                int count = 0;
                while(k < b.size() && l < a.size() && a[l] == b[k]){
                    count++;
                    k++;l++;
                }
                if(l == a.size() || k == b.size())
                maxi1 = max(maxi1, count);
            }
       string ans = a;
        for(int j = maxi1; j < b.size(); j++){
            ans += b[j];
        }
        int maxi2 = 0;
        for(int j = 0; j < ans.size(); j++){
                int k = 0; int l = j;
                int count = 0;
                while(k < c.size() && l < ans.size() && ans[l] == c[k]){
                    count++;
                    k++;l++;
                }
               if(l == ans.size() || k == c.size())
                maxi2 = max(maxi2, count);
            }
        for(int j = maxi2; j < c.size(); j++)ans += c[j];
        // cout << maxi1 << " " << maxi2 << endl;
        return ans;
    }
    string minimumString(string a, string b, string c) {
        string ans = "";
        // int n1 = a.size(), n2 = b.size(), n3 = c.size();
        string f1 = play(a, b, c);
        string f2 = play(a, c, b);
        string f3 = play(b, a, c);
        string f4 = play(b, c, a);
        string f5 = play(c, a, b);
        string f6 = play(c, b, a);
        ans = f1;
        cout << f1 << endl;
            if(f2.size() < ans .size() || ans.size() == f2.size() && f2 < ans)
            ans = f2;
        
            if(f3.size() < ans .size() || ans.size() == f3.size() && f3 < ans)
            ans = f3;
        
             if(f4.size() < ans .size() || ans.size() == f4.size() && f4 < ans)
            ans = f4;
       
             if(f5.size() < ans .size() || ans.size() == f5.size() && f5 < ans)
            ans = f5;
        
             if(f6.size() < ans .size() || ans.size() == f6.size() && f6 < ans)
            ans = f6;
        
        return ans;
    }
};