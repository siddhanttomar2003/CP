class Solution {
public:
    bool check(int m, int op, vector<int>&segment){
        int count=0;
        for(int i=0;i<segment.size();i++){
            int curr=segment[i];
            if(curr<=m)continue;
            count+=(curr/(m+1));
        }
        if(count>op)return false;
        return true;
    }
    int minLength(string s, int numOps) {
       int n=s.size();
       vector<int>seg_size;
       for(int i=0;i<n;i++){
         int curr=1;
         while(i+1<n && s[i]==s[i+1]){
            curr++;i++;
         }
         seg_size.push_back(curr);
       }
       int i=1;int j=n;
       int ans=j;
       while(i<=j){
        int m=i+(j-i)/2;
        if(check(m,numOps,seg_size)){
            ans=m;
            j=m-1;
        }
        else i=m+1;
       }
       return ans;
    }
};