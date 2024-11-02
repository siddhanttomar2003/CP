class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size();
        char last=sentence[n-1];

        for(int i=0;i<n;i++){
            if(i==0 || sentence[i-1]==' '){
                if(sentence[i]!=last){
                    return false;
                }
            }
            if(i+1<n && sentence[i+1]==' ')last=sentence[i];
        }
        return true;
    }
};