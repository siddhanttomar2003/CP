/******** 
  
  *   Author: Zesty
  *   Motto: "Think Outside the box"

   ********/

#pragma GCC optimize("O3,unroll-loops")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug() cout << "try" << "\n";
#endif

#define read(type) readInt<type>() // Fast read
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define per(i,k,n) for (int i = k - 1; i >= n; i--)
#define nL "\n"
#define pb emplace_back
#define prec(n) fixed << setprecision(n)
#define mk make_pair
#define a first
#define b second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define umap unordered_map
#define uset unordered_set
#define maxSize 1000001
#define imax INT_MAX
#define imin INT_MIN
#define expo 1e9
#define sz(x) (int((x).size()))
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

// vll prime;
// vll adj[200001];
// vll vis(200001, 0);
vll rank(200001);
vll parent(200001);
vll mark(500001,0);

void debug2(vll & v, ll n){
   for(int i = 0; i < n ;i++) cout << v[i] << " ";
}

// Some constants
const int N = int(1e5 + 3);
const int gk = 1e9 + 7;
const double dbl = 1e-6;
const double pi = 1.00 * acos(-1.00);
const double EPS = 1e-9;
const int dx[8] = {1,0,-1,0,-1,-1,1,1}, dy[8] = {0,1,0,-1,-1,1,-1,1};


// <<<<<<< LCM >>>>>>> //
ll lcm(ll a, ll b) { return (a * (b / __gcd(a, b))); }


// <<<<<<< Sort pairs >>>>>>> //
bool cmp(const pair<ll,ll> &p1, const pair<ll,ll> &p2)
{
     if(p1.a == p2.a)
       return (p1.b < p2.b);
     return p1.a > p2.a;
}


   

// <<<<<<< Binary Exponentiation >>>>>>> // 
long long binpow(long long a, long long b) {
    //a %= gk;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

// <<<<<<< Binary Search >>>>>>> //
// ll binarySearch(vector<ll>& array, int x, int low, int high) {
     
//      while (low <= high) {
//        int mid = low + (high - low) / 2;
//        if (array[mid] == x)
//          return mid;
//        if (array[mid] < x)
//          low = mid + 1;
//        else
//          high = mid - 1;
//   }

//      return low;
// }

/**** Sieve ****/

//  void sieve()
// {

//     memset(vis, true, sizeof(vis));

//     for (ll p = 2; p * p <= 1000000; p++)
//     {

//         if (vis[p] == true)
//         {

//             for (ll i = p * p; i <= 1000000; i += p)
//                 vis[i] = false;
//         }
//     }

//     for (ll p = 2; p <= 1000000; p++)
//         if (vis[p])
//            prime.push_back(p);
// }


// <<<<<<< Euclid's GCD Algo >>>>>>> //
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}  


// void edge(int a, int b)
// {
//     adj[a].push_back(b);
//     // for undirected graph add this line
//     adj[b].push_back(a);
// }


/***** Breadth First Search *****/
// void BFS(int s) {
//     queue<int> q;
//     vis[s] = 0; 
//     q.push(s);
//     while (q.size()) {
//         int u = q.front(); 
//         cout << u << " ";
//         q.pop();
//         for (int v : adj[u]) {
//             if (vis[v] == 0) {
//                 vis[v] = 1;
//                 q.push(v);
//             }
//         }
//     }
// }

void BFSonGrid(vector<vector<char>>& vc,vector<vll>& vis, ll n, ll m, ll i, ll j) {
    queue<pair<ll,ll>> q;
    vis[i][j] = 1; 
    q.push({i,j});
    // cnt--;
    // ll cnt = 0;
    while (q.size()) {
        auto u = q.front(); 
        // cout << u << " ";
        q.pop();
        rep(i,0,8){
          ll newRow = u.a + dx[i];
          ll newCol = u.b + dy[i];
          // if(cnt == 0) break;
          if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && vc[newRow][newCol] == '#' && !vis[newRow][newCol]){
            q.push({newRow,newCol});
            vis[newRow][newCol] = 1;
          }
        }
    }
}

/***** Depth First Search *****/
// ll dfs(int u, vector<ll>& vis, vector<vector<pair<ll,ll>>>& adj) {
//     vis[u] = 1;
//    //  cout << u << " ";
//     ll cur = 0;
//     for (auto v : adj[u]) {
//         if (!vis[v.a]){
//           cur = max(cur,v.b + (dfs(v.a, vis, adj)));
//         } 
//     }
//     vis[u] = 0;
//     return cur;
// }

// void DFS(int V) {
//     for (int u = 1; u <= V; u++)
//         if (vis[u] == false)
//             dfs(u, vis, adj);
// }

