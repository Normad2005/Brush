#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> res;
    void geng(int left, int right, int n, string cur){
        if(cur.length() == 2*n){
            res.push_back(cur);
            return;
        }
        if(left < n)
            geng(left + 1, right, n, cur + '(');
        if(left > right)
            geng(left, right + 1, n, cur + ')');

    }
    

    vector<string> generateParenthesis(int n) {
        geng(0, 0, n, "");
        return res;
    }
};