class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        int a=0;
        for(int i=0;i<pow(2,n);i++){
            string t="";
            int ch[26]={0};
            bool flag=true;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    for(int k=0;k<arr[j].length();k++){
                        ch[arr[j][k]-97]++;
                    }
                 t+=arr[j];
                }
                
                for(int i=0;i<26;i++){
                    if(ch[i]>1){
                        flag=false;
                        break;
                    }
                }
            }
            int b=t.length();
                if(flag)a=max(a,b);
            }
          
        
     
        return a;
    }
};