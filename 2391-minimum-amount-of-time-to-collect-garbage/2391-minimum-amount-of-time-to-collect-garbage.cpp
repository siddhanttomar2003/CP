class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> prefix(travel.size());
        prefix[0]=travel[0];
        for(int i=1;i<travel.size();i++)
        {
            prefix[i]=prefix[i-1]+travel[i];
        }
        for(auto itr:prefix)
        {
            cout<<itr<<" ";
        }
        int ans=0,g=0,p=0,m=0;
        for(int i=0;i<garbage.size();i++)
        {
            string curr=garbage[i];
            for(int j=0;j<curr.length();j++)
            {
                if(curr[j]=='G') g=i;
                if(curr[j]=='P') p=i;
                if(curr[j]=='M') m=i;
            }
            ans=ans+curr.length();
        }
        if(g>=1)
        {
            ans=ans+prefix[g-1];
        }
         if(p>=1)
        {
            ans=ans+prefix[p-1];
        }
         if(m>=1)
        {
            ans=ans+prefix[m-1];
        }
        return ans;
        return 0;
    }
};