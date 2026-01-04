class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int a = nums[i];
            int div1 = -1, div2 = -1;
            for(int j = 2; j <= sqrt(a); j++){
                if(a % j == 0 && div1 == -1){
                   div1 = j;
                   div2 = a / j;
                }
                else if(a % j == 0){
                    div1 = -1, div2 = -1;
                    break;
                }
            }
            if(div2 != -1){
                int contri = 1 + div1 + div2 + a;
                cout << a << " " <<  div1 << " " << div2 << endl;
                if(div1 * div2 == a && div1 != div2)ans += contri;
            }
        }
        return ans;
    }
};