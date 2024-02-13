#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Tree {
    struct Node* root;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insertNode(struct Tree* tree, int data) {
    struct Node* newNode = createNode(data);

    if (tree->root == NULL) {
        tree->root = newNode;
    } else {
        struct Node* current = tree->root;
        struct Node* parent = NULL;

        while (current != NULL) {
            parent = current;

            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (data < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
}
struct Node* findMinNode(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorderTraversal(struct Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

void preorderTraversal(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void postorderTraversal(struct Node* node) {
    if (node != NULL) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%d ", node->data);
    }
}

int main() {
    struct Tree tree;
    tree.root = NULL;

    int numNodes, data;
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&tree, data);
    }

    printf("In-order traversal: ");
    inorderTraversal(tree.root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorderTraversal(tree.root);
    printf("\n");

    printf("Post-order traversal: ");
    postorderTraversal(tree.root);
    printf("\n");

    int key;
    printf("Enter the key to delete: ");
    scanf("%d", &key);
    tree.root = deleteNode(tree.root, key);

    printf("Updated In-order traversal: ");
    inorderTraversal(tree.root);
    printf("\n");

    return 0;
}
