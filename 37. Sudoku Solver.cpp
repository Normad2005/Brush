#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<set<char>>> avail;
    void solveSudoku(vector<vector<char>>& board) {
        avail.resize(9, vector<set<char>>(9));
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                avail[i][j] = {'1','2','3','4','5','6','7','8','9'};
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j] != '.')
                    update(i, j, board[i][j]);
        bool found = true;
        while(found){
            found = false;
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(board[i][j] == '.' && avail[i][j].size() == 1){
                        found = true;
                        board[i][j] = *(avail[i][j].begin());
                        update(i, j, board[i][j]);
                    }
                        
                }
            }
        }

        DFS(board);

    }

    void update(int i, int j, char c){
        avail[i][j].clear();
        for(int k=0;k<9;k++){
            avail[i][k].erase(c);
            avail[k][j].erase(c);
        }
        int bi = i/3 * 3;
        int bj = j/3 * 3;
        for(int x=0;x<3;x++)
            for(int y=0;y<3;y++)
                avail[bi+x][bj+y].erase(c);
    }

    bool DFS(vector<vector<char>>& board){
        int row = -1, col = -1, minAvail = 10;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j] == '.' && avail[i][j].size() < minAvail){
                    minAvail = avail[i][j].size();
                    row = i;
                    col = j;
                }
        if(row == -1)
            return true;
        set<char> cand = avail[row][col];
        for(char c:cand){
            auto OldAvail = avail;
            board[row][col] = c;
            update(row, col, c);
            if(DFS(board))
                return true;
            board[row][col] = '.';
            avail = OldAvail;
        }
        return false;
    }

};