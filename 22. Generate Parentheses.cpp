#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> res;

    void Geng(int left, int right, string cur){
        if(right == left){
            res.push_back(cur);
            return;
        }
        if(right > left)
            return;
        Geng(left + 1, right, cur + "(");
        Geng(left, right+1, cur + ")");
    }

    vector<string> generateParenthesis(int n) {
        Geng(0, 0, "");
        return res
    }
};