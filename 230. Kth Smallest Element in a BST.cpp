#include <iostream>
#include <vector>

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
    int index, res;

    int kthSmallest(TreeNode* root, int k) {
        index = res = 0;
        inorder(root, k);
        return res;
    }

    void inorder(TreeNode *root, int k){
        if(root){
            inorder(root->left, k);
            if(++index == k){
                res = root->val;
                return;
            }
            inorder(root->right, k);
        }
    }
};