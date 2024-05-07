#include<bits/stdc++.h>
 
using namespace std;
 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define in insert 
#define fo(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
 
typedef long long ll;
// typedef long long int;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int>pii;
typedef pair<ll, ll>pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii>vpii;
typedef vector<pl>vpl;
typedef vector<vi>vvi;
typedef vector<vl>vvl;
typedef map<ll,ll>mpl;
typedef unordered_map<ll,ll>umpl;
 
const ll MAXN = 1e6+5;
const ll M = 1e9+7;
vector<vector<ll>> allSubsets(vector<ll>& nums) {
        ll n = nums.size();
        ll mask = pow(2, n)-1;
        vector<vector<ll>> subsets;
        for(ll i = 0; i<=mask; ++i){
            vector<ll> subset;
            for(ll j = 0; j<n; ++j){
                if(i&(1<<j)){
                    subset.push_back(nums[j]);
                }
            }
            subsets.push_back(subset);   
        }
        return subsets;
}
 
ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}
 
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}
 
ll bex(ll a, ll b){
 
    ll ans = 1;
    while(b){
 
        if(b&1){
            b--;
            ans*=a;
        }
       
       b = b>>1;
       a = a*a;
    }
    return ans;
}
 
ll bex(ll a, ll b, ll m){
    a%=m;
    ll ans = 1;
    while(b){
 
        if(b&1){
            b--;
            ans*=a;
            ans%=m;
        }
       
       b = b>>1;
       a = (a*a)%m;
    }
    return ans;
}
 
ll binMul(ll a, ll b, ll mod){
    long long res = 0; // Initialize result
 
    // Update a if it is more than
    // or equal to mod
    a %= mod;
 
    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;
 
        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;
 
        b >>= 1; // b = b / 2
    }
 
    return res;
}
    
 
void pre(vl &v){
   fo(i,v.size()-1){
      v[i+1] += v[i];
   }
}
void post(vl &v){
   for(int i = v.size()-1; i>0; --i){
       v[i-1] += v[i];
   }
}
 
vl prime(MAXN+1,1);
vl lowestPrime(MAXN+1,0), highestPrime(MAXN+1,0);
 
void seive(){
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i<=MAXN; ++i){
        if(prime[i]){
            lowestPrime[i] = highestPrime[i] = i; //for prime numbers
           for(int j = 2*i; j<MAXN; j+=i){
               prime[j] = 0;
               highestPrime[j] = i;
               if(lowestPrime[j]==0){
                   lowestPrime[j] = i;
               }
           }
        }
    }
}
 
bool checkPrime(ll n){
    if(n==1)  return false;
 
    for(int i = 2;  i*i<n ; ++i){
        if(n%i==0) return false;
    }
 
    return true;
}
 
vl primeFactors(ll n){
   vl prime_fac;
   ll temp = n;
   while(temp>1){
       ll p = lowestPrime[temp]; // or u can also take highest or any other prime
       while(temp%p==0){
           prime_fac.push_back(p);
           temp/=p;
       }
   }
   return prime_fac;
}
 
vl primeFactorsWithoutSeive(ll n){
 
 
    vl ans;
    while(n%2==0){
        n/=2;
        ans.pb(2);
    }
    for(ll i = 3; i<= sqrt(n); i+=2){
        while(n%i==0){
            ans.pb(i);
            n/=i;
        }
    }
   
    if(n>2){
        ans.pb(n);
    }
    return ans;
}
 
set<ll> uniquePrimeFactors(ll n){
    set<ll> ans;
    while(n%2==0){
        n/=2;
        ans.insert(2);
    }
    for(ll i = 3; i<= sqrt(n); i+=2){
        while(n%i==0){
            ans.in(i);
            n/=i;
        }
    }
 
    if(n>2){
        ans.in(n);
    }
    return ans;
}
 
set<ll> uniqueDivisors(ll n){
    set<ll> ans;
    ll temp = n;
    rep(i,1,sqrt(n)+1){
        if(temp%i==0){
            ans.in(i);
            ans.in(n/i);
        }
    }
    return ans;
}
 

 
/* (a/b)%m = (a*(b^-1))%m {(b^-1)%m = modular multiplicative inverse(MMI) of b}
   if (a*b)%m = 1, then b is MMI of a
   from fermat theorem  A^-1 = (A^(M-2))%M, where m is prime
 
    */
 
