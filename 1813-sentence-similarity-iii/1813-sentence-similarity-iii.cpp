class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int f_pos= -1;
        int n=sentence1.size(); int m=sentence2.size();
        for(int i=0;i<min(n,m);i++){
            if(sentence1[i]!=sentence2[i] ){
                if(i>0 && sentence1[i-1]!=' ')return false;
                if(f_pos == -1)f_pos=i;
                break;
            }
        }
        if(f_pos == -1)return true;
        // find first in second
        cout<<f_pos<<endl;
        int rem_size1=n-f_pos;
        int rem_size2=m-f_pos;
        if(rem_size2>=rem_size1){
            string fir=sentence1.substr(f_pos,rem_size1);
            string sec="";
             int i=m-1;
             int c=0;
             while(c<rem_size1){
                sec+=sentence2[i];i--;c++;
             }
             reverse(sec.begin(),sec.end());

            if(fir==sec)return true;
        }
        // find second in first
        if(rem_size1>=rem_size2){
          string sec=sentence2.substr(f_pos,rem_size2);
          string fir="";
            int i=n-1;
             int c=0;
             while(c<rem_size2){
                fir+=sentence1[i];i--;c++;
             }
             reverse(fir.begin(),fir.end());
            if(fir==sec)return true;
        }
        return false;
    }
};