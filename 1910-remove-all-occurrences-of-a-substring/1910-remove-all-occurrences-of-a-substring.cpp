class Solution {
public:
    string removeOccurrences(string s, string part) {
        string curr=s;
        int pos=s.find(part);
        int size=part.size();
        while(pos!=string :: npos){
            string temp="";
           for(int i=0;i<pos;i++){
            temp+=curr[i];
           }
           for(int i=pos+size;i<curr.size();i++){
            temp+=curr[i];
           }
           curr=temp;
           pos=curr.find(part);
        }
        return curr;
    }
};