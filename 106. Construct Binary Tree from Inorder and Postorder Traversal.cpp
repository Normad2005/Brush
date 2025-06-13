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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inid;
        for(int i=0;i<inorder.size();i++){
            inid[inorder[i]] = i;
        }
        int index = postorder.size() - 1;
        TreeNode *root = build(postorder, inid, &index, 0, postorder.size()-1);
        return root;
    }
    TreeNode *build(vector<int>& postorder, map<int, int>& inid, int *index, int l, int r){
        if(!(l <= r) || *index < 0) return NULL;

        int rootval = postorder[*index];
        TreeNode *root = new TreeNode(rootval);
        int mid = inid[rootval];
        (*index)--;

        root->right = build(postorder, inid, index, mid+1, r);
        root->left = build(postorder, inid, index, l, mid-1);
        return root;
    }
};