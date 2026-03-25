/*
 * Assignment 2 / Question 1 / student.c
 * ------------------------------------------------------------
 * Search in a Binary Search Tree (BST)
 *
 * Implement:
 *   struct TreeNode* bstSearch(struct TreeNode* root, int target);
 *
 * Rules:
 * - Return a pointer to the node with value == target, else NULL.
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run1
 */

#include <stddef.h>  // NULL

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) {
    // Base case: empty tree or found the target
    if (root == NULL) {
        return NULL;
    }
    
    // Check if current node is the target
    if (root->val == target) {
        return root;
    }
    
    // Use BST property: if target is less, go left; if greater, go right
    if (target < root->val) {
        return bstSearch(root->left, target);
    } else {
        return bstSearch(root->right, target);
    }
}
