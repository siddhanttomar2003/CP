#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int x;
	cin>>x;
	if(x<3)cout<<"GOLD"<<endl;
	else if(x<6)cout<<"SILVER"<<endl;
	else cout<<"BRONZE"<<endl;
	return 0;
}
