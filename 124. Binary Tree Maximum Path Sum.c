#include <stdlib.h>
#include <limits.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

int Max(int a, int b){
    return (a > b) ? a : b;
}

int dfs(TreeNode *root, int *maxSum){
    if(!root)
        return 0;
    
    int left = Max(0, dfs(root->left, maxSum));
    int right = Max(0, dfs(root->right, maxSum));

    *maxSum = Max(*maxSum, left + right + root->val);
    
    return Max(left, right) + root->val;
}

int maxPathSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    dfs(root, &maxSum);
    return maxSum;
}