/*
Swapping pairs make sum equal

Given two arrays of integers, write a program to check if a pair of values (one value from each array)
 exists such that swapping the elements of the pair will make the sum of two arrays equal.

Input:
First line of input contains a single integer T which denotes the number of test cases. T test cases follows. 
First line of each test case contains two space separated integers N and M. Second line of each test case 
contains N space separated integers denoting the elements of first array. Third line of each test case contains 
M space separated integers denoting the elements of second array.

Output:
For each test case, print 1 if there exists any such pair otherwise print -1.

Constraints:
1 <= T <= 100
1 <= N <= 104
1 <= M <= 104
0 <= elements <= 104

Example:
Input:
2
6 4
4 1 2 1 1 2
3 6 3 3
4 4
5 7 4 6
1 2 3 8

Output:
1
1

Explanation:
Testcase 1: 1 and 3 are two such values one from first array other from second one, 
if we swap these two values then we will get both arrays sum as equal.

idea = 
sum1 - x + y = sum2 - y + x
2(y - x) = sum1 - sum2
2(y - x) =  diff
y = x + (diff/2)
OR
x = y - (diff/2)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	int n;
	int m;
	
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        int arr1[n];
        int arr2[m];
        
        int sum1 = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
            sum1 += arr1[i];
        }
        
        int sum2 = 0;
        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
            sum2 += arr2[i];
        }
        
        int diff = (sum1-sum2)/2;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < m; i++) {
            mp[arr2[i]]++;
        }
        
        int flag = 0;
        
        for (int i = 0; i < n; i++) {
            if (mp.find(arr1[i] - diff) != mp.end()) {
                flag = 1;
                break;
            }
        }
        
        if (flag) {
            cout << "1" << endl;
        }
        else {
            cout << "-1" << endl;
        }
        
    }
	return 0;
}