ll modInverse(ll A, ll m){
    return bex(A, m-2, m);
}
 
 
ll fact[(int)1e3+5];
void initializeFact(ll m){
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i<(int)(1e3)+5; ++i){
        fact[i] =  (fact[i-1]*i)%m;
    }
}
ll nCrModM(ll n, ll r, ll m){
     ll ans = fact[n]%m;
     ll den = (fact[r]*fact[n-r])%m;
     ans*= modInverse(den, m)%m;
     ans%=m;
     return ans;
}
ll nPrModM(ll n, ll r, ll m){
     ll ans = fact[n]%m;
    // cout<<ans<<"a\n";
     ll den = (fact[n-r])%m;
   // cout<<modInverse(den, m)<<"den\n";
     ans*= modInverse(den, m)%m;
     ans%=m;
     return ans;
}
 
vector<string> split (string str, char seperator)  
{  
    vector<string> strings;
       stringstream X(str); // X is an object of stringstream that references the S string  
       string T;
    // use while loop to check the getline() function condition  
    while (getline(X, T, seperator)) {  
        /* X represents to read the string from stringstream, T use for store the token string and, 
         ' ' whitespace represents to split the string where whitespace is found. */  
          
        strings.push_back(T);
    }  
    return strings;
}  
 
int lcs(string text1, string text2) {
       int n = text1.size();
       int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i<=n; ++i){
            for(int j = 1; j<=m; ++j){
                int op1 = (text1[i-1]==text2[j-1])+dp[i-1][j-1];
                int op2 = dp[i-1][j];
                int op3 = dp[i][j-1];
                dp[i][j] = max({op1, op2, op3});
            }
        }
        return dp[n][m];
    }
 
int computeXOR(int n)
{
   
  // If n is a multiple of 4
  if (n % 4 == 0)
    return n;
 
  // If n%4 gives remainder 1
  if (n % 4 == 1)
    return 1;
 
  // If n%4 gives remainder 2
  if (n % 4 == 2)
    return n + 1;
 
  // If n%4 gives remainder 3
  return 0;
}

bool isSubSequence(string str1, string str2)
{
    int m = str1.size(), n = str2.size();
    int j = 0; // For index of str1 (or subsequence
 
    // Traverse str2 and str1, and
    // compare current character
    // of str2 with first unmatched char
    // of str1, if matched
    // then move ahead in str1
    for (int i = 0; i < n && j < m; i++){
        
        if (str1[j] == str2[i]){
            j++;
        }
    }
    // If all characters of str1 were found in str2
    return (j == m);
}


void rotateMatrix(vector<vector<int>>& mat)
{
    // Consider all squares one by one
    int N = mat.size();
    for (int x = 0; x < N / 2; x++) {
        // Consider elements in group
        // of 4 in current square
        for (int y = x; y < N - x - 1; y++) {
            // Store current cell in
            // temp variable
            int temp = mat[x][y];
 
            // Move values from right to top
            mat[x][y] = mat[y][N - 1 - x];
 
            // Move values from bottom to right
            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];
 
            // Move values from left to bottom
            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];
 
            // Assign temp to left
            mat[N - 1 - y][x] = temp;
        }
    }
}



int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}
 
int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

int EvaluateExpression(char* expr){
    int i;
    string tokens = convertToString(expr, sizeof(expr)/sizeof(char));
    stack <int> values;
     
    stack <char> ops;
     
    for(i = 0; i < sizeof(tokens)/sizeof(tokens[0]); i++){
         
        if(tokens[i] == ' ')
            continue;
         
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }
         
        else if(isdigit(tokens[i])){
            int val = 0;
             
            while(i < sizeof(tokens)/sizeof(tokens[0]) &&
                        isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
             
            values.push(val);
             
              i--;
        }
         
        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();
                 
                int val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
             
            if(!ops.empty())
               ops.pop();
        }
         
        else
        {
            while(!ops.empty() && precedence(ops.top())
                                >= precedence(tokens[i])){
                int val2 = values.top();
                values.pop();
                 
                int val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
             
            ops.push(tokens[i]);
        }
    }
     
    while(!ops.empty()){
        int val2 = values.top();
        values.pop();
                 
        int val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();
                 
        values.push(applyOp(val1, val2, op));
    }
     
    return values.top();
}

