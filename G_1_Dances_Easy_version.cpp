//author:-Siddhant Tomar
//linked in :-https://www.linkedin.com/in/siddhant-tomar-9b3aab261/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
 using namespace __gnu_pbds;
   typedef tree<
       int, 
       null_type, 
       less<int>, 
       rb_tree_tag, 
       tree_order_statistics_node_update> 
       ordered_set;
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
#define inv rep(i,n,0){cin>>v[i];}
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
void solve(){
     inint(n);
     inint(m);
     vl a(n-1);
     rep(i,n-1,0)cin>>a[i];
     vl b(n);
     map<int,int>mp;
     rep(i,n,0){
        cin>>b[i];
         mp[b[i]]++;
     }
     rep(i,n-1,0){
        auto it=mp.upper_bound(a[i]);
        if(it!=mp.end()){
            int num=it->first;
            mp[num]--;
            if(mp[num]==0)mp.erase(num);
        }
     }
     ll rem=0;
     for(auto it:mp){
        rem+=it.second;
     }
     int number=mp.rbegin()->first;
     if(number>1)rem--;
     cout<<rem<<endl;
}
//  IMPORTANT :-  First look up the constraints first for every value given not just n for every valueeeee.
//  1. If greedy :-
//       0. If it is an interval related problem try either sorting in an optimal way or line sweep algorithm.
//       1. think of prefix or suffix sum
//       2. think of binary search :-  either lowerbound / upperbound , binary search on answers, when constraints are 
//        greater than 10^9 or around 10^18
//       3. iterate from last 
//       4. think of any mathematical expression :- for ex  (we use seive function cleverly)
//       5. think of map , we can create any types of map ,  for ex:- int,vectorint etc , we can also use ordered map for extra functionalities.
//       6. we can also use priorityqueue
//       IMPORTANT 1:- * If the question requires last greater or last smaller or next greater or next smaller use stack     
//       IMPORTANT 2:-  * If the question require first greater or first smaller for i'th index then u can pre_min or max array with bs.
//  2. Two pointers:-
//        1. maintain two pointers on different arrays
//        2. sliding window 
//  3. Bit manipulation :-
//        1. just follow the properties greedily of or , xor and and;
//  4. Dynamic Programming :-
//        1. think of state using constraints and requirement 
//        2. if ans is not coming in given states try to increase states and find the states smartly not violating the constraints
//  5. Graph :-
//        1. either bfs / dfs or dijkstra
//        2. use dsu.
//        3. u may also require to use dp to calculate the precomputed value for correct ans , means somewhat u have to use dfs.
//        4. U can use kahns algo for finding whether there is cycle or not , the vector will return the nodes which are not in the cycle.
//   6. If u are not able to proove that  any of your approaches is correct
//       1. There might be a brute force solution which is actually not exceeding the time limit
//          (Just carefully observe how many max times a loop can run if i do it and try to proove it will be in given constraints).
int32_t main()
{
    fastio()
    #ifndef ONLINE_JUDGE
        freopen("Error.txt","w",stderr);
    #endif
   // Jai Bajrang Bali 
    int t;
    cin>>t;
    while(t--)
    {
     solve();
    }
    return 0;
}