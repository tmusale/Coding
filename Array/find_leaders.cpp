/*
Given an array of positive integers. Your task is to find the leaders in the array.
Note: An element of array is leader if it is greater than or equal to all the elements to its right side. 
Also, the rightmost element is always a leader. 

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print all the leaders.

Example:
Input:
3
6
16 17 4 3 5 2
5
1 2 3 4 0
5
7 4 5 7 3
Output:
17 5 2
4 0
7 7 3
*/

#include <iostream>
#include <vector>
using namespace std;

void find_leaders(vector<int> v, int n)
{
    int leader = v[n-1];
    vector<int> l;
    l.push_back(v[n-1]);
    //cout << v[n-1] << " ";
    for (int i = n-2; i >= 0; i--) {
        if (v[i] >= leader) {
            //cout << v[i] << " ";
            l.push_back(v[i]);
            leader = v[i];
        }
    }
    //cout << v[n-1] << endl;
    for (auto i = l.rbegin(); i != l.rend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

int main() 
{
	//code
	int T;
	int n;
	int x;
	
	vector<int> v;
	
	cin >> T;
	while (T--) {
	    cin >> n;
	    for (int i = 0; i < n; i++) {
	        cin >> x;
	        v.push_back(x);
	    }
	    
	    find_leaders(v, n);
	    
	    v.clear();
	}
	
	return 0;
}