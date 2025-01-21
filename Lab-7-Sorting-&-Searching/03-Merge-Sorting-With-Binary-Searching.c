/*
Lab 7 : Implementation of Merge Sort & Implementation of Binary Search

*/

#include <stdio.h>

// Merge function to combine two sorted subarrays
void merge(int arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1; // Size of the left subarray
  int n2 = right - mid;    // Size of the right subarray

  int L[n1], R[n2]; // Temporary arrays

  // Copy data to temporary arrays
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  // Merge the temporary arrays back into the original array
  int i = 0, j = 0, k = left; // Initial indices
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy remaining elements of L[] if any
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy remaining elements of R[] if any
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2; // Find the middle point

    // Recursively sort the two halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

// Binary Search function
int binarySearch(int arr[], int left, int right, int target)
{
  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) // Target found
      return mid;

    if (arr[mid] < target) // Target is on the right half
      left = mid + 1;
    else // Target is on the left half
      right = mid - 1;
  }
  return -1; // Target not found
}

// Main function
int main()
{
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target;
  printf("\n Enter Element to Search : ");
  scanf("%d", &target);

  printf("Original array: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  // Sort the array using Merge Sort
  mergeSort(arr, 0, n - 1);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  // Search for the target using Binary Search
  int result = binarySearch(arr, 0, n - 1, target);

  if (result != -1)
    printf("Element %d found at index %d.\n", target, result);
  else
    printf("Element %d not found.\n", target);

  return 0;
}
