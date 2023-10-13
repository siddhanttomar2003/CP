#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    int n;
	    cin >> n;
	    
	    int arr[N];
	    int totalCandies = 0;
	    
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	        totalCandies += arr[i];
	    }
	    
	    
	    // Difference not more than 1 simply means we want our total number of candies to be an odd number, as long as it is odd we can divide it among siblings with a difference of 1 
	    
	    // Eg: 5 = 3 + 2, 23 = 12 + 11, 45 = 23 + 22 
	    
	    cout << ((totalCandies%2 != 0) ? "YES" : "NO") << endl;
	}
	
	
	return 0;
}
