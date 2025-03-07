class Solution {
public:
    vector<int>is_prime;
    vector<int>last_prime;
    void Sieve(int n){
        is_prime.resize(n,true);
        is_prime[0]=is_prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(is_prime[i]){
                for(int j=i*i;j<n;j+=i){
                    is_prime[j]=false;
                }
            }
        }
    }
    void l_prime(int n){
      last_prime.resize(n);
      int last=n-1;
      for(int i=n-1;i>=1;i--){
        if(is_prime[last]){
            last_prime[i]=last;
        }
        else last_prime[i]=-1;
        if(is_prime[i])last=i;
      }
    }
    vector<int> closestPrimes(int left, int right) {
        Sieve(right+1);
        l_prime(right+1);
        int mini=1e9;
        int l=-1;
        int r=-1;
        for(int i=left;i<right;i++){
            if(is_prime[i] && last_prime[i]!=-1){
               int diff=last_prime[i]-i;
                if(mini>diff){
                    mini=diff;
                    l=i;r=last_prime[i];
                }
            }
        }
        return {l,r};
    }
};