/*
Lab 6 : Implementation of Binary Search Tree (BST) Operations

-> Write a program to implement BST Operations
1. Insertion
2. Traversal ( Inorder , Preorder & Postorder)
3. Deletion

Insert Following Nodes:
eg : 10 , 20 , 15 , 5 , 30 , 8 , 3
*/

/*
Lab 6 : Implementation of Binary Search Tree (BST) Operations

-> Write a program to implement BST Operations
1. Insertion
2. Traversal ( Inorder , Preorder & Postorder)
3. Deletion

Insert Following Nodes:
eg : 10 , 20 , 15 , 5 , 30 , 8 , 3
*/

#include <stdio.h>
#include <stdlib.h>

// BST node structure
struct Node
{
  int data;           // Node मा data राख्ने
  struct Node *left;  // Left child
  struct Node *right; // Right child
};

// नयाँ node create गर्ने function
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Dynamic memory allocate
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// BST मा node insert गर्ने function
struct Node *insert(struct Node *root, int data)
{
  if (root == NULL)
  {
    return createNode(data); // यदि root खाली छ भने नयाँ node बनाउने
  }

  if (data < root->data)
  {
    root->left = insert(root->left, data); // Data सानो छ भने left मा insert
  }
  else if (data > root->data)
  {
    root->right = insert(root->right, data); // Data ठूलो छ भने right मा insert
  }

  return root; // Root unchanged फर्काउने
}

// Inorder Traversal (Left → Root → Right)
void inorder(struct Node *root)
{
  if (root != NULL)
  {
    inorder(root->left);       // Left subtree visit
    printf("%d ", root->data); // Root print
    inorder(root->right);      // Right subtree visit
  }
}

// Preorder Traversal (Root → Left → Right)
void preorder(struct Node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data); // Root print
    preorder(root->left);      // Left subtree visit
    preorder(root->right);     // Right subtree visit
  }
}

// Postorder Traversal (Left → Right → Root)
void postorder(struct Node *root)
{
  if (root != NULL)
  {
    postorder(root->left);     // Left subtree visit
    postorder(root->right);    // Right subtree visit
    printf("%d ", root->data); // Root print
  }
}

// BST बाट node delete गर्ने function
struct Node *deleteNode(struct Node *root, int key)
{
  if (root == NULL)
  {
    return root; // खाली भए return
  }

  // Key सानो छ भने left subtree मा खोज्ने
  if (key < root->data)
  {
    root->left = deleteNode(root->left, key);
  }
  // Key ठूलो छ भने right subtree मा खोज्ने
  else if (key > root->data)
  {
    root->right = deleteNode(root->right, key);
  }
  // Found the node to delete
  else
  {
    // Case 1: No child / One child (left)
    if (root->left == NULL)
    {
      struct Node *temp = root->right;
      free(root);
      return temp;
    }
    // Case 2: One child (right)
    else if (root->right == NULL)
    {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }

    // Case 3: Two children - inorder successor find गर्ने
    struct Node *temp = root->right;
    while (temp->left != NULL)
    {
      temp = temp->left;
    }

    root->data = temp->data;                           // Successor को value राख्ने
    root->right = deleteNode(root->right, temp->data); // Successor लाई delete गर्ने
  }

  return root;
}

int main()
{
  struct Node *root = NULL; // BST को root node

  // BST मा nodes insert गर्ने
  int nodes[] = {10, 20, 15, 5, 30, 8, 3};
  int n = sizeof(nodes) / sizeof(nodes[0]);

  for (int i = 0; i < n; i++)
  {
    root = insert(root, nodes[i]);
  }

  printf("Inorder Traversal: ");
  inorder(root);
  printf("\n");

  printf("Preorder Traversal: ");
  preorder(root);
  printf("\n");

  printf("Postorder Traversal: ");
  postorder(root);
  printf("\n");

  // BST बाट node delete गर्ने
  printf("\nDeleting Node 20...\n");
  root = deleteNode(root, 20);

  printf("Inorder Traversal after Deletion: ");
  inorder(root);
  printf("\n");

  return 0;
}
