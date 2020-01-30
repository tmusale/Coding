/*
Largest subarray of 0's and 1's

Given an array of 0's and 1's your task is to complete the function maxLen which returns size of the largest sub array with equal 
number of 0's and 1's. The function maxLen takes 2 arguments. The first argument is the array A[] and second argument is the size 
'N' of the array A[].

Input:
The first line of the input is T denoting the number of test cases. Then T test cases follow . Each test case contains two lines. 
The first line of each test case is a number N denoting the size of the array and in the next line are N space separated values of A [].

Output:
For each test case output in a new line the max length of the subarray.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= A[] <= 1

Example:
Input 
2
4
0 1 0 1
5
0 0 1 0 0

Output
4
2

Explanation:
Testacase 1: The array from index [0...3] contains equal number of 0's and 1's. Thus maximum length of subarray having equal 
number of 0's and 1's is 4. 

*/

/*You are required to complete this method*/
int maxLen(int arr[], int n)
{
//Your code here
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            arr[i] = -1;
        }
    }
    
    unordered_map<int, int> mp;
    int sum[n];
    sum[0] = arr[0];
    
    mp[sum[0]] = 0;
    
    int len = 0;
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i-1] + arr[i];
        if (sum[i] == 0) {
            int size = i+1;
            if (len < size) {
                len = size;
            }
        }
        if (mp.find(sum[i]) != mp.end()) {
            int l = mp[sum[i]];
            int h = i;
            int size = h - l;
            if (len < size) {
                len = size;
            }
        }
        else {
            mp[sum[i]] = i;
        }
    }
    
    //cout << len << endl;
    
    return len;
}