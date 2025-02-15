class Solution {
public:
    bool check(double line,vector<vector<int>>&squares){
        double low=0,up=0;
        for(auto &it:squares){
            double x=it[0];
            double y=it[1];
            double len=it[2];
            if(y+len<=line){
                low+=(len*len);
            }
            else if(y>=line){
                up+=(len*len);
            }
            else {
                double ly=line-y;
                double uy=y+len-line;
                up+=((uy*len));
                low+=((ly*len));
            }
        }
        return low<up;
        
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low=0;
        double high=2e9;
        
        double ans=high;
        while(high-low>1e-5){
            double mid=(low+high)/(2.0);
            if(check(mid,squares)){
                low=mid;
            }
            else {
                high=mid;
                ans=mid;
            }
        }
        return ans;
    }
};