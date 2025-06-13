#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    queue<TreeNode *> pre;

    void preorder(TreeNode *root){
        if(root){
            pre.push(root);
            preorder(root->left);
            preorder(root->right);
        }
    }

    void flatten(TreeNode* root) {
        if(!root) return;
        preorder(root);
        TreeNode *cur =  pre.front();
        pre.pop();

        while(!pre.empty()){
            TreeNode *next = pre.front();
            pre.pop();
            cur->left = nullptr;
            cur->right = next;
            cur = next;
            cur->right = nullptr;
        }

    }
};