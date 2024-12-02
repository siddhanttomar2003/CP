class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string>temp;
        int n=sentence.size();
        for(int i=0;i<n;i++){
            string curr="";
            while(i<n && sentence[i]!=' '){
                curr+=sentence[i];
                i++;
            }
            temp.push_back(curr);
        }
        int m=searchWord.size();
        for(int i=0;i<temp.size();i++){
            int j=0;
            int s=temp[i].size();
            int k=0;
            while(k<s && j<m){
                if(searchWord[j]==temp[i][k]){
                    k++;j++;
                }
                else break;
            }
            if(j==m)return i+1;
        }
        return -1;

    }
};