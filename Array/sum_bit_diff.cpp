/*Sum of bit differences
Write a program to find the sum of bit differences in all pairs that can be formed from array elements n. 
Bit difference of a pair (x, y) is a count of different bits at same positions in binary representations of x and y. 
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).

Input: The first line of input contains an integer T denoting the number of test cases. 
First line of the test case will contain an array of elements n.
Output: The sum of bit differences of all pairs that can be formed by given array.

Example:

Input:

2
2 
1 2
3 
1 3 5

Output:

4
8
*/

#include <iostream>
using namespace std;

int find_sum(int arr[], int n)
{
    int count = 0;
    int sum = 0;
    
    for (int i = 0; i < 32; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if ((arr[j] & (1 << i))) {
                count++;
            }
        }
        
        sum += (count * (n - count) * 2);
    }
    
    return sum;
}

int main() 
{
	//code
	int T;
	int n;
	
	cin >> T;
	while (T--) {
	    cin >> n;
	    int arr[n];
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    int res = find_sum(arr, n);
	    cout << res << endl;
	}
	
	return 0;
}