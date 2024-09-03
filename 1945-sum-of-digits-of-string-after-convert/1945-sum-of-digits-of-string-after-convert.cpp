class Solution {
public:
    int getLucky(string s, int k) {
        // int ans=0;
        string temp="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            int add=s[i]-'a'+1;
            string con=to_string(add);
            temp+=con;
        }
        int ans=0;
        while(k--){
          int curr=0;
          for(int i=0;i<temp.size();i++){
            curr+=(temp[i]-48);
          }
          if(curr!=0)ans=curr;
          temp=to_string(curr);
        }
        return ans;
        

    }
};