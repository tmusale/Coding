/*
Common elements
Given three increasingly sorted arrays A, B, C of sizes N1, N2, and N3 respectively, you need to print all common elements in these arrays.

Note: Please avoid printing the same common element more than once.

Input:
First line contains a single integer T denoting the total number of test cases. T testcases follow. Each testcase contains four lines of 
input. First line consists of 3 integers N1, N2 and N3, denoting the sizes of arrays A, B, C respectively. The second line contains N1 
elements of A array. The third lines contains N2 elements of B array. The fourth lines contains N3 elements of C array.

Output:
For each testcase, print the common elements of array. If not possible then print -1.

Constraints:
1 <= T <= 100
1 <= N1, N2, N3 <= 107
1 <= Ai, Bi, Ci <= 1018

Example:
Input:
1
6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120
Output:
20 80

Explanation:
Testcase1:  20 and 80 are the only common elements
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	int n1;
	int n2;
	int n3;
	
	cin >> t;
	while (t--) {
	    cin >> n1 >> n2 >> n3;
	    
	    int A[n1];
	    int B[n2];
	    int C[n3];
	    
	    for (int i = 0; i < n1; i++) {
	        cin >> A[i];
	    }
	    for (int i = 0; i < n2; i++) {
	        cin >> B[i];
	    }
	    for (int i = 0; i < n3; i++) {
	        cin >> C[i];
	    }
	    
	    map<int, int> hash;
	    hash[A[0]]++;
	    
	    for (int i = 1; i < n1; i++) {
	        if (A[i] != A[i-1]) {
	            hash[A[i]]++;
	        }
	    }
	    
	    hash[B[0]]++;
	    
	    for (int i = 1; i < n2; i++) {
	        if (B[i] != B[i-1]) {
	            hash[B[i]]++;
	        }
	    }
	    
	    hash[C[0]]++;
	    for (int i = 1; i< n3; i++) {
	        if (C[i] != C[i-1]) {
	            hash[C[i]]++;
	        }
	    }
	    
	    int flag = 0;
	    for (auto i = hash.begin(); i != hash.end(); i++) {
	        if ((*i).second >= 3) {
	            cout << (*i).first << " ";
	            flag = 1;
 	        }
	    }
	    
	    if (flag == 0) {
	        cout << -1;
	    }
	    
	    cout << endl;
	}
	return 0;
}