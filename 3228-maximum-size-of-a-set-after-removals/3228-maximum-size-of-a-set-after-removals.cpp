class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        set<int>st1;set<int>st2;
        for(int i=0;i<n;i++){st1.insert(nums1[i]);st2.insert(nums2[i]);}

       for(auto it:st1)cout<<it<<" ";
       cout<<endl;
       for(auto it:st2)cout<<it<<" ";
       cout<<endl;


        if(st1.size()>n/2){ 
                for (auto it = st1.begin(); it != st1.end(); ) {
        if (st2.find(*it)!=st2.end()) {
            it = st1.erase(it);
        } else {
            ++it;  
        }
        if(st1.size()==n/2)break;
    }
                  if(st1.size()>n/2){
                    while(st1.size()>n/2)st1.erase(st1.begin());
                }
        }
        if(st2.size()>n/2){
                for (auto it = st2.begin(); it != st2.end(); ) {
        if (st1.find(*it)!=st1.end()) {
            it = st2.erase(it);
        } else {
            ++it;  
        }
        if(st2.size()==n/2)break;
    }
            if(st2.size()>n/2){
                while(st2.size()>n/2)st2.erase(st2.begin());
            }
        }
        set<int>f_ans;
        for(auto it:st1)f_ans.insert(it);
        for(auto it:st2)f_ans.insert(it);
        return f_ans.size();



    }
};