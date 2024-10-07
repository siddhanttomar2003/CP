class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string>words1;
        vector<string>words2;
        int n=sentence1.size();
        int m=sentence2.size();
        for(int i=0;i<n;i++){
            string temp="";
            while(i<n && sentence1[i]!=' '){
                 temp+=sentence1[i];
                 i++;
            }
            words1.push_back(temp);
        }
           for(int i=0;i<m;i++){
            string temp="";
            while(i<m && sentence2[i]!=' '){
                 temp+=sentence2[i];
                 i++;
            }
            words2.push_back(temp);
        }
        int n1=words1.size(); int n2=words2.size();
        if(n2<n1)return areSentencesSimilar(sentence2,sentence1);
        int i=0;
        while(i<words1.size() && words1[i]==words2[i]){
            i++;
        }
        int rem=words1.size()-i;
        if(rem==0)return true;
      int j=n2-rem; 
        if(j<=i)return false;
        while(j<n2 && i<n1 && words1[i]==words2[j]){
            i++;j++;
        }
        return j==n2;

    }
};