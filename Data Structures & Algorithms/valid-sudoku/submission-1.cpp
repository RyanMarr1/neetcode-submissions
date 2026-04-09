class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> num_table (27);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                char digit = board[i][j];
                if (digit == '.') {
                    continue;
                }
                int quadrant_index = ((i / 3) * 3) + (j / 3);
                if (!num_table[i].insert(digit).second) {
                    return false;
                }
                if (!num_table[j + 9].insert(digit).second) {
                    return false;
                }
                if (!num_table[quadrant_index + 18].insert(digit).second) {
                    return false;
                }
            }
        }
        return true;
    }
};