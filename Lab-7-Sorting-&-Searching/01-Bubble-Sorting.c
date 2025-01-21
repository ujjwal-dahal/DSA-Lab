#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n)
{
  // Outer loop: Controls the number of passes
  // Each pass places the largest unsorted element at its correct position
  for (int i = 0; i < n - 1; i++)
  {
    // Flag to track if any swapping occurred in this pass
    int swapped = 0;

    // Inner loop: Compares adjacent elements and swaps if needed
    for (int j = 0; j < n - i - 1; j++)
    {
      // If the current element is greater than the next, swap them
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];   // Store current element in temp
        arr[j] = arr[j + 1]; // Move the next element to the current position
        arr[j + 1] = temp;   // Assign temp to the next position

        // Mark that a swap has occurred
        swapped = 1;
      }
    }

    // Optional: Print the state of the array after each pass
    printf("After pass %d: ", i + 1);
    for (int k = 0; k < n; k++)
    {
      printf("%d ", arr[k]);
    }
    printf("\n");

    // If no swapping occurred in this pass, the array is already sorted
    if (swapped == 0)
    {
      break;
    }
  }
}

// Function to display the array
void displayArray(int arr[], int n)
{
  // Traverse the array and print each element
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Main function
int main()
{
  // Define an array of integers
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

  // Print the original array
  printf("Original array: ");
  displayArray(arr, n);

  // Call bubbleSort to sort the array
  bubbleSort(arr, n);

  // Print the sorted array
  printf("Sorted array: ");
  displayArray(arr, n);

  return 0;
}
