struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

void dfs(TreeNode *root, int cur, int *total){
    if(!root) return;

    cur = cur*10;
    cur += root->val;
    if(!root->left && !root->right){
        *total += cur;
    }
    dfs(root->left, cur, total);
    dfs(root->right, cur, total);
}

int sumNumbers(struct TreeNode* root) {
    int total = 0;
    dfs(root, 0, &total);
    return total;
}