/*
Rearrange Array Alternately

Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e 
first element should be max value, second should be min value, third should be second max, fourth should be second min and so on...

Note: O(1) extra space is allowed. Also, try to modify the input array as required.

Input:
First line of input conatins number of test cases T. First line of test case contain an integer denoting the array 
size N and second line of test case contain N space separated integers denoting the array elements.

Output:
Output the modified array with alternated elements.

Constraints:
1 <=T<= 100
1 <=N<= 107
1 <=arr[i]<= 107

Example: 
Input:
2
6
1 2 3 4 5 6
11 
10 20 30 40 50 60 70 80 90 100 110

Output:
6 1 5 2 4 3
110 10 100 20 90 30 80 40 70 50 60

Explanation:
Testcase 1: Max element = 6, min = 1, second max = 5, second min = 2, and so on... Modified array is : 6 1 5 2 4 3.
 
*/


#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void rearrange(lli arr[], lli n)
{
    lli max_idx = n-1;
    lli min_idx = 0;
    lli max_ele = arr[max_idx] + 1;
    
    for (lli i = 0; i < n; i++) {
        if ((i%2) == 0) {
            arr[i] += (arr[max_idx] % max_ele) * max_ele;
            max_idx--;
        }
        else {
            arr[i] += (arr[min_idx] % max_ele) * max_ele;
            min_idx++;
        }
    }
    
    for (lli i = 0; i < n; i++) {
	        cout << arr[i] / max_ele << " ";
	}
}

int main() {
	//code
	int t;
	lli n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    lli arr[n];
	    
	    for (lli i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    rearrange(arr, n);
	    
	    
	    cout << endl;
	}
	return 0;
}