class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_set<string> sup(supplies.begin(), supplies.end());
        int n = recipes.size();
        unordered_set<string> ans;
        vector<int> vis(n, 0);
        for(int k=0;k<n;k++){
        for (int i = 0; i < n; i++) {
            if(!vis[i]){
            bool check = true;
            for (auto& it : ingredients[i]) {
                if (sup.find(it) == sup.end())
                    check = false;
            }
            if (check) {
                ans.insert(recipes[i]);
                sup.insert(recipes[i]);
                vis[i] = 1;
            }
            }
        }
        }
        vector<string>f_ans;
        for(auto &it:ans)f_ans.push_back(it);
        return f_ans;
    }
};