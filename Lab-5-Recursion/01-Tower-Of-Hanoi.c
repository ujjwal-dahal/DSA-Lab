// Implementation of Recursion

/*
Report ma chai TOH & Fibonacci Series kai Garne
*/

/*
Write a program to implement Tower Of Hanoi (TOH) Problem
*/

/*

Source Auxiliary Destination
A         B         C

1
2
3

i.e 3 ota Disks

1st Step : Move Disk 1 from A to C  -> ( n-1 Disk lai Source to Destination)
2nd Step : Move Disk 2 from A to B
3rd Step : Move Disk 1 from C to B
4th Step : Move Disk 3 from A to C
5th Step : Move Disk 1 from B to A
6th Step : Move Disk 2 from B to C
7th Step : Move Disk 1 from A to C



-> 1st Step Bhaneko n-1 disk lai source to auxiliary laane using destination rod
-> 2nd Step bhaneko nth disk lai Source to Destination laane
-> 3rd Step bhaneko n-1 tai disk lai Auxiliary to Destination laane using Source
*/

#include <stdio.h>

// Recursive function for Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
  if (n <= 0)
  {
    printf("No Any Disk to Perform TOH");
    return;
  }

  // Base case: जब n == 1 हुन्छ, सिधा move गर्नु
  if (n == 1)
  {
    printf("Move Disk %d from %c to %c\n", n, source, destination); // 1 disk सिधै move हुन्छ
    return;                                                         // base case पुगेपछि return गर्छ
  }

  // Recursion bhaneko Function lai tai function bhitra call garnu

  // Step 1: n-1 discs लाई source बाट auxiliary मा move गर्नु
  towerOfHanoi(n - 1, source, destination, auxiliary); // Source → Auxiliary (Destination लाई help को रूपमा प्रयोग गर्दै)

  // Step 2: सबैभन्दा ठूलो disc लाई source बाट destination मा move गर्नु
  printf("Move Disk %d from %c to %c\n", n, source, destination); // ठुलो disc move गरिन्छ

  // Step 3: n-1 discs लाई auxiliary बाट destination मा move गर्नु
  towerOfHanoi(n - 1, auxiliary, source, destination); // Auxiliary → Destination (Source लाई help को रूपमा प्रयोग गर्दै)
}

int main() // main() लाई void होइन int बनाउनुपर्छ (standard practice अनुसार)
{
  int n; // Disk संख्या राख्नको लागि
  printf("\nEnter Number of Disks: ");
  scanf("%d", &n); // User बाट input लिने

  // Tower of Hanoi function call गर्ने
  towerOfHanoi(n, 'A', 'B', 'C'); // A = Source, B = Auxiliary, C = Destination

  return 0; // main function successful रूपमा समाप्त
}
