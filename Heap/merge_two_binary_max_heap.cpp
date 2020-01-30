/*
Merge two binary Max heaps
Given two binary max heaps as arrays, merge the given heaps, after merging the two arrays.
The task is very simple to merge the two arrays firstly keep all the elements of first array 
than elements second array, than apply the merge operation of heaps.

Input:
First line consists of T test cases. First line of every test case consists of 2 integers N and M, 
denoting the number elements of two arrays (MAX HEAP). Second and third line of every test cases consists of elements of 2 Heaps respectively.

Output:
Single line output, print the merged max heap.

Constraints:
1<=T<=100
1<=N,M<=100

Example:
Input:
1
4 3
10 5 6 2
12 7 9
Output:
12 10 9 2 5 7 6 
*/

#include <bits/stdc++.h>
using namespace std;


void heapify(vector<int> &arr, int n, int i)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int large = i;
    
    if (l < n && arr[l] > arr[i]) {
        large = l;
    }
    if (r < n && arr[r] > arr[large]) {
        large = r;
    }
    
    if (large != i) {
        swap(arr[large], arr[i]);
        heapify(arr, n, large);
    }
}

int main() {
	//code
	int t;
	int n;
	int m;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    cin >> m;
	    
	    vector<int> v;
	    int x;
	    //int arr[m];
	    
	    for(int i = 0; i < n; i++) {
	        cin >> x;
	        v.push_back(x);
	    }
	    
	    for (int i = v.size()-1; i >= 0; i--) {
	        //heapify(v, n, i);
	    }
	    
	    for (int i = 0; i < m; i++) {
	        cin >> x;
	        v.push_back(x);
	        //heapify(v, n+1+i, v.size()+i);
	    }
	    
	    for (int i = v.size()-1; i >= 0; i--) {
	        heapify(v, v.size(), i);
	    }
	    
	    for (auto i = v.begin(); i != v.end(); i++) {
	        cout << *i << " ";
	    }
	    cout << endl;
	}
	return 0;
}