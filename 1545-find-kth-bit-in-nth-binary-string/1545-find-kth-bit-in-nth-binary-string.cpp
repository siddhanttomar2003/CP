class Solution {
public:
    char findKthBit(int n, int k) {
        int count=0;
        long long mid=pow(2,n)-1;
        mid/=2;k--;
        // cout<<n<<" "<<k<<endl;
        while(mid>0){
          if(k==mid){
            if(count&1) return '0';
            return '1';
          }
          else {
            if(k>mid){
                count++;
                long long dis=k-mid;
                k=mid-dis;
            }
            cout<<k<<endl;
            mid/=2;
          }
        }
        // cout<<count<<endl;
        if(count&1)return '1';

        return '0';

    }
};