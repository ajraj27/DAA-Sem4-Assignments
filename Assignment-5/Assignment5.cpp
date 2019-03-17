#include<bits/stdc++.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>
using namespace std;
vector< int > myvector(9,0);
// Binary search 
int GetCeilIndex(vector< int > &arr, vector< int > &T, int l, int r, int key) 
{ 
    while (r - l > 1) 
    { 
        int m = l + (r - l)/2; 
        if (arr[T[m]] >= key) 
            r = m; 
        else
            l = m; 
    } 
  
    return r; 
} 
  
void LongestIncreasingSubsequence(vector<int> &arr, int n) 
{ 
    vector<int> tailIndices(n, 0); // Initialized with 0  
    vector<int> prevIndices(n, -1); // initialized with -1 
  
    int len = 1; // it will always point to empty location 
    for (int i = 1; i < n; i++) 
    { 
        if (arr[i] < arr[tailIndices[0]]) 
        { 
            // new smallest value 
            tailIndices[0] = i; 
        } 
        else if (arr[i] > arr[tailIndices[len-1]]) 
        { 
            // arr[i] wants to extend largest subsequence 
            prevIndices[i] = tailIndices[len-1]; 
            tailIndices[len++] = i; 
        } 
        else
        { 
            // arr[i] wants to be a potential condidate of 
            // future subsequence 
            // It will replace ceil value in tailIndices 
            int pos = GetCeilIndex(arr, tailIndices, -1, 
                                   len-1, arr[i]); 
  
            prevIndices[i] = tailIndices[pos-1]; 
            tailIndices[pos] = i; 
        } 
    } 
    myvector.clear();
    for (int i = tailIndices[len-1]; i >= 0; i = prevIndices[i]) 
        myvector.push_back(arr[i]);
}

int main(){
	srand(time(NULL));
	vector< vector<int> > v(100 , vector<int>(100,0)),arr;
	int x;
	vector<int> vect ;

// Create 100*100 matrix between range of 1 to 1000	
	for(int i = 0;i < v.size();i++){
		for(int j = 0;j < v[i].size();j++){
			x = rand() % 1000 + 1;
		    v[i][j] = x;
		}
	}
	
// Print randomly generated matrix
    cout << "Randomly generated 100*100 matrix is" << endl; 
	for(int i = 0;i < v.size();i++){
		for(int j = 0;j < v[i].size();j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	
// Check for 3*3 mask
    int row , col ;
    row = v.size()-2;
    col = row;
	for(int j = 0;j < col;j++){
	    for(int i = 0;i < row;i++){
	        // Store 3*3 mask in vector
	        vect.clear();
	        for(int k = i;k < i+3;k++){
	           for(int l = j;l < j+3;l++){
	               vect.push_back(v[k][l]);
	           }
	        }
	        cout << "Print 3*3 mask sequence i = " << i << " j = " << j << endl;
			for(int m = 0;m < vect.size();m++)
			    cout << vect[m] << " ";
			cout << endl;
			myvector.clear();
	        LongestIncreasingSubsequence(vect, vect.size());

	        if(myvector.size() == 9) {
	        	cout << "Mask Is Sorted" << endl;
	        }
	        else {
				cout << "Longest Increasing Subsequence with Size "  << myvector.size() << endl;
				for(int k = myvector.size()-1;k >= 0;k--) 
				    cout << myvector[k] << " ";
				cout << endl;
			} 
	    }
	}
	return 0;
}