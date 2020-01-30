/*
Longest consecutive subsequence

Given an array arr[] of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are 
consecutive integers, the consecutive numbers can be in any order.

Input Format:
The first line of input contains T, number of test cases. First line of line each test case contains a single integer N.
Next line contains N integer array.

Output Format:
Print the output of each test case in a seprate line.

Your Task:
This is a function problem. You only need to complete the function findLongestConseqSubseq that takes arr and n as parameters and retuns 
the length.

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= a[i] <= 105

Example:
Input:
2
7
2 6 1 9 4 5 3
7
1 9 3 10 4 20 2

Output:
6
4

Explanation:
Testcase 1:  The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.

Testcase2: 1, 2, 3, 4 is the longest consecutive subsequence.
*/


int findLongestConseqSubseq(int arr[], int n)
{
  //Your code here
  sort(arr, arr+n);
  
  int max = 1;
  
  int cur_max = 1;
  
  for (int i = 1; i <n; i++) {
      if (arr[i] == arr[i-1]+1) {
          cur_max++;
          if (cur_max > max) {
              max = cur_max;
          }
      }
      else {
          cur_max = 1;
      }
  }
  
  return max;
}