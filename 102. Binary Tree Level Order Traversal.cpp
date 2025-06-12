#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > v;
        if(!root) return v;

        queue<TreeNode *> q;
        q.push(root);
        
        
        while(!q.empty()){
            int levelsize = q.size();
            vector<int > level;
            for(int i=0;i<levelsize;i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                level.push_back(node->val);
            }
            v.push_back(level);
        }
        return v;
    }
};