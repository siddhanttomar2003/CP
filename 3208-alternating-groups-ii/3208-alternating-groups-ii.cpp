class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int>v=colors;
        int n=colors.size();
        for(int i=0;i<n;i++){
            v.push_back(colors[i]);
        }
        queue<int>q;
        int i=0,j=1;
        for(j;j<k;j++){
         if(colors[j]==colors[j-1])q.push(j-1);
        }
        int ans=0;
        if(q.size()==0)ans++;
        j--;
        while(i<n && j<2*n){
            if(q.size()>0){
                if(q.front()==i){
                    q.pop();
                }
            }
            i++;
            if(v[j]==v[j+1]){
                q.push(j);
            }
            j++;
            if(q.size()==0 && i<n)ans++;
        }
        return ans;
    }
};