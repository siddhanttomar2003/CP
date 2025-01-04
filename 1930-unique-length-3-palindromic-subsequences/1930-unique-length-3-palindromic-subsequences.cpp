class Solution {
public:
    int countPalindromicSubsequence(string inputString) {
    //as it is asking for subsequence we have to keep in mind the order in which the
    //character are coming
    // we need to keep track of the first and last occurrence of each character
    // and then calculate the number of different elements between them
    vector<int>first_occur(26,INT_MAX);
    vector<int>last_occur(26,INT_MIN);
     for(int i=0;i<inputString.size();i++){
         first_occur[inputString[i]-'a']=min( first_occur[inputString[i]-'a'],i);
         last_occur[inputString[i]-'a']=max(last_occur[inputString[i]-'a'],i);

     }
     int count=0;
     for(int i=0;i<26;i++){
         if(first_occur[i]==INT_MAX||last_occur[i]==INT_MIN)continue;
         unordered_set<int>s;
         for(int j=first_occur[i]+1;j<last_occur[i];j++){
             s.insert(inputString[j]);//for no. of unique element
         }
         count+=s.size();
     }
    return count;
    }
};