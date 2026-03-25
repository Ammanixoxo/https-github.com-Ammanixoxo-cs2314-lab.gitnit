/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function: returns height if valid AVL, -1 if invalid
static long long checkAVLHelper(struct TreeNode* node, long long min, long long max) {
    // Base case: empty tree is valid with height 0
    if (node == NULL) {
        return 0;
    }
    
    // Check strict BST property: node value must be strictly between min and max
    if (node->val <= min || node->val >= max) {
        return -1;  // Invalid BST
    }
    
    // Recursively check left subtree (values must be < node->val)
    long long leftHeight = checkAVLHelper(node->left, min, node->val);
    if (leftHeight == -1) {
        return -1;  // Left subtree is invalid
    }
    
    // Recursively check right subtree (values must be > node->val)
    long long rightHeight = checkAVLHelper(node->right, node->val, max);
    if (rightHeight == -1) {
        return -1;  // Right subtree is invalid
    }
    
    // Check height-balance condition: |height(left) - height(right)| <= 1
    long long diff = leftHeight - rightHeight;
    if (diff < -1 || diff > 1) {
        return -1;  // Unbalanced
    }
    
    // Return height of current subtree (height of leaf is 1, height of NULL is 0)
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isAVL(struct TreeNode* root) {
    // Tree is AVL if helper returns >= 0 (valid height)
    return checkAVLHelper(root, LLONG_MIN, LLONG_MAX) >= 0;
}
