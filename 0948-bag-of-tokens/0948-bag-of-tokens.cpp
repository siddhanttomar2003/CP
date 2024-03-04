class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        int maxi_score=0;
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=tokens.size()-1;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                score++;
                i++;
            }
            else{
                if(score>0){
                maxi_score=max(maxi_score,score);
                score--;
                power+=tokens[j];
                j--;
                }
                else break;
            }
        }
        maxi_score=max(maxi_score,score);
        return maxi_score;
    }
};