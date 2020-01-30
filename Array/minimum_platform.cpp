
/*
Minimum Platforms

Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number of  
platforms required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave on the same day. Also, arrival and departure times will 
not be same for a train, but we can have arrival time of one train equal to departure of the other.

In such cases, we need different platforms, i.e at any given instance of time, same platform can not be used for both 
departure of a train and arrival of another.

Input:
The first line of input contains T, the number of test cases. For each test case, first line will contain an integer N, 
the number of trains. Next two lines will consist of N space separated time intervals denoting arrival and departure times respectively.
Note: Time intervals are in the 24-hour format(hhmm),  of the for HHMM , where the first two charcters represent hour 
(between 00 to 23 ) and last two characters represent minutes (between 00 to 59).

Output:
For each test case, print the minimum number of platforms required for the trains to arrive and depart safely.

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= A[i] < D[i] <= 2359

Example:
Input:
2
6 
0900  0940 0950  1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240 

Output:
3
1

Explanation:
Testcase 1: Minimum 3 platforms are required to safely arrive and depart all trains.
*/

#include <bits/stdc++.h>
using namespace std;

int find_platform(int arr[], int dep[], int n)
{
    int plat_needed = 1;
    int max_plat = 1;
    
    sort(arr, arr+n);
    sort(dep, dep+n);
    
    int i = 1;
    int j = 0;
    
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
            
            if (max_plat < plat_needed) {
                max_plat = plat_needed;
            }
        }
        else {
            plat_needed--;
            j++;
        }
    }
    
    return max_plat;
}

int main() {
	//code
	int t;
	int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    int arr[n];
	    int dep[n];
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    for (int i = 0; i < n; i++) {
	        cin >> dep[i];
	    }
	    
	    cout << find_platform(arr, dep, n) << endl;
	}
	return 0;
}