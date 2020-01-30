/*
Flood fill Algorithm

Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of the given pixel and all 
adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

Example:

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 2, 2, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 2, 2, 0},
{1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 2, 2, 1},
 };

 x=4, y=4, color=3 

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1}, 
{1, 3, 3, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 3, 3, 0},
{1, 1, 1, 1, 1, 3, 1, 1},
{1, 1, 1, 1, 1, 3, 3, 1}, };

Note: Use zero based indexing.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case 
contains Two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix. Then in 
the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1 <= T <= 100
1 <= M[][] <= 100

Example:
Input:
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4 
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9

Output:
0 5 5 0 5 5 5 5 0 5 2 3
8 8 8 8
1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4
*/

#include <bits/stdc++.h>
using namespace std;

bool issafe(vector<int> mat[], int i, int j, int k, int N, int M, int temp)
{
    return ((i >= 0) && (i < N) && (j >= 0) && (j < M) && (mat[i][j] == temp));
}

void flood(vector<int> mat[], int x, int y, int k, int N, int M, int temp)
{
    //int temp;
    if (x >= 0 && x < N && y >= 0 && y < M) {
        temp = mat[x][y];
        mat[x][y] = k;
    }
    
    if (issafe(mat, x-1, y, k, N, M, temp)) {
        flood(mat, x-1, y, k, N, M, temp);
    }
    
    if (issafe(mat, x, y-1, k, N, M, temp)) {
        flood(mat, x, y-1, k, N, M, temp);
    }
    
    if (issafe(mat, x, y+1, k, N, M, temp)) {
        flood(mat, x, y+1, k, N, M, temp);
    }
    
    if (issafe(mat, x+1, y, k, N, M, temp)) {
        flood(mat, x+1, y, k, N, M, temp);
    }
    
}

int main() {
	//code
	int t;
	int N;
	int M;
	int x;
	int y;
	int k;
	
	cin >> t;
	while (t--) {
	    cin >> N;
	    cin >> M;
	    
	    //int 
	    
	    vector<int> mat[N];
	    
	    for (int i = 0; i < N; i++) {
	        
	        for (int j = 0; j < M; j++) {
	            int a;
	            cin >> a;
	            mat[i].push_back(a);
	        }
	    }
	    
	    cin >> x;
	    cin >> y;
	    cin >> k;
	    
	    flood(mat, x, y, k, N, M, mat[x][y]);
	    
	    for (int i = 0; i < N; i++) {
	        for (int j = 0; j < M; j++) {
	            cout << mat[i][j] << " ";
	        }
	    }
	    
	    cout << endl;
	}
	return 0;
}