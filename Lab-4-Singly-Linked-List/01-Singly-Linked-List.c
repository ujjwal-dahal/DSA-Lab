#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node
{
  int data;          // Data stored in the node
  struct Node *next; // Pointer to the next node
};

// Insert a node at the beginning of the list
void insertAtBeginning(struct Node **head, int value)
{
  // **head is Pointer to Pointer -> Esle Arko Pointer ko Memory Address store garne kaam garcha
  // Esle Memory Address Create garcha Struct Node ko Size ko
  // *newNode is Pointer
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

  if (!newNode)
  {
    printf("Memory allocation failed\n");
    return;
  }
  newNode->data = value; // Assign value to the new node

  // Since **head is Pointer to Pointer so -> *head le 1st Node ko Memory Address Store garne kaam garcha
  newNode->next = *head; // Point the new node to the current head

  // Abo Hamile Head lai New Node ma Move garne -> i.e *head lai newNode ko memory address dine
  // since *newNode le newNode ko Memory address paako huncha so hamile *head = newNode garda memory address jancha
  *head = newNode; // Update head to the new node
  printf("%d inserted at the beginning.\n", value);
}

// Delete the last node in the list
void deleteLastNode(struct Node **head)
{

  // Eddi head ma NULL address cha bhane head chai last Node ma Point gareko huncha
  if (*head == NULL)
  {
    printf("Linked list is empty! Nothing to delete.\n");
    return;
  }

  /*
  Hamile 1st Node Delete garna chai Key Concept
  1. 1st Node ko Memory address ma NULL value haldine
  2. Head lai 2nd Node ma Point garne
  */
  struct Node *temp = *head;
  struct Node *prev = NULL;

  // Traverse to the last node
  while (temp->next != NULL)
  {
    prev = temp;       // Keep track of the previous node
    temp = temp->next; // Move to the next node
  }

  if (prev == NULL)
  {
    // Only one node exists in the list
    printf("%d deleted (it was the only node).\n", temp->data);
    free(temp); // Free the memory of the single node
    *head = NULL;
  }
  else
  {
    prev->next = NULL; // Remove the last node by updating the previous node's next
    printf("%d deleted from the list.\n", temp->data);
    free(temp); // Free the memory of the last node
  }
}

// Traverse and display all elements in the list
void traverseAndDisplay(struct Node *head)
{
  if (head == NULL)
  {
    printf("Linked list is empty!\n");
    return;
  }

  printf("Linked List: ");
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data); // Print each node's data
    temp = temp->next;            // Move to the next node
  }
  printf("NULL\n");
}

// Search for an element in the list
void searchElement(struct Node *head, int value)
{
  int position = 0;
  struct Node *temp = head; // temp pointer ma head le point gareko memory address hold garcha

  while (temp != NULL)
  {
    if (temp->data == value)
    {
      printf("%d found at position %d.\n", value, position + 1);
      return;
    }
    temp = temp->next;
    position++;
  }
  printf("%d not found in the linked list.\n", value);
}

// Main function to test the operations
int main()
{
  struct Node *head = NULL; // Initialize an empty linked list

  int choice, value;

  while (1)
  {
    printf("\nMenu:\n");
    printf("1. Insert at Beginning\n");
    printf("2. Delete Last Node\n");
    printf("3. Traverse and Display\n");
    printf("4. Search for an Element\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1: // Insert at beginning
      printf("Enter value to insert: ");
      scanf("%d", &value);
      insertAtBeginning(&head, value);
      break;

    case 2: // Delete last node
      deleteLastNode(&head);
      break;

    case 3: // Traverse and display
      traverseAndDisplay(head);
      break;

    case 4: // Search for an element
      printf("Enter value to search: ");
      scanf("%d", &value);
      searchElement(head, value);
      break;

    case 5: // Exit
      printf("Exiting...\n");
      return 0;

    default: // Invalid choice
      printf("Invalid choice! Please try again.\n");
    }
  }
}
