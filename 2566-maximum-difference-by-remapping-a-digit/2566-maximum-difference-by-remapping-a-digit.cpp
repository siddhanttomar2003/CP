class Solution {
public:
    int minMaxDifference(int num) {
        string a=to_string(num);
        int mini=1e9;
        int maxi=-1e9;
        for(int i=0;i<a.size();i++){
            for(char j='0';j<='9';j++){
                string temp=a;
                 for(int k=0;k<a.size();k++){
                     if(a[i]==a[k]){
                        temp[k]=j;
                     }
                 }
                 int n=stoi(temp);
                   mini=min(mini,n);
                   maxi=max(maxi,n);
            }
        }
        return maxi-mini;
    }
};