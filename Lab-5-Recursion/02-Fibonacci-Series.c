// Write a program to generate Fibonacci Series

#include <stdio.h>

// Recursive function for Fibonacci Series
void fibonacciSeries(int a, int b, int n)
{
  if (n > 0)
  {
    int number = a + b;    // अगिल्लो दुई संख्या जोडिन्छ
    printf("%d ", number); // नयाँ संख्या print हुन्छ

    // Recursive call with updated values
    fibonacciSeries(b, number, n - 1); // नयाँ a र b को मान पठाइन्छ
  }
}

int main() // Corrected from void main to int main
{
  int n;
  printf("Enter Upto How Many Terms: ");
  scanf("%d", &n); // User input for series length

  printf("Fibonacci Series: ");

  if (n >= 1)
    printf("0 "); // पहिलो संख्या 0
  if (n >= 2)
    printf("1 "); // दोस्रो संख्या 1

  fibonacciSeries(0, 1, n - 2); // Start recursion with first two terms

  return 0; // Program successful run
}
