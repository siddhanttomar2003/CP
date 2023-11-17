#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--){
	    int N,cnt=0;
	    cin >> N;
	    string temp1,temp2;
	    cin >> temp1;
	    for(int i=1;i<N;i++){
	        cin >> temp2;
	        for(int j=0;j<10;j++){
	            if(temp1[j]!=temp2[j]){
	                temp2[j] = '1';
	            }
	            else
	                temp2[j] = '0';
	        }
	        temp1 = temp2;
	    }
	    
	    for(int i=0;i<10;i++){
	        if(temp1[i]=='1')
	            cnt++;
	    }
	    cout << cnt << '\n';
	    
	}
	return 0;
}