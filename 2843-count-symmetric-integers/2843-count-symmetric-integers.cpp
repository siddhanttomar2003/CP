class Solution {
public:
    bool check(string &a){
        int sum1=0;
        int sum2=0;
        int n=a.size();
        for(int i=0;i<n/2;i++){
            sum1+=(a[i]-48);
        }
        for(int i=n/2;i<n;i++){
            sum2+=(a[i]-48);
        }
        return sum1==sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            string a=to_string(i);
            if(a.size()&1){
                int len=a.size();
                string temp=string(len,'9');
                i=stoi(temp);
            }
            else {
                if(check(a))ans++;
            }
        }
        return ans;
    }
};