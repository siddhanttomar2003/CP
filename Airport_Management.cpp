#include <iostream>
#include <unordered_map>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int tt;
  std::cin >> tt;
  while(tt--) {
    int n;
    std::cin >> n;
    int a[n * 2];
    for(int i = 0; i < 2 * n; i++) std::cin >> a[i];
    std::unordered_map<int, int> freqMap;
    for(int i = 0; i < 2 * n; i++) freqMap[a[i]]++;
    int m = 0;
    for(auto& x : freqMap) if(x.second > m) m = x.second;
    std::cout << m << '\n';
  }
  return 0;
}