#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<vector<int> > &graph, vector<int > &cur, int u, int n){
        cur.push_back(u);
        if(u == n-1)
            res.push_back(cur);
        
        else
            for(int v:graph[u])
                dfs(graph, cur, v, n);
        
        
        cur.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int > cur;
        dfs(graph, cur, 0, graph.size());
        return res;
    }
};