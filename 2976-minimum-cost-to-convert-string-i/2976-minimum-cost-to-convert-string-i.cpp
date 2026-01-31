class Solution {
public:
    typedef long long ll;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>>dis(26, vector<ll>(26, 1e18));
        for(int i = 0; i < original.size(); i++){
            int idx1 = original[i] - 97;
            int idx2 = changed[i] - 97;
            dis[idx1][idx2] = min(dis[idx1][idx2], (ll)cost[i]);
        }
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                for(int k = 0; k < 26; k++){
                    if(dis[j][i] + dis[i][k] < dis[j][k]){
                        dis[j][k] = dis[j][i] + dis[i][k];
                    }
                }
            }
        }
        ll ans = 0;
        for(int i = 0; i < source.size(); i++){
            if(source[i] != target[i]){
                int idx1 = source[i] - 97, idx2 = target[i] - 97;
                // cout << dis[idx1][idx2] << " ";
                if(dis[idx1][idx2] == 1e18)return -1;
                ans += dis[idx1][idx2];
            }
        }
        return ans;
    }
};