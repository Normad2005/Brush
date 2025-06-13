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
    vector<vector<int> > res;
    void backtracking(TreeNode *root, int target, vector<int>& cur){
        if(!root) return;

        target -= root->val;
        cur.push_back(root->val);
    
        if(!root->left && !root->right && !target)
            res.push_back(cur);
        else{
            backtracking(root->left, target, cur);
            backtracking(root->right, target, cur);
        }

        cur.pop_back();
        target += root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur;
        backtracking(root, targetSum, cur);
        return res;
    }
};