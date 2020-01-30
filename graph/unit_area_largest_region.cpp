/*
Unit Area of largest region of 1's

Consider a matrix with N rows and M columns, where each cell contains either a ‘0’ or a ‘1’ 
and any cell containing a 1 is called a filled cell. Two cells are said to be connected if 
they are adjacent to each other horizontally, vertically, or diagonally. If one or more 
filled cells are connected, they form a region. The task is to find the unit area of the largest region.

Input:
The first line of input will be the number of testcases T, then T testcases follow. 
The first line of each testcase contains 2 space separated integers n and m. Then in 
the next line are the n x m inputs of the matrix A separated by space.

Output:
The output in the expected output will be the length of the largest region formed.

Constraints:
1 <= T <= 100
1 <= N, M <= 50
0 <= A[][] <= 1

Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1

Output:
4
3

Explanation:
Testcase 1: Matrix can be shown as follows:
1 1 0
0 0 1
1 0 1

Largest region of 1s in the above matrix is with total 6 1s (colored in Red).
*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> A[], int n, int m, vector<int> visited[], int i, int j)
{
    return ((i >= 0) && (i < n) && (j >= 0) && (j < m) && (A[i][j] && !visited[i][j]));
}

void dfs(vector<int> A[], int n, int m, vector<int> visited[], int i, int j, int *count)
{
    visited[i][j] = 1;
    (*count)++;
    
    if (isSafe(A, n, m, visited, i-1, j-1)) {
        //(*count)++;
        dfs(A, n, m, visited, i-1, j-1, count);
    }
    
    if (isSafe(A, n, m, visited, i-1, j+1)) {
        //(*count)++;
        dfs(A, n, m, visited, i-1, j+1, count);
    }
    
    if (isSafe(A, n, m, visited, i-1, j)) {
        //(*count)++;
        dfs(A, n, m, visited, i-1, j, count);
    }
    
    if (isSafe(A, n, m, visited, i, j-1)) {
        //(*count)++;
        dfs(A, n, m, visited, i, j-1, count);
    }
    
    if (isSafe(A, n, m, visited, i, j+1)) {
        //(*count)++;
        dfs(A, n, m, visited, i, j+1, count);
    }
    
    if (isSafe(A, n, m, visited, i+1, j-1)) {
        //(*count)++;
        dfs(A, n, m, visited, i+1, j-1, count);
    }
    
    if (isSafe(A, n, m, visited, i+1, j)) {
        //(*count)++;
        dfs(A, n, m, visited, i+1, j, count);
    }
    
    if (isSafe(A, n, m, visited, i+1, j+1)) {
        //(*count)++;
        dfs(A, n, m, visited, i+1, j+1, count);
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
	    
	    vector<int> A[n];
	    vector<int> visited[n];
	    
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < m; j++) {
	            int x;
	            cin >> x;
	            A[i].push_back(x);
	            visited[i].push_back(0);
	        }
	    }
	    int max_count = -1;
	    int count = 0;
	    for (int i = 0; i < n; i++) {
	        
	        for (int j = 0; j < m; j++) {
	            
	            if (A[i][j] && !visited[i][j]) {
	                dfs(A, n, m, visited, i, j, &count);
	                if (count > max_count) {
	                    max_count = count;
	                }
	                count = 0;
	            }
	        }
	    }
	    
	    cout << max_count << endl;
	}
	return 0;
}