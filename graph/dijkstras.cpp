/*
Implementing Dijkstra | Set 1 (Adjacency Matrix)
Given a graph of V nodes represented in the form of adjacency matrix. The task is to find the 
shortest distance of all the vertex's from the source vertex.

Input:
The first line of input contains an integer T denoting the number of test cases . Then T test cases follow .
The first line of each test case contains an integer V denoting the size of the adjacency matrix  and in the 
next line are V space separated values of the matrix (graph) . The third line of each test case contains an 
integer denoting the source vertex s.

Output:
For each test case output will be V space separated integers where the ith integer denote the shortest 
distance of ith vertex from source vertex.

You task:
You are required to complete the function dijkstra() which takes 3 arguments. The first argument is the 
adjacency matrix (graph), the second argument is the source vertex s and the third argument is V 
denoting the size of the matrix. The function prints  V space separated integers where i'th integer 
denotes the shortest distance of the i'th vertex from source vertex.

Constraints:
1 <= T <= 20 
1 <= V <= 20
0 <= graph[i][j] <= 1000
0 <= s

Example:
Input:
2
2
0 25 25 0
0
3
0 1 43 1 0 6 43 6 0
2

Output:
0 25
7 6 0

Explanation:
Testcase 1: Shortest distance of source node 0 to 1 is 25, and shortest distance of source to source is 0.
*/

/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

bool cmpbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    // Your code here
    unordered_map<int, int> mp;
    unordered_map<int, int> distance;
    unordered_map<int, int> path;
    
    for (int i = 0; i < V; i++) {
        mp[i] = 9999;
    }
    
    mp[src] = 0;
    //distance[src] = 0;
    //path[src] = -1;
    
    //mp.erase[src];
    
    //in
    while (mp.size() > 0) {
        auto it = std::min_element(mp.begin(), mp.end(), cmpbysec);
        int cur = (*it).first;
        int dist = (*it).second;
        //cout << dist << ' ';
        
        distance[cur] = dist;
        if (cur == src) {
            path[cur] = -1;
        }
        else {
            
        }
        mp.erase(cur);
        for (int i = 0; i < graph[cur].size(); i++) {
            //dijkstra()
            int temp = i;
            if (mp.find(temp) != mp.end()) {
                //continue;
                if (mp[temp] > distance[cur] + graph[cur][temp]) {
                    mp[temp] = distance[cur] + graph[cur][temp];
                }
                path[temp] = cur;
            }
            
        }
        
        
        
    }
    
    for (int j = 0; j < V; j++) {
        //cout << (*j).first << " " << (*j).second << " "<<endl;
        cout << distance[j] << " ";
    }
    
    //cout << endl;
}