/*
Count distinct elements in every window
Given an array A[] of size N and an integer K. Your task is to complete the function countDistinct() which prints the count of distinct 
numbers in all windows of size k in the array A[].

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two 
integers N and K. Then in the next line are N space separated values of the array A[].

Output:
For each test case in a new line print the space separated values denoting counts of distinct numbers in all windows of size k in the 
array A[].

Constraints:
1 <= T <= 100
1 <= N, K <= 100
1 <= A[] <= 100

Example(To be used only for expected output):
Input:
2
7 4
1 2 1 3 4 2 3
3 2
4 1 1

Output:
3 4 4 3
2 1
*/

/*You are required to complete below method */


void countDistinct(int A[], int k, int n)
{
    //Your code here
    unordered_map<int, int> hash;
    deque<int> dq;
    
    for (int i = 0; i < k; i++) {
        dq.push_back(A[i]);
        hash[A[i]]++;
    }
    int count = 0;
    count = hash.size();
    cout << count << " ";
    
    for (int i = k; i < n; i++) {
        int temp = dq.front();
        dq.pop_front();
        hash[temp]--;
        if (hash[temp] == 0) {
            hash.erase(temp);
        }
        dq.push_back(A[i]);
        hash[A[i]]++;
        count = hash.size();
        cout << count << " ";
    }
    
}

/*
method 2 :=


int distinct(int arr[], int n)
{
    set<int> s;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s.find(arr[i]) == s.end()) {
            s.insert(arr[i]);
            count++;
        }
    }
    s.clear();
    
    return count;
}

void countDistinct(int A[], int k, int n)
{
    //Your code here
    int count;
    set<int> s;
    
    for (int i = 0; i <= n-k; i++) {
        int res = distinct(A+i, k);
        cout << res << " ";
    }
    
    //cout << endl;
}
*/