#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_sum(int a, int b)
{
    int c;
    c = a^b;
    vector<int> diff;
    int count = 0;
    while (c > 0) {
        if ((c%2) == 0) {
            diff.push_back(0);
        }
        else {
            diff.push_back(1);
            count++;
        }
        c = c / 2;
    }
    return count;
}

int main() {
	//code
	int t;
	int n;
	//vector<int> v;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    int arr[n];
	    //int x;
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	        //v.push_back(x);
	    }
	    
	    int res = 0;
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; i < n; j++) {
	           res += find_sum(arr[i], arr[j]);
	        }
	    }
	    
	    cout << res << endl;
	}
	return 0;
}