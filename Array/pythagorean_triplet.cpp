/*
Pythagorean Triplet

Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

Input:
The first line contains T, denoting the number of testcases. Then follows description of testcases. 
Each case begins with a single positive integer N denoting the size of array. The second line contains 
the N space separated positive integers denoting the elements of array A.

Output:
For each testcase, print "Yes" or  "No" whether it is Pythagorean Triplet or not (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= A[i] <= 1000

Example:
Input:
1
5
3 2 4 6 5

Output:
Yes

Explanation:
Testcase 1: a=3, b=4, and c=5 forms a pythagorean triplet, so we print "Yes"
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool find_triplet(int arr[], int n)
{
    sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i]*arr[i];
    }
    
    for (int i = n-1; i >= 0; i--) {
        int l = 0;
        int h = i-1;
        
        while (l < h) {
            int temp = arr[l] + arr[h];
            if (temp == arr[i]) {
                return true;
            }
            
            (arr[l]+arr[h] < arr[i])? l++ : h--;
        }
    }
    
    return false;
}

int main() {
	//code
	int T;
	int n;
	
	cin >> T;
	while (T--) {
	    cin >> n;
	    int arr[n];
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    bool res = find_triplet(arr, n);
	    if (res) {
	        cout << "Yes";
	    }
	    else {
	        cout << "No";
	    }
	    cout << endl;
	}
	return 0;
}