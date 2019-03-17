#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int len = s.length(), sum = 0;
		map < char, vector <int> > m;
		for(int i = 0; i < len; i++) {
			m[s[i]].push_back(i);
		}
		map< char, vector < int > > :: iterator it;
		for(it = m.begin(); it != m.end(); it++){
			int vSize = (it->second).size();
			if(vSize > 1) {
				cout << "STARTING(ENDING) WITH : " << it->first << endl;

				for(int i = 0; i < vSize; i++){
					for(int j = i+1; j < vSize; j++) {
						cout  << '\t' << s.substr((it->second)[i], (it->second)[j] - (it->second)[i] + 1) << endl;
					}
				}
				sum += vSize*(vSize-1)/2;
			}
		}
		cout << " TOTAL SUBRSTRING WITH SAME START AND END " << sum << endl;
	}
}
