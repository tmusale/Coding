/*
Transitive closure of a Graph
Given a directed graph, find out if a vertex j is reachable from another vertex i for all 
vertex pairs (i, j) in the given graph. Here reachable mean that there is a path from vertex i to j. 
The reach-ability matrix is called transitive closure of a graph.

Input:
First line consists of T test cases. First line of every test case consists of N , denoting number of vertices. 
Second line consists of N*N spaced integer(Only 0 and 1), denoting the edge b/w i to j.

Output:
Single line output, print the trasitive closure formed of graph.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
1
4
1 1 0 1 0 1 1 0 0 0 1 1 0 0 0 1
Output:
1 1 1 1 0 1 1 1 0 0 1 1 0 0 0 1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	int N;
	int max = INT_MAX;
	
	cin >> t;
	while (t--) {
	    cin >> N;
	    vector<int> adj[N];
	    
	    for (int i = 0; i < N; i++) {
	        
	        for (int j = 0; j < N; j++) {
	            int a;
	            cin >> a;
	            
	            adj[i].push_back(a);
	            
	        }
	    }
	    
	    for (int k = 0; k < N; k++) {
	        
	        for (int i = 0; i < N; i++) {
	            
	            for (int j = 0; j < N; j++) {
	                //adj[i][j] = min(adj[i][k]+adj[k][j], adj[i][j]);
	                if((adj[i][j] == 0 && adj[i][k] == 1 && adj[k][j] == 1) || i == j) {
	                    adj[i][j] = 1;
	                }
	            }
	        }
	    }
	    
	    for (int i = 0; i < N; i++) {
	        for (int j= 0; j < N; j++) {
	            
	            cout << adj[i][j] << " ";
	        }
	    }
	    
	    cout << endl;
	}
	return 0;
}