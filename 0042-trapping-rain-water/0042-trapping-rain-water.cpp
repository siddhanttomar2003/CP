class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left_max(n,0);
        vector<int>right_max(n,0);
          int maxil=height[0];
          int maxir=height[n-1];
        for(int i=0;i<height.size();i++){
            left_max[i]=maxil;
            maxil=max(maxil,height[i]);
            right_max[n-i-1]=maxir;
            maxir=max(maxir,height[n-i-1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int mini=min(left_max[i],right_max[i]);
            if(mini-height[i]>0)ans+=abs(height[i]-mini);
            // else the water is flowing throught one or both the ends
        }

        for(int i=0;i<height.size();i++){
            cout<<left_max[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<height.size();i++){
            cout<<right_max[i]<<" ";
        }
        cout<<endl;
        return ans;

    }
};