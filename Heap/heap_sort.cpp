/*
Heap Sort
Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to 
implement Heap Sort.

Input:
First line of the input denotes number of test cases T. First line of the test case is the size of array and second line consists of 
array elements.

Output:
Sorted array in ascending order.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106

Example:
Input:
2
5
4 1 3 9 7
10
10 9 8 7 6 5 4 3 2 1

Output:
1 3 4 7 9
1 2 3 4 5 6 7 8 9 10

Explanation:
Testcase 1: After sorting elements using heap sort, elements will be in order as 1, 3, 4, 7 and 9.
*/

/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */
// The functions should be written in a way that array become sorted 
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[]. 
// n is size of heap. This function  is used in above heapSor()
void heapify(int arr[], int n, int i)  {
      // Your Code Here
      int l = 2*i + 1;
      int r = 2*i + 2;
      int large = i;
      if (l < n && arr[l] > arr[i]) {
          large = l;
      }
      if (r < n && arr[r] > arr[large]) {
          large = r;
      }
      
      if (large != i) {
          swap(arr[i], arr[large]);
          heapify(arr, n, large);
      }
}
// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  { 
    // Your Code Here
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, n, i);
    }
}
