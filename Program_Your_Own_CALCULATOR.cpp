#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b;
	char c;
	cin>>a>>b>>c;
	cout<<fixed<<setprecision(7)<<(c=='+'?a+b:(c=='-'?a-b:(c=='*'?a*b:(b!=0?(double)a/b:0))));
	return 0;
}
