/*
Find a rotation with maximum hamming distance

Given an array of n elements, create a new array which is a rotation of 
given array and hamming distance between both the arrays is maximum.
Hamming distance between two arrays or strings of equal length is the number of 
positions at which the corresponding character(elements) are different.

Note: There can be more than one output for the given input.

Examples:

Input :  1 4 1
Output :  2
Explanation:  
Maximum hamming distance = 2.
We get this hamming distance with 4 1 1 
or 1 1 4 

input :  N = 4
         2 4 8 0
output :  4
Explanation: 
Maximum hamming distance = 4
We get this hamming distance with 4 8 0 2.
All the places can be occupied by another digit.
Other solutions can be 8 0 2 4, 4 0 2 8 etc.  

Algorithm:
Create another array which is double the size of the original array, 
such that the elements of this new array (copy array) are just the elements 
of the original array repeated twice in the same sequence. Example, 
if the original array is 1 4 1, then the copy array is 1 4 1 1 4 1.
Now, iterate through the copy array and find hamming distance with every shift (or rotation). 
So we check 4 1 1, 1 1 4, 1 4 1, choose the output for which the hamming distance is maximum.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;

	cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int temp[2*n];

	for (int i = 0; i < n; i++) {
		temp[i] = arr[i];
	}
	int j = 0;
	for (int i = n; i < 2*n; i++) {
		temp[i] = arr[j];
		j++;
	}
	int k = 1;
	int i = 0;
	int ham = 0;

	while (k < (2*n)-n) {
		int count = 0;
		int j = k;
		for (int i = 0; i < n; i++) {
			if(arr[i] != temp[j]) {
				count++;
			}
			j++;
		}
		if (ham < count) {
			ham = count;
		}
		k++;
	}

	cout << ham << endl;
	/*for (int i = 0; i < 2*n; i++) {
		cout << temp[i] << " ";
	}
	cout << endl;*/

	return 0;
}