/****** Function to detect cycle in an undirected graph ******/
// bool dfs(int src, vector<int> adj[], vector<int>& vis, int parent){
//       vis[src] = 1;
//       for(auto it: adj[src]){
//          if(it == parent) continue;
//          if(vis[it]) return true;
//          if(dfs(it, adj, vis, src)) return true;
//       }
//         return false;
// }
// bool isCycle(int V, vector<int> adj[]) {
//       // Code here
//       vector<int> vis(100001,0);
//       for(int i = 0; i < V; i++){
//          if(!vis[i] && dfs(i, adj, vis, -1)) return true;
//       }
//       return false;
// }

/*** Representing in Bit ***/
// void bitRepresntation(vector<vll>&v,ll num, ll ind){
//   // ll pos = -1;
//    rep(i,0,31){
//         // if(num & 1) pos = cnt;
//         v[ind][i] = num & 1;
//         // cnt++;
//         num >>= 1; 
//    }
// }
/**** Last Set Bit ****/
// int lastSetBit(int n){
//     return log2(n & -n) + 1;
// }

/****** To check Power of 2 *****/
// int isPowerof2(int x)
// {
//     return (x && !(x & x-1));
// }


/**** Check for Square Root ****/
// bool isSqrt(ll num){
//     ll sq = sqrt(num);
 
//     return sq * sq == num;
// }

/**** Check Palindrome *****/
bool isPalin(string s){
  int n = s.length();
  for(int i = 0; i < n / 2; i++){
    if(s[i] != s[n - i - 1]) return false;
  }
  return true;
}

/**** Absolute Dif ****/
// ll abs(ll a, ll b)
// {
//     if (a > b)
//         return a - b;
//     else
//         return b - a;
// }


/***** Sum of digits *****/
// ll digitSum(ll num){
//   ll sum = 0;
//   while(num > 0){
//     sum += num % 10;
//     num /= 10;
//   }
//   return sum;
// }

// vll fib(vll& fibSeq, ll n, ll x, ll y) {
//     fibSeq.push_back(x);
//     fibSeq.push_back(y);

//     for (int i = 2; i <= n; ++i) {
//         ll nextFib = fibSeq[i - 1] + fibSeq[i - 2];
//         fibSeq.push_back(nextFib);
//     }
//     return fibSeq;
// }

/**** CUSTOM HASH ****/
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

/*****
  Additional Fun 
                  *****/
// ll zesty(vll& v, ll num, ll sum1, ll sum2, ll n, ll ans){
//   if(num == n){
    
//   }

// }

   
/***** Main Area *****/

void solve(){
    
    ll n, m = 1, p = 0, q = 0, x = 0, y = 0, l = 0, r = 1, k = 0, d = 0, o = 0,z = 0, ng = 0, e = 0, ind = -1, n1 = 0, n2 = 0, fg = 1, num, num1 = 0,num2 = 0,sum = 0,sum1 = 0,sum2 = 0,cnt = 0, f1 = 0, f2 = 0, ans = 0,mn, mx = imin, a = 0, b = 0, c;
    string s, str, s1 = "",s2 = "", sk = "", ak = "";
    char ch = 'a',ch1,ch2;
    bool dk = false, dk1 = true;
    // priority_queue<pair<ll,ll>> pq;
    // map<pair<ll,ll>,ll> mp;
    // map<char,ll> mp,mp1,mp2;
    // umap<ll, ll, custom_hash> mp;
    // vector<pair<ll,ll>> vp;
    // vector<vector<char>> vc(n,vector<char> (n));
    // rep(i,0,n){
    //   rep(j,0,n)
    //   cin >> vc[i][j];
    // }

    cin >> n;
    cin >> s;
    
    vll res;
    if(n % 2) cout << -1 << nL;
    else {
      l = 0, r = n - 1;
      while(l <= r && cnt < 300){
        if(s[l] == s[r]){
          if(s[l] == '0'){
            res.pb(r + 1);
            s.insert(r + 1, "01");
          } else {
            res.pb(l);
            s.insert(l,"01");
          } cnt++;
          l = 0;
          r = s.size() - 1;
        } else {
          l++;
          r--;
        }
      }
      if(l < r) cout << -1 << nL;
      else {
      cout << cnt << nL;
      for(auto it: res) cout << it << " ";
      cout << nL;
      }
    
    }
    
    
}

 


int main(){
//    #ifdef _DEBUG
// 	  freopen("input.txt", "r", stdin);
//  	freopen("output.txt", "w", stdout);
//    #endif

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
    return 0;
}