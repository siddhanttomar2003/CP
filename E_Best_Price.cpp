#include <bits/stdc++.h>
using namespace std;

int maxMutatedViruses(int N, vector<int>& c) {
    // User will implement this function
    map<int,int>mp;
    for(int i=0;i<N;i++){
        mp[c[i]]++;
    }
    int count=0;
    vector<int>temp;
    for(auto it:mp){
        temp.push_back(it.first);
    }
    if(temp.size()>2){
    for(int i=0;i<temp.size()-2;i++){
       if(temp[i]+1==temp[i+1] && temp[i]+2==temp[i+2]){
        int mini=min({mp[temp[i]],mp[temp[i+1]],mp[temp[i+2]]});
        count+=mini;
        mp[temp[i]]-=mini;
        if(mp[temp[i]]==0)mp.erase(temp[i]);
        mp[temp[i+1]]-=mini;
        if(mp[temp[i+1]]==0)mp.erase(temp[i+1]);
        mp[temp[i+2]]-=mini;
        if(mp[temp[i+2]]==0)mp.erase(temp[i+2]);
       }
    }
    }
    for(auto it:mp){
        count+=(it.second/3);
    }
    return count;
    

}

int main() {
    int V;
    cin >> V;
    vector<int> contamination_levels(V);
    for (int i = 0; i < V; i++) {
        cin >> contamination_levels[i];
    }
    int result = maxMutatedViruses(V, contamination_levels);
    cout << result << endl;
    return 0;
}