class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x_tar=target[0],y_tar=target[1],z_tar=target[2];
        bool x=false,y=false,z=false;
        for(auto it:triplets){
            if(it[0]==x_tar){
                if(it[1]<=y_tar && it[2]<=z_tar)x=true;
            }
            if(it[1]==y_tar){
                if(it[0]<=x_tar && it[2]<=z_tar)y=true;
            }
            if(it[2]==z_tar){
                if(it[0]<=x_tar && it[1]<=y_tar)z=true;
            }
        }
        return x & y & z;

    }
};
