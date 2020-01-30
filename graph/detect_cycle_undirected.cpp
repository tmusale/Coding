/*
Detect cycle in an undirected graph

Given a undirected graph, the task is to complete the method isCyclic() to detect 
if there is a cycle in the undirected graph or not.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. 
Then 'T' testcases follow. Each testcase consists of two lines. Description of testcases are as follows: 
The First line of each testcase contains two integers 'N' and 'M' which denotes the no of vertices and 
no of edges respectively. The Second line of each test case contains 'M'  space separated pairs u and v 
denoting that there is a bidirectional  edge from u to v .

Output:
The method should return 1 if there is a cycle else it should return 0.

User task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function isCyclic.

Constraints:
1 <= T <= 100
1 <= N,M <= 100
0 <= u,v <=  N-1

Example:
Input:
3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
5 4
0 1 2 3 3 4 4 2

Output:
1
0
1

Explanation:
Testcase 1: In above first test case there is a graph with 2 vertices and 2 edges the first edge is 
from 0 to 1 and other edge is from 0 to 0 . 
Testcase 2: In the second test case there is a graph with 3 vertices and 3 edges from 0 to 1 , 1 to 2 and 2 to 3.


*/

bool isCyclicUtil(int v, vector<int> adj[], vector<bool> &visited, int parent)
{
    visited[v] = true;
    
    
    for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
        if (!visited[*i]) {
            if (isCyclicUtil(*i, adj, visited, v)) {
                return true;
            }
        }
        
        else if (*i != parent) {
            return true;
        }
    }
    
    
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   vector<bool> visited(V, false);
   
   for (int i = 0; i < V; i++) {
       if (!visited[i]) {
           if (isCyclicUtil(i, adj, visited, -1)) {
               return true;
           }
       }
   }
   
   return false;
   
}