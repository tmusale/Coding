/*
Longest Common Prefix in an Array

Given a array of N strings, find the longest common prefix among all strings present in the array.

Input:
The first line of the input contains an integer T which denotes the number of test cases to follow. 
Each test case contains an integer N. Next line has space separated N strings.

Output:
Print the longest common prefix as a string in the given array. If no such prefix exists print "-1"(without quotes).

Constraints:
1 <= T <= 103
1 <= N <= 103
1 <= |S| <= 103

Example:
Input:
2
4
geeksforgeeks geeks geek geezer
3
apple ape april

Output:
gee
ap

Explanation:
Testcase 1: Longest common prefix in all the given string is gee.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void longest_prefixes(string arr[], int n)
{
    int len[n];
    vector<char> prefix;
    int min = arr[0].size();
    
    for (int i = 0; i < n; i++) {
        int temp_min = arr[i].size();
        if (min > temp_min) {
            min = temp_min;
        }
    }
    
    //cout << min << endl;
    //int min = *min_element(len, len+n);
    int flag = 0;
    char temp;
    
    for (int i = 0; i < min; i++) {
        temp = arr[0][i];
        for (int j = 0; j < n; j++) {
            
            if (temp == arr[j][i]) {
                flag = 1;
            }
            else {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            prefix.push_back(temp);
        }
    }
    
    int a = prefix.size();
    //cout << a << endl;
    if (a == 0) {
        cout << -1;
    }
    else {
        for (int i = 0; i < a; i++) {
            cout << prefix[i];
        }
    }
    prefix.clear();
    cout << endl;
}

int main() {
	//code
	
	int t;
	int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    string arr[n];
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    
	    /*for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            cout << arr[j][i] << " ";
	        }
	    }*/
	    
	    longest_prefixes(arr, n);
	    
	}
	return 0;
}