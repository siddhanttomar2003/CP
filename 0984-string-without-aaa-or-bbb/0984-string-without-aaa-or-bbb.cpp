class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        if(a>b){
            while(a>0&&b>0){
                if(a&1){
                    ans+='a';a-=1;
                }
                else{
                    ans+='a';ans+='a';a-=2;
                }
                if(b>a/2&&a!=0){
                    ans+='b'; ans+='b';b-=2;
                }
                else{
                    ans+='b';b-=1;
                }
            }
            while(a>0){ans+='a';a--;}
            while(b>0){ans+='b';b--;}
        }
        else{
              while(b>0&&a>0){
                if(b&1){
                    ans+='b';b-=1;
                }
                else{
                    ans+='b';ans+='b';b-=2;
                }
                if(a>b/2&&b!=0){
                    ans+='a'; ans+='a';a-=2;
                }
                else{
                    ans+='a';a-=1;
                }
            }
            while(b>0){ans+='b';b--;}
            while(a>0){ans+='a';a--;}
        }
        return ans;

    }
};