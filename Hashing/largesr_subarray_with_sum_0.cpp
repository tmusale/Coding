/*
Largest subarray with 0 sum
Given an array having both positive an negative integers. The task is to complete the function maxLen() which returns the length of maximum 
subarray with 0 sum. The function takes two arguments an array A and n where n is the size of the array A.

Input:
The first line of input contains an element T denoting the number of test cases. Then T test cases follow. Each test case consist of 2 lines. 
The first line of each test case contains a number denoting the size of the array A. Then in the next line are space separated values of 
the array A.

Output:
For each test case output will be the length of the largest subarray which has sum 0.

User Task:
Sinec this is a functional problem you don't have to worry about input, you just have to complete the function maxLen().

Constraints:
1 <= T <= 100
1 <= N <= 100
-1000 <= A[] <= 1000

Example:
Input
1
8
15 -2 2 -8 1 7 10 23

Output
5

Explanation
Testcase 1: In the above test case the largest subarray with sum 0 will be -2 2 -8 1 7.
*/

/*You are required to complete this function*/
int maxLen(int A[],int n)
{
  //Your code here
  unordered_map<int, int> hash;
  int sum[n];
  sum[0] = A[0];
  hash[sum[0]] = 0;
  int max = 0;
  for (int i = 1;i < n; i++) {
      sum[i] = sum[i-1] + A[i];
      if (sum[i] == 0) {
          int start = 0;
          int end = i;
          int len = end - start + 1;
          if (max < len) {
              max = len;
          }
      }
      if (hash.find(sum[i]) != hash.end()) {
          int start = hash[sum[i]] + 1;
          int end = i;
          int len = end - start + 1;
          if (max < len) {
              max = len;
          }
      } 
      else {
        hash[sum[i]] = i;
      }
      
  }
  
  return max;
  
}
