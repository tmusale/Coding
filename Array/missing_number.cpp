/*Missing number in array
Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.

Input:
The first line of input contains an integer T denoting the number of test cases. For each 
test case first line contains N(size of array). The subsequent line contains N-1 array elements.

Output:
Print the missing number in array.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ C[i] ≤ 107

Example:
Input:
2
5
1 2 3 5
10
1 2 3 4 5 6 7 8 10

Output:
4
9

Explanation:
Testcase 1: Given array : 1 2 3 5. Missing element is 4.
*/

#include <bits/stdc++.h>
using namespace std;

void missing_number(int arr[], int n)
{
    //sort(arr, arr+n);
    vector<int> v(n+2, 0);
    int k = 1;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        v[arr[i]] = 1;
    }
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == 0) {
            cout << i;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        //cout << n+1;
    }
}

int main() {
	//code
	int t;
	int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    n = n-1;
	    int arr[n];
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    missing_number(arr, n);
	    cout << endl;
	}
	return 0;
}