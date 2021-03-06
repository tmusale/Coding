/*
Activity Selection
Given N activities with their start and finish times. Select the maximum number of 
activities that can be performed by a single person, assuming that a person can only 
work on a single activity at a time.

Note : The start time and end time of two activities may coincide.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. 
First line is N number of activities then second line contains N numbers which are starting time of activies.
Third line contains N finishing time of activities.

Output:
For each test case, output a single number denoting maximum activites which can be performed in new line.

Constraints:
1<=T<=50
1<=N<=1000
1<=A[i]<=100

Example:
Input:
2
6
1 3 2 5 8 5
2 4 6 7 9 9
4
1 3 2 5
2 4 3 6

Output:
4
4
*/

#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main() {
	//code
	int t;
	int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    int arrs[n];
	    int arrf[n];
	    
	    vector< pair<int, int>> v;
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arrs[i];
	    }
	    
	    for (int i = 0; i  < n; i++) {
	        cin >> arrf[i];
	        
	        v.push_back(make_pair(arrs[i], arrf[i]));
	    }
	    
	    sort(v.begin(), v.end(), sortbysec);
	    
	    int i = 0;
	    int count = 1;
	    
	    for (int j = 1; j < n; j++) {
	        if (v[j].first >= v[i].second) {
	            count++;
	            i = j;
	        }
	    }
	    
	    cout << count << endl;
	}
	return 0;
}