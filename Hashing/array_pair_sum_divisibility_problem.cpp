/*
Array Pair Sum Divisibility Problem

Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of 
every pair is divisible by k.

Input:
The first line of input contains an integer T denoting the number of test cases. The T test cases follow. Each test case contains an integer 
n denoting the size of the array. The next line contains the n space separated integers forming the array. The last line contains the value 
of k.

Output:
Print "True" (without quotes) if given array can be divided into pairs such that sum of every pair is divisible by k or else "False" 
(without quotes).

Constraints:
1<=T<=100
2<=n<=10^5
1<=a[i]<=10^5
1<=k<=10^5

Example:
Input:
2
4
9 7 5 3
6
4
91 74 66 48
10

Output:
True
False
*/

#include <bits/stdc++.h>
using namespace std;

bool check_divisibility(int arr[], int n, int k)
{
    if ((n%2) != 0) {
        return false;
    }
    
    map<int, int> hash;
    
    for (int i = 0;i < n; i++) {
        hash[arr[i]%k]++;
    }
    
    for (int i = 0; i < n; i++) {
        int rem = arr[i]%k;
        
        if (2*rem == k) {
            if ((hash[rem]%2) != 0) {
                return false;
            }
        }
        else if (rem == 0) {
            if ((hash[rem]%2) != 0) {
                return false;
            }
        }
        
        else if (hash[rem] != hash[k-rem]) {
            return false;
        }
    }
    
    return true;
}

int main() {
	//code
	int t;
	int n;
	int k;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    int arr[n];
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    cin >> k;
	    
	    if (check_divisibility(arr, n, k)) {
	        cout << "True";
	    }
	    else {
	        cout << "False";
	    }
	    cout << endl;
	}
	return 0;
}