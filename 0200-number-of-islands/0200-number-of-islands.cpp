
//author:-Siddhant Tomar
//linked in :-https://www.linkedin.com/in/siddhant-tomar-9b3aab261/


#include <bits/stdc++.h>
using namespace std;

//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//Macros
#define IOtext freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define foreach(i, j, k, in) for(int i=j;i<k;i+=in)
#define rforeach(i, j, k, in) for(int i=j;i>=k;i-=in)
#define rep(i,j,s) foreach(i,s,j,1)
#define rrep(i,j,k) rforeach(i,j,k,1)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define sz(s) (int)(s.size())
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define inint(x) int x; cin>>x;
#define inf  int flag=0;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define all(x) x.begin(), x.end()
#define os(x) cout << x << " ";
#define out(x) cout << x << endl;
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define COUNT(x,u) count(all(x), u)
#define B break
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pm cout<<"-1"<<endl
#define po cout<<"0"<<endl;
#define ps(x,y) fixed<<setprecision(y)<<x
#define pe cout<<endl
#define inv rep(i,n){cin>>v[i];}
#define invv rep(i,n){rep(j,m){cin>>vv[i][j];}}
#define ouv rep(i,n){cout<<v[i]<<" ";}
#define inv2 rep(i,n){cin>>v2[i];}
#define inv3 rep(i,n){cin>>v3[i];}
#define inv4 rep(i,n){cin>>v4[i];}
#define sort(v) sort(v.begin(),v.end());
#define add(sum,v) accumulate(v.begin(),v.end(),sum);
#define repa(it)      for(auto it:mp)

//Typedef
typedef long long ll;
typedef unordered_map<ll,ll> ull;
typedef  map<ll,ll> oll;
typedef long double lld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef set<int> st;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif


// Operator overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T, typename V> // cout << map<T,T>
ostream& operator<<(ostream &ostream, const map<T,V> &c) { for (auto &it : c) cout << it.first << " " << it.second<<endl; return ostream; }

//Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}


//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

//Constants
vector <ll> primes;
vector <bool> is_prime;

// Mathematical functions
void Sieve(int n){ is_prime.assign(n + 1, true); is_prime[0] = is_prime[1] = false; for(ll i = 2; i * i <= n; i++) if(is_prime[i]) for(ll j = i * i; j <= n; j += i) is_prime[j] = false;}
void get_primes(int n){ for(int i = 2; i <= n; i++)  if(is_prime[i])  primes.push_back(i); }
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
ll count_one(int n) { ll count=0; while(n) {  n = n&(n-1); count++; } return count;}
bool isPowerOfFour(int n) { return !(n&(n-1)) && (n&0x55555555);//check the 1-bit location;
}
ll modinv(ll p,ll q){ll ex;ex=M-2;while (ex) {if (ex & 1) {p = (p * q) % M;}q = (q * q) % M;ex>>= 1;}return p;}

ll binomial_expo (ll a, ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%1000000007;
        }
        a=(a*a)%1000000007;
        b>>=1;
        
    }
    return ans;
}
ll buildTree(ll i, ll l, ll r, vector<ll> & v,vector<ll> &Seg_tree){
 if(l==r){
   Seg_tree[i]=v[l];
   return Seg_tree[i];
 }
 ll mid=(l+r)/2;
 ll build_left=buildTree(2*i+1,l,mid,v,Seg_tree);
 ll build_right=buildTree(2*i+2,mid+1,r,v,Seg_tree);
 Seg_tree[i]=build_left+build_right;
 return Seg_tree[i];
}
 ll updateTree(ll i,ll l ,ll r , ll a, vl &Seg_tree,ll value){
    if(l==r &&r==a){
        Seg_tree[i]=value;
        return Seg_tree[i];
    }
     if(r<a || l>a)return Seg_tree[i];
     ll mid=(l+r)/2;
    ll left= updateTree(2*i+1,l,mid,a,Seg_tree,value);
      ll right= updateTree(2*i+2,mid+1,r,a,Seg_tree,value);
      return Seg_tree[i]=left+right ;
 }
  ll travel(ll i, ll a, ll b, ll l , ll r , vl &Seg_tree ){
    if(l>=a && r<=b)return Seg_tree[i];
    if(l>b || r<a)return 0;// outofbounds
    if(l==r)return 0;
    ll mid=(l+r)/2;
    ll left=travel(2*i+1,a,b,l,mid,Seg_tree);
    ll right=travel(2*i+2,a,b,mid+1,r,Seg_tree);
    return left+right;
 }
class Solution {
public:
 void dfs(vvl  &adj, vi &is_Visited, int curr_node){
        rep(i,adj[curr_node].size(),0){
            if(!is_Visited[adj[curr_node][i]]){
                is_Visited[adj[curr_node][i]]=1;
                dfs(adj,is_Visited,adj[curr_node][i]);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // we can assume each point as node 
        // one island= number of different points we can reach from one point
        // similiar to different no. of provinces
       
        //  int curr=0;
         int n=grid.size();
         int m=grid[0].size();
        //   vvl mat(n,vl(m,0));
          int curr=0;
          rep(i,n,0){
            rep(j,m,0){
                if(grid[i][j]=='1'){
                    ++curr;
                    grid[i][j]=curr+48;
                }
            }
          }
        
         rep(i,n,0){
            rep(j,m,0)cout<<grid[i][j]<<" ";
            pe;
         }
         vvl adj(curr+1);
         rep(i,n,0){
            rep(j,m,0){
                if(grid[i][j]!='0'){
                    //right
                    if(j+1<m){
                        if(grid[i][j+1]!='0')adj[grid[i][j]-48].pb(grid[i][j+1]-48);
                    }
                    //left
                    if(j-1>=0){
                         if(grid[i][j-1]!='0')adj[grid[i][j]-48].pb(grid[i][j-1]-48);
                    }
                    //down
                    if(i+1<n){
                         if(grid[i+1][j]!='0')adj[grid[i][j]-48].pb(grid[i+1][j]-48);
                    }
                    // up
                    if(i-1>=0){
                         if(grid[i-1][j]!='0')adj[grid[i][j]-48].pb(grid[i-1][j]-48);
                    }

                }
            }
         }
         int ans=0;
         vi is_visited(curr+1,0);
         rep(i,curr+1,1){
            if(!is_visited[i]){
                ans++;
                int curr_node=i;
                dfs(adj,is_visited,curr_node);
            }
         }
         return ans;
// return 0;
    }
};