class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>l_s,n_s;
        vector<int>last(n),next(n);
        last[0]=-1;
        next[n-1]=n;
        l_s.push(0),n_s.push(n-1);
        for(int i=1;i<n;i++){
            while(!l_s.empty() && heights[i]<=heights[l_s.top()]){
                l_s.pop();
            }
            if(l_s.size()==0){
                last[i]=-1;
            }
            else last[i]=l_s.top();
            l_s.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<last[i]<<" ";
        // }
        // cout<<endl;
        for(int i=n-2;i>=0;i--){
            while(!n_s.empty() && heights[i]<=heights[n_s.top()]){
                n_s.pop();
            }
            if(n_s.size()==0){
                next[i]=n;
            }
            else next[i]=n_s.top();
            n_s.push(i);
        }
        // for(int i=0;i<n;i++)cout<<next[i]<<" ";
        // cout<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
            int left_len=i-last[i];
            int right_len=next[i]-i;
            int curr_len=left_len+right_len-1;
            ans=max(ans,curr_len*heights[i]);
        }
        return ans;
    }
};
