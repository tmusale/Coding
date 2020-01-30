/*
Find the number of islands

A group of connected 1's forms an island. The task is to complete the method findIslands() 
which returns the number of islands present. The function takes three arguments the first is 
the boolean matrix A and then the next two arguments are N and M denoting the size(N*M) of the matrix A .

Input:
The first line of input will be the number of testcases T, then T test cases follow. 
The first line of each testcase contains two space separated integers N and M. Then in the 
next line are the NxM inputs of the matrix A separated by space .

Output:
For each testcase in a new line, print the number of islands present.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function findIslands().

Constraints:
1 <= T <= 100
1 <= N, M <= 50
0 <= A[i][j] <= 1

Example(To be used only for expected output) :
Input
2
3 3
1 1 0 0 0 1 1 0 1
4 4
1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0

Output
2
2

Explanation:
Testcase 1: The graph will look like
1 1 0
0 0 1
1 0 1
Here, two islands will be formed
First island will be formed by elements {A[0][0] ,  A[0][1], A[1][2], A[2][2]}
Second island will be formed by {A[2][0]}.
*/

bool isSafe(vector<int> A[],int N, int M, vector<int> visited[], int i, int j)
{
    return ((i >= 0) && (i < N) && (j >= 0) && (j < M) && (A[i][j] && !visited[i][j]));
}


void dfs(vector<int> A[], int N, int M, vector<int> visited[], int i, int j)
{
    visited[i][j] = 1;
    
    if (isSafe(A,N, M, visited, i-1, j-1)) {
        dfs(A, N, M, visited, i-1, j-1);
    }
    
    if (isSafe(A, N, M, visited, i-1, j+1)) {
        dfs(A, N, M, visited, i-1, j+1);
    }
    
    if (isSafe(A, N, M, visited, i, j-1)) {
        dfs(A, N, M, visited, i, j-1);
    }
    
    if (isSafe(A, N, M, visited, i, j+1)) {
        dfs(A, N, M, visited, i, j+1);
    }
    
    if (isSafe(A, N, M, visited, i-1, j)) {
        dfs(A, N, M, visited, i-1, j);
    }
    
    if (isSafe(A, N, M, visited, i+1, j-1)) {
        dfs(A, N, M, visited, i+1, j-1);
    }
    
    if (isSafe(A, N, M, visited, i+1, j)) {
        dfs(A, N, M, visited, i+1, j);
    }
    
    if (isSafe(A, N, M, visited, i+1, j+1)) {
        dfs(A, N, M, visited, i+1, j+1);
    }
    
    
    
    
}

int findIslands(vector<int> A[], int N, int M)
{
    
    // Your code here
    vector<int> visited[N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            //visited[i][j] = 0;
            visited[i].push_back(0);
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        
        for (int j = 0; j < M; j++) {
            
            if (A[i][j] && !visited[i][j]) {
                dfs(A, N, M, visited, i, j);
                
                count++;
            }
        }
    }
    
    return count;
    
}
