class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // trying both ways fixing the first num;
        int n=derived.size();
        vector<int>try1(n,0),try2(n,0);
        try2[0]=1;
        try1[0]=0;
        for(int i=0;i<n-1;i++){
              try1[i+1]=try1[i]^derived[i];
              try2[i+1]=try2[i]^derived[i];
        }
        if(derived[n-1]==try1[0]^try1[n-1] || derived[n-1]==try2[0] ^ try2[n-1])return true;
        return false;
    }
};