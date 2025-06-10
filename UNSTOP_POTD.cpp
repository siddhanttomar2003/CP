#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAXN = 101;
static const int MAXM = 101;
static const int MAXK = 10;

// dp[i][j][c] = best score from (i,j) when you have c steps of cooldown remaining.
// We store LLONG_MIN to mean “not yet computed or impossible.”
static ll dp[MAXN][MAXM][MAXK+1];

int n, m;
vector<vector<ll>> grid;

// Check in‐bounds and not a wall
bool valid(int r,int c){
    return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != -1;
}

// Directions
int dr[4] = {-1,0,1,0}, dc[4] = {0,1,0,-1};

ll cal(int i,int j,int steps){
    // Clamp steps into [0..MAXK]
    if(steps < 0) steps = 0;
    if(steps > MAXK) steps = MAXK;

    // Base: reached target
    if(i == n-1 && j == m-1){
        // If we arrive off‐cooldown, we may collect the final rune
        if(steps == 0 && grid[i][j] > 0)
            return grid[i][j];
        else
            return 0;
    }

    // If dp already filled, return it
    ll &ans = dp[i][j][steps];
    if(ans != LLONG_MIN) 
        return ans;

    // Temporarily mark as “in progress” to break cycles
    ans = LLONG_MIN + 1;  

    ll best = LLONG_MIN;

    // Next cooldown if we just move
    int baseCd = max(0, steps - 1);

    // 1) Move without picking up a rune here
    for(int k = 0; k < 4; ++k){
        int ni = i + dr[k], nj = j + dc[k];
        if(!valid(ni,nj)) 
            continue;
        best = max(best, cal(ni, nj, baseCd));
    }

    // 2) If there is a rune here (grid[i][j]>0) and we are off‐cooldown, pick it up:
    if(steps == 0 && grid[i][j] > 0){
        ll gain = grid[i][j];
        int refill = min((int)grid[i][j], MAXK);
        int afterCd = max(0, refill - 1);
        for(int k = 0; k < 4; ++k){
            int ni = i + dr[k], nj = j + dc[k];
            if(!valid(ni,nj)) 
                continue;
            best = max(best, gain + cal(ni, nj, afterCd));
        }
    }

    // Store the result (or LLONG_MIN if no valid moves)
    return ans = best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.assign(n, vector<ll>(m));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> grid[i][j];

    // Initialize DP to “not computed”
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        for(int c = 0; c <= MAXK; ++c)
          dp[i][j][c] = LLONG_MIN;

    ll result = cal(0, 0, 0);
    // If LLONG_MIN (i.e. unreachable), clamp to 0
    cout << max(0LL, result) << "\n";
    return 0;
}
