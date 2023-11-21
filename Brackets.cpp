#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >>t;
	while(t--){
	    string s;
	    cin >>s;
	    int maxVal = 0;
	    int val = 0;
	    for(int i=0; i<s.length(); i++){
	        if(s[i] == '(') val++;
	        if(s[i] == ')') val--;
	        maxVal = max(maxVal, val);
	    }
	    int temp = maxVal;
	    while(temp--) cout <<'(';
	    while(maxVal--) cout <<')';
	    cout <<endl;
	}
	return 0;
}