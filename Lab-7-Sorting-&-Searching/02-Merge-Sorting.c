/*

Implementation of Merge Sort & Implementation of Binary Searching

*/

/*
Merge Sort ko Concept:

1. Sabai Array lai middle bata divide garne.
   Divide gardai jane until Array ma 1 element matra baaki hunchha.
   Minimum 2 ota element baaki huna parcha to divide further.

2. Aba 2 ta element bhaeko array lai sort garne.
   Sabai 2 ta element bhaeko array sorted form ma convert garne.

3. Aba Sorted 2 ta element bhaeko arrays huncha.
   Aba chai 2 ta array ko each element compare garne.
   - 1st index ko element lai 1st index ko element sanga compare garne.
   - Smaller element lai merge garera sorted array ma rakhdai combine garne.

4. Esari recursively sab array combine garera last ma sorted array paunchha.

Example:
- [4, 2, 7, 3]
  Step 1: Divide: [4, 2] [7, 3]
  Step 2: Sort: [2, 4], [3, 7]
  Step 3: Merge: Compare & Combine: [2, 3, 4, 7]

Yaso gardai Merge Sort ko process complete huncha.
*/

// C program for the implementation of merge sort
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]

// merge function ko kaam chai sorted array lai combine garne
void merge(int arr[], int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left + 1; // array ko middle dekhi left samma ko length thaa bhayo
  int n2 = right - mid;    // array ko right side dekhi middle samma ko length thaa bhayo

  // Create temporary arrays
  int leftArr[n1], rightArr[n2]; // Yo array chai hamile left ra right array ko element halna banako

  // Copy data to temporary arrays
  for (i = 0; i < n1; i++)
    leftArr[i] = arr[left + i]; // since n1 ko count left+1 to middle samma jancha
  for (j = 0; j < n2; j++)
    rightArr[j] = arr[mid + 1 + j]; // abo hamilai middle+1 dekhi right samma ko value chaeyo

  // Merge the temporary arrays back into arr[left..right]
  i = 0,     /* initial index of first sub-array */
      j = 0; /* initial index of second sub-array */
  k = left;  /* initial index of merged sub-array */

  while (i < n1 && j < n2)
  {
    if (leftArr[i] <= rightArr[j])
    {
      arr[k] = leftArr[i];
      i++;
    }
    else
    {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of leftArr[], if any
  while (i < n1)
  {
    arr[k] = leftArr[i];
    i++;
    k++;
  }

  // Copy the remaining elements of rightArr[], if any
  while (j < n2)
  {
    arr[k] = rightArr[j];
    j++;
    k++;
  }
}

// The subarray to be sorted is in the index range [left-right]
void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {

    // Calculate the midpoint
    int mid = left + (right - left) / 2;

    // Sort first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7, 8, 1, 100};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Sorting arr using mergesort
  mergeSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  return 0;
}