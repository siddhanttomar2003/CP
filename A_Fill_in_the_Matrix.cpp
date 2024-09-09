#include <bits/stdc++.h>
typedef long long ll;
void solve()
{
	int n,m;
	std::cin >> n >>m;
	int ans = n<m ? n+1 : m>1 ? m : 0;
	std::cout << ans << "\n";
	int k = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			std::cout << (k+j)%m << " "; 
		}k++;
		if(k ==m-1)k = 0;
		std::cout << "\n";
	}

}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}
}