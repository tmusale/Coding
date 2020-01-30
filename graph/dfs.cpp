/*
DFS of Graph
Given N nodes and E edges of a graph. The task is to do depth first traversal of the graph.

Note: Use recursive approach.

Input:
First line of input contains number of testcases T. For each testcase. First line of 
each testcase contains number of nodes and edges seperated by space and next line contains 
N pairs of integers (X and Y each) where X Y means an edge from X to Y.

Output:
For each testcase, print the nodes while doing DFS starting from node 0.

Your task:
The task is to complete the function dfs() which should do the depth first traversal of given graph and prints the node in DFS order.

Constraints:
1 <= T <= 100
1 <= N <= 500

Example:
Input:
2
5 4
0 1 0 2 0 3 2 4
4 3
0 1 1 2 0 3

Output:
0 1 2 4 3    // dfs from node 0
0 1 2 3

Explanation:
Testcase 1: There is  one test cases.  First line of each test case represent an integer 
N denoting number of edges and then in the next line N pairs of values a and b are fed which denotes there is an edge from a to b.
*/

void dfs(int s, vector<int> g[], bool vis[])
{
    
    // Your code here
    //DFSUtil()
    
    vis[s] = true;
    cout << s << " ";
    
    for (auto i = g[s].begin(); i != g[s].end(); i++) {
        if (!vis[*i]) {
            dfs(*i, g, vis);
        }
    }
    
}