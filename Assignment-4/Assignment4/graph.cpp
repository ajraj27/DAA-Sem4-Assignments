#include<bits/stdc++.h>
using namespace std;
int main() {
	int t, len, c;
	int tic = 0;
	ofstream file;
	file.open("worstCase.dat");
	string s;
	s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//cin >> t;
	t = 10;
	while(t < 100) {
		// tic  =  clock();
											tic+=5;
		c = 0;
		s = s + "aaaaaaaaaa";
		len = s.length();
		for(int i = 0; i < len; i++) {
											tic+=4;
			for(int j = i+1; j < len; j++) {
											tic+=3;
				if(s[i] == s[j]) {
											tic+=2;
					cout << s.substr(i,j-i+1) << '\n';
					c++;
				}
			}
		}
		// toc = clock();
		// float time = (float)(toc - tic);
		float time = (float)tic;
		time = time/CLOCKS_PER_SEC;
		file << t << '\t' << time << '\n';
		t+= 10;
		cout << c << '\n';
	}
	file.close();
	return 0;
}