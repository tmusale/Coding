/*
Nearly Sorted Algorithm

Given an array of n elements, where each element is at most k away from its target position. 
The task is to print array in sorted form.

Input:
First line consists of T test cases. First line of every test case consists of two integers N and K, 
denoting number of elements in array and at most k positions away from its target position respectively. 
Second line of every test case consists of elements of array.

Output:
Single line output to print the sorted array.

Constraints:
1<=T<=100
1<=N<=100
1<=K<=N

Example:
Input:
2
3 3
2 1 3
6 3
2 6 3 12 56 8
Output:
1 2 3
2 3 6 8 12 56
*/

#include <bits/stdc++.h>
using namespace std;

void sortk(int arr[], int n, int k)
{
     priority_queue<int, vector<int>, greater<int>> pq(arr, arr+k+1);
     
     int index = 0;
     
     for (int i = k+1; i < n; i++) {
         arr[index++] = pq.top();
         pq.pop();
         pq.push(arr[i]);
     }
     
     while (!pq.empty()) {
         arr[index++] = pq.top();
         pq.pop();
     }
     
     for (int i = 0; i < n; i++) {
         cout << arr[i] << " ";
     }
}

int main() {
	//code
	
	int t;
	int n;
	int k;
	
	cin >> t;
	while (t--) {
	    cin >> n >> k;
	    int arr[n];
	    
	    priority_queue<int, vector<int>, greater<int>> pq;
	    int x;
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	        pq.push(arr[i]);
	    }
	    
	    while (!pq.empty()) {
	        cout << pq.top() << " ";
	        pq.pop();
	    }
	    //sortk(arr, n, k);
	    cout << endl;
	}
	return 0;
}