class Solution {
public:
    int secondHighest(string s) {
        vector<int>v;
        string k=s;
        char c;
        for(int i=0;i<k.size();i++){
         if((int)k[i]>=48 && (int)k[i]<=57){
             v.push_back(s[i]-48);
         }
        }
         int slargest=-1;
        if(v.size()!=0){
        int largest=v[0];
       
        int count=0;
        for(int i=1;i<v.size();i++){
            if(v[i]>largest){
                slargest=largest;
                largest=v[i];
            }
            else if(v[i]<largest&&v[i]>slargest){
                slargest=v[i];
            }
        }
        }
        return slargest;
        
    }
};