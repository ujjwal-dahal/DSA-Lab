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

// Structure of a BST node
struct node
{
  int key;                   // Value of the node
  struct node *left, *right; // Left and right children
};

typedef struct node bst;

// Function to create a new node
bst *newNode(int item)
{
  bst *temp = (bst *)malloc(sizeof(bst));
  temp->key = item;                // Assign the key value
  temp->left = temp->right = NULL; // Initialize children as NULL
  return temp;
}

// Function for Inorder Traversal (Left -> Root -> Right)
void inorder(bst *root)
{
  if (root != NULL)
  {
    inorder(root->left);         // Visit left subtree
    printf("%d -> ", root->key); // Print root value
    inorder(root->right);        // Visit right subtree
  }
}

// Function for Preorder Traversal (Root -> Left -> Right)
void preorder(bst *root)
{
  if (root != NULL)
  {
    printf("%d -> ", root->key); // Print root value
    preorder(root->left);        // Visit left subtree
    preorder(root->right);       // Visit right subtree
  }
}

// Function for Postorder Traversal (Left -> Right -> Root)
void postorder(bst *root)
{
  if (root != NULL)
  {
    postorder(root->left);       // Visit left subtree
    postorder(root->right);      // Visit right subtree
    printf("%d -> ", root->key); // Print root value
  }
}

// Function to insert a key into the BST
bst *insert(bst *node, int key)
{
  if (node == NULL)
  {
    return newNode(key); // If tree is empty, create a new node
  }
  if (key < node->key)
  {
    node->left = insert(node->left, key); // Insert in left subtree
  }
  else if (key > node->key)
  {
    node->right = insert(node->right, key); // Insert in right subtree
  }
  return node; // Return the updated root
}

// Function to find the inorder successor (smallest node in right subtree)
bst *minValueNode(bst *root)
{
  bst *current = root;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

// Function to delete a node from BST
bst *deletenode(bst *root, int key)
{
  if (root == NULL)
    return root; // If tree is empty, return

  if (key < root->key)
  {
    root->left = deletenode(root->left, key); // Move to left subtree
  }
  else if (key > root->key)
  {
    root->right = deletenode(root->right, key); // Move to right subtree
  }
  else
  {
    // Node to be deleted found
    if (root->left == NULL)
    {
      bst *temp = root->right;
      free(root); // Delete node with only right child or no child
      return temp;
    }
    if (root->right == NULL)
    {
      bst *temp = root->left;
      free(root); // Delete node with only left child or no child
      return temp;
    }

    // Node with two children: get the inorder successor
    bst *temp = minValueNode(root->right);
    root->key = temp->key;                            // Copy successor's key
    root->right = deletenode(root->right, temp->key); // Delete successor
  }

  return root; // Return updated root
}

int main()
{
  bst *root = NULL;

  // Insert nodes into BST
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 15);
  root = insert(root, 5);
  root = insert(root, 30);
  root = insert(root, 8);
  root = insert(root, 3);

  // Perform Traversals
  printf("Inorder Traversal: ");
  inorder(root);
  printf("\n");

  printf("Preorder Traversal: ");
  preorder(root);
  printf("\n");

  printf("Postorder Traversal: ");
  postorder(root);
  printf("\n");

  // Delete a node and perform traversal again
  printf("Inorder Traversal after deleting node 8: ");
  root = deletenode(root, 8);
  inorder(root);
  printf("\n");

  return 0;
}