bool is(ll k, vl a){
    bool ans = 1;
    ll toAdd = 0;
    ll e;
    for(ll i = 1; i<=k; ++i){
         e = (*(min_element(all(a))));
         int cnt = 0;
         for(int f: a){
            if(f==e){
                cnt++;
            }
         }
        if((((e+toAdd)>(k-i+1))&&(cnt==1))||(e>(k-i+1))){
            return false;
        }
        int idx = (int)(upper_bound(all(a), (k-i+1))-a.begin());
        toAdd += (k-i+1);
        idx--;
        a[idx] = 10000;
       }
    //    cout<<" s\n";
    return true;
}

string longDivision(string number, int divisor)
{
    // As result can be very large store it in string
    string ans;
 
    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');
 
    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.size() > idx) {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';
 
        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
 
    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";
 
    // else return ans
    return ans;
}


string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";
 
    // will keep the result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);
 
    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;
     
    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;
         
        // Go from right to left in num2            
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";
 
    // generate the result string
    string s = "";
     
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
}

ll count1(vector<int>& arr,
                   int n)
{
    // to search for index with
    // (current prefix sum - j*j)
    unordered_map<int, int> mp;
 
    // storing the prefix sum
    int prefixSum[n];
 
    // used to track the minimum
    // value in prefixSum
    int prefixMin = 0;
 
    prefixSum[0] = arr[0];
    prefixMin = min(prefixMin,
                    prefixSum[0]);
 
    // Calculating the prefixSum
    // and tracking the prefixMin
    for (int i = 1; i < n; i++) {
 
        prefixSum[i] = prefixSum[i - 1]
                       ^arr[i];
 
        // below statement is used if
        // array contains
        // negative numbers
        prefixMin = min(prefixMin,
                        prefixSum[i]);
    }
 
    // counts the no of subarrays
    // with perfect square sum
    ll countSubs = 0;
 
    // as 0 is a perfect square,
    // so we initialize 0th
    // index-key with value 1
     mp[0] = 1;
 
    // Here we count the perfect
    // square subarray sum by
    // searching if there is a
    // prefix with
    // sum = (current prefixSum - (sq*sq))
    for (int i = 0; i < n; i++) {
        for (int j = 0;
             prefixSum[i]^(j * j) >= prefixMin;
             j++) {
 
            if (mp.find(prefixSum[i]^(j * j))
                != mp.end())
 
                // increasing our subarray count
                countSubs += mp[prefixSum[i]^(j * j)];
                // cout<<mp[prefixSum[i]- j * j]<<" "<<prefixSum[i]- j * j<<"\n";
        }
        
        // increasing the current prefixSum
        // index value in map by 1 to count
        // the other perfect squares while
        // traversing further
        mp[prefixSum[i]]++;
    }
 
    return countSubs;
}



void solve(){
    ll n, k;
    cin>>n>>k;
    vl a(n), b(n);
    fo(i,n) cin>>a[i];
    fo(i,n) cin>>b[i];
    ll ans = 0, mx = 0, sum = 0;
    fo(i, min(k,n)){
        ll curr = a[i];
        mx = max(mx, b[i]);
        sum+=curr;
        ans = max(ans, sum+(k-i-1)*mx);
        // cout<<ans<<" "<<i<<'\n';
    }
    cout<<ans<<"\n";
}
int main(){
 
    #ifndef ONLINE_JUDGE 
 
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
    
    #endif

 
        fastio();
        //  seive();
        //  initializeFact(998244353);
       // memset(memo, -1, sizeof(memo));
    
        int t = 1;
        cin>>t;
        while(t--){
            solve();
        }
 
return 0;
}