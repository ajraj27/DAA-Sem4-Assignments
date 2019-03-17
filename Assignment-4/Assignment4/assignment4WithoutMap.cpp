#include<bits/stdc++.h>
using namespace std;
int main() {
	int t, len, c;
	string s;
	cin >> t;
	while(t--) {
		c = 0;
		cin >> s;
		len = s.length();
		for(int i = 0; i < len; i++) {
			for(int j = i+1; j < len; j++) {
				if(s[i] == s[j]) {
					cout << s.substr(i,j-i+1) << '\n';
					c++;
				}
			}
		}
		cout << c << '\n';
	}
	return 0;
}

