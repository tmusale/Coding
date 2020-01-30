/*
Check if array contains contiguous integers with duplicates allowed

Given an array of n integers(duplicates allowed). Print “Yes” if it is a set of contiguous integers else print “No”.


INPUT: The first line consists of an integer T i.e. the number of test cases. 
First line of each test case consists of an integer n, denoting the size of array. 
Next line consists of n spaced integers, denoting elements of array.


OUTPUT:  Print “Yes” if it is a set of contiguous integers else print “No”.

 

CONSTRAINTS:
1<=T<=100
1<=n<100000
a[i]<=105

 Example:

 2
8
5  2  3  6  4  4  6  6
7
10  14  10  12  12  13  15

Output :
 Yes
 No

Explanation:
Test Case 1 : The elements  of array form a contiguous set of integers which is {2, 3, 4, 5, 6} so the output is Yes.
Test Case 2: We are unable to form contiguous set of integers using elements of array.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	int n;
	set<int> s;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    int arr[n];
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	        if (s.find(arr[i]) == s.end()) {
	            s.insert(arr[i]);
	        }
	    }
	    
	    int k = *(min_element(s.begin(), s.end()));
	    int flag = 1;
	    for (auto i = s.begin(); i != s.end(); i++) {
	        if ((*i) != k) {
	            flag = 0;
	            break;
	        }
	        k++;
	    }
	    flag ? cout <<"Yes" : cout <<"No";
	    cout << endl;
	    s.clear();
	}
	return 0;
}