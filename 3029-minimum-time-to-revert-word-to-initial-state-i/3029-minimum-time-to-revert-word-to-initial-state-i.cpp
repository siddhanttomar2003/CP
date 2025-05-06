class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        // vector<int>lps(n);
        // int len=0;
        // int i=1;
        // lps[0]=0;
        // while(i<n){
        //     if(word[i]==word[len]){
        //         len++;
        //         lps[i]=len;
        //         i++;
        //     }
        //     else {
        //         if(len!=0){
        //             len=lps[len-1];
        //         }
        //         else {
        //             i++;
        //         }
        //     }
        // }
        int s=k;
        int count=1;
        while(true){
         int i=s;
         bool check=true;
         for(int j=0;j<n;j++){
            if( i<n && word[j]==word[i]){
                i++;
            }
            else break;
         }
         if(i==n)return count;
         count++;
         s+=k;
        }
        return 0;
        
    }
};