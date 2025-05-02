class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int>l(n),r(n);
        int curr_l=-1,curr_r=-1;
        for(int i=0;i<dominoes.size();i++){
            l[i]=curr_l;
            r[n-i-1]=curr_r;
            if(dominoes[i]=='L')curr_l=-1;
            else if(dominoes[i]=='R')curr_l=i;
            if(dominoes[n-i-1]=='L')curr_r=n-i-1;
            else if(dominoes[n-i-1]=='R')curr_r=-1;
        }
        for(int i=0;i<n;i++){
            if(dominoes[i]=='.'){
               if(r[i]==-1 && l[i]==-1)continue;
               else if(l[i]==-1 && r[i]!=-1)dominoes[i]='L';
               else if(l[i]!=-1 && r[i]==-1)dominoes[i]='R';
               else {
                 if(i-l[i]<r[i]-i)dominoes[i]='R';
                 else if(i-l[i]>r[i]-i)dominoes[i]='L';
               }
            }
            // cout<<l[i]<<" "<<r[i]<<endl;
        }
        return dominoes;
    }
};