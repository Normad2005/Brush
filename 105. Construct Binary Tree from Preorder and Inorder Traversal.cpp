#include <iostream>
#include <vector>
#include <map>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inid;
        for(int i=0;i<inorder.size();i++){
            inid[inorder[i]] = i;
        }
        int index = 0;
        TreeNode *root = build(preorder, inid, &index, 0, preorder.size()-1);
        return root;
    }
    TreeNode *build(vector<int>& preorder, map<int, int>& inid, int *index, int l, int r){
        if(!(l <= r) || *index == preorder.size()) return NULL;

        int rootval = preorder[(*index)];
        TreeNode *root = new TreeNode(rootval);
        int mid = inid[rootval];
        (*index)++;

        root->left = build(preorder, inid, index, l, mid-1);
        root->right = build(preorder, inid, index, mid+1, r);
        return root;
    }

};