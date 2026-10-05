#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *left, *right;
} Node;

static Node *insert(Node *root, int value) {
  if (!root) {
    root = (Node *)malloc(sizeof(Node));
    root->value = value; root->left = root->right = NULL;
  } else if (value < root->value) root->left = insert(root->left, value);
  else if (value > root->value) root->right = insert(root->right, value);
  return root;
}
static void inorder(Node *root) {
  if (root) { inorder(root->left); printf("%d ", root->value); inorder(root->right); }
}
static void preorder(Node *root) {
  if (root) { printf("%d ", root->value); preorder(root->left); preorder(root->right); }
}
static void postorder(Node *root) {
  if (root) { postorder(root->left); postorder(root->right); printf("%d ", root->value); }
}
static void destroy(Node *root) {
  if (root) { destroy(root->left); destroy(root->right); free(root); }
}
int main(void) {
  int n, value;
  Node *root = NULL;
  printf("Number of values: ");
  if (scanf("%d", &n) != 1 || n < 0) return 1;
  for (int i = 0; i < n; ++i) { scanf("%d", &value); root = insert(root, value); }
  printf("Inorder: "); inorder(root);
  printf("\nPreorder: "); preorder(root);
  printf("\nPostorder: "); postorder(root);
  puts("");
  destroy(root);
  return 0;
}
