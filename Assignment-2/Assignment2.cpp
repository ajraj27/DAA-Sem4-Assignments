#include<bits/stdc++.h>
#include<time.h>
#define DMAX 1000
using namespace std;
long long int timer;
int lookUp[] = {1,2,3,4,5,6,7,8,9,
				2,4,6,8,10,12,14,16,18,
				3,6,9,12,15,18,21,24,27,
				4,8,12,16,20,24,28,32,36,
				5,10,15,20,25,30,35,40,45,
				6,12,18,24,30,36,42,48,54,
				7,14,21,28,35,42,49,56,63,
				8,16,24,32,40,48,56,64,72,
				9,18,27,36,45,54,63,72,81};

int mul(int a, int b){
																				timer += 1;
	int c = 0;
	while(b--) {
																				timer += 2;
		c += a;
	}
																				timer += 1;
	return c;
}
int AtoI(char a){
																				timer += 1;
	return a - 48;
}
int multiply(int i, int j) {
																				timer += 1;
	if(i == 0 || j == 0) return 0;
																				timer += 1;
	return lookUp[mul(9,i-1)+(j-1)];
}
string zeroStr(int i) {
	string s = "";
	while(i--){
		s = s + '0';
	}
	return s;
}
int main() {
	clock_t tic, toc;
	ofstream file;
	file.open("plotAssignment2avg.dat");
	string aStr, bStr, productStr, resultantStr;
	long long int a, b, t, i, j, carry, product, result, resultant, aLen, bLen, productLen, finalAnswer;
	cout;
	cout << setw(10) <<"n(a = b)" << setw(15) << "Result" << setw(10) << "duration" << endl;
	for(long long int k = 1; k < 2000000; k += 100 ) {
		tic = clock();
		finalAnswer = 0;
																				timer += 1;
		a = b = k-1;
																				timer += 1;
		stringstream numParser;
																				timer += 2;
		numParser << a << " " << b ;
		numParser >> aStr >> bStr;
																				timer += 2;
		aLen = aStr.length();
		bLen = bStr.length();
																				timer += 2;
		reverse(aStr.begin(), aStr.end());
		reverse(bStr.begin(), bStr.end());
																				timer += 2;
		for(i = 0; i < bLen; i++) {
																				timer += 2;
																				timer += 3;
			carry = 0;
			stringstream resultParser, thirdParser;
			resultParser << zeroStr(i);
																				timer += 2;
			for(j = 0; j < aLen; j++) {
						
																				timer += 3;
				stringstream productParser;
																				timer += 1;
				product = multiply( AtoI(aStr[j]), AtoI(bStr[i]));
																				timer += 4;
				product += carry;
				productParser << product;
				productParser >> productStr;
				productLen = productStr.length();
																				timer += 1;
			
																				timer += 1;
				if(productLen == 2) {
																				timer += 2;
					result = AtoI(productStr[1]);
					carry = AtoI(productStr[0]);
				}
				else if(productLen == 1) {
																				timer += 2;
					result = AtoI(productStr[0]);
					carry = 0;
				}
																				timer += 1;
				resultParser << result;
			
			}
																				timer += 1;
			if(carry != 0) {
																				timer += 1;
				resultParser << carry;
			}
																				timer += 2;
			resultParser >> resultantStr;
			reverse(resultantStr.begin(), resultantStr.end());
																				timer += 3;
			thirdParser << resultantStr;
			thirdParser >> resultant;
			finalAnswer += resultant;
		}
		toc = clock();
		float duration = (float)timer;
		duration = duration/CLOCKS_PER_SEC;
		cout << setw(10) << a << setw(15) << finalAnswer << setw(10) << duration << endl;
		file << a << '\t' << duration << endl;
	}
}