/*
Topological sort
Given a directed graph, you need to complete the function topoSort which returns an array having the 
topologically sorted elements of the array and takes two arguments. The first argument is the 
Graph graph represented as adjacency list and the second is the number of vertices N.

Note : There can be multiple topological sorts of a Graph.  The driver program that calls your 
function doesn't match your output element by element, but checks whether the output produced by 
your function is a valid topological sort or not.

Input:
The first line of input takes the number of test cases then T test cases follow . Each test case 
contains two lines. The first  line of each test case  contains two integers E and N representing 
no of edges and the number of vertices. Then in the next line are E  pairs of integers u, v 
representing an edge from u to v in the graph.

Output:
For each test case output will be 1 if the topological sort is done correctly else it will be 0 .

Constraints:
1 <= T <= 50
1 <= E, N <= 50
0 <= u, v

Example:
Input
2
6 6 
5 0 5 2 2 3 4 0 4 1 1 3
4 4
3 0 1 0 2 0 0 1

Output:
1
0

Explanation:
Testcase 1: The output 1 denotes that the order is valid.  So, if you have implemented your 
function correctly, then output would be 1 for all test cases.
*/

// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array 
*/

void dfs(int v, vector<int> adj[], vector<bool> &visited, stack<int> &s) 
{
    visited[v] = true;
    
    for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
        if (!visited[*i]) {
            dfs(*i, adj, visited, s);
        }
    }
    
    s.push(v);
}

int* topoSort(int V, vector<int> adj[])
{
    // Your code here
    vector<bool> visited(V, false);
    
    stack<int> s;
    int *arr = (int *)malloc(sizeof(int) * V);
    
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, s);
        }
    }
    
    int j = 0;
    while (!s.empty()) {
        //cout << s.top() << " ";
        arr[j++] = s.top();
        s.pop();
    }
    
    return arr;
}
