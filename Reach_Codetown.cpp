#include <iostream>
using namespace std;

int letter(char x) {
  if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
    return 1;
  else return 0;
}

int main() {
	// your code goes here
	int t;
	string s;
	cin >> t;
	while(t--) {
	  cin >> s;
	  if(letter(s[1]) && letter(s[3]) && letter(s[5]) && !letter(s[0]) && !letter(s[2]) && !letter(s[4]) && !letter(s[6]) && !letter(s[7]))
	    cout << "YES\n";
	  else
	    cout << "NO\n";
	}
	return 0;
}