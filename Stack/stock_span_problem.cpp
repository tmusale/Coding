/*Stock span problem

The stock span problem is a financial problem where we have a series of n daily price quotes 
for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number 
of consecutive days just before the given day, for which the price of the stock on 
the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, 
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Input:
The first line of input contains an integer T denoting the number of test cases. 
The first line of each test case is N, N is the size of the array. The second line of each test case contains N input C[i].

Output:
For each testcase, print the span values for all days.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 200
1 ≤ C[i] ≤ 800

Example:
Input:
2
7
100 80 60 70 60 75 85
6
10 4 5 90 120 80

Output:
1 1 1 2 1 4 6
1 1 2 4 5 1
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	int n;
	vector<int> v;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    int x;
	    
	    for (int i = 0; i < n; i++) {
	        cin >> x;
	        v.push_back(x);
	    }
	    
	    vector<int> res;
	    int max;
	    int cur_max = 0;
	    for (int i = 0; i < n; i++) {
	        max = 0;
	        cur_max = 0;
	        for (int j = 0; j <= i; j++) {
	            if (v[i] >= v[j]) {
	                cur_max++;
	            }
	            else {
	                /*if (cur_max > max) {
	                    max = cur_max;
	                }*/
	                cur_max = 0;
	            }
	        }
	        /*if (cur_max > max) {
	            max = cur_max;
	        }*/
	        res.push_back(cur_max);
	    }
	    
	    for (int i = 0; i < n; i++) {
	        cout << res[i] << " ";
	    }
	    cout << endl;
	    v.clear();
	    res.clear();
	}
	return 0;
}
