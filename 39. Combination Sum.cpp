#include <vector>
using  namespace std;



class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &candidates, int target, vector<int> &cur, int num, int init){
        if(num >= target){
            if(num == target)
                res.push_back(cur);
            return;
        }
        for(int i = init ; i < candidates.size() ; i++){
            cur.push_back(i);
            dfs(candidates, target, cur, num + candidates[i], i);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        dfs(candidates, target, cur, 0, 0);
        return res;
    }
};