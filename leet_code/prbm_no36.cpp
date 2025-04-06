class Solution {
public:
#include <unordered_map>
#include <unordered_set>
#include <vector>
    bool isValidSudoku(vector<vector<char>>& board) {
        // 行のチェック
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> row_set;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (row_set.count(board[i][j])) {
                        return false;
                    }
                    row_set.insert(board[i][j]);
                }
            }
        }

        // 列のチェック
        for (int j = 0; j < 9; ++j) {
            unordered_set<char> col_set;
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] != '.') {
                    if (col_set.count(board[i][j])) {
                        return false;
                    }
                    col_set.insert(board[i][j]);
                }
            }
        }

        // 3x3サブボックスのチェック
        for (int block_row = 0; block_row < 3; ++block_row) {
            for (int block_col = 0; block_col < 3; ++block_col) {
                unordered_set<char> block_set;
                for (int i = block_row * 3; i < block_row * 3 + 3; ++i) {
                    for (int j = block_col * 3; j < block_col * 3 + 3; ++j) {
                        if (board[i][j] != '.') {
                            if (block_set.count(board[i][j])) {
                                return false;
                            }
                            block_set.insert(board[i][j]);
                        }
                    }
                }
            }
        }

        return true;
    }

    bool isValidSudoku2(std::vector<std::vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> rows(9);
        std::unordered_map<int, std::unordered_set<char>> cols(9);
        std::unordered_map<int, std::unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    // Check row
                    if (rows[i].count(c))
                        return false;
                    rows[i].insert(c);

                    // Check column
                    if (cols[j].count(c))
                        return false;
                    cols[j].insert(c);

                    // Check 3x3 box
                    int box_index = (i / 3) * 3 + (j / 3);
                    if (boxes[box_index].count(c))
                        return false;
                    boxes[box_index].insert(c);
                }
            }
        }
        return true;
    }

    /*
        int getMatrix(int i, int j) {
            if (i < 3 && j < 3) {
                return 1;
            } else if (i < 6 && j < 3) {
                return 2;
            } else if (i < 9 && j < 3) {
                return 3;
            }
            if (i < 3 && j < 6) {
                return 4;
            } else if (i < 6 && j < 6) {
                return 5;
            } else if (i < 9 && j < 6) {
                return 6;
            }
            if (i < 3 && j < 9) {
                return 7;
            } else if (i < 6 && j < 9) {
                return 8;
            } else if (i < 9 && j < 9) {
                return 9;
            }
            return -1;
        }

        bool isValidSudoku(vector<vector<char>>& board) {

            unordered_map<char, unordered_set<int>> rows; // i
            unordered_map<char, unordered_set<int>> cols; // j
            unordered_map<char, unordered_set<int>> matrixs;

            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    char c = board[i][j];

                    if (c != '.') {
                        // For row (i)
                        if (rows.find(c) != rows.end()) {
                            unordered_set<int> row = rows.at(c);
                            if (row.find(i) != row.end()) {
                                return false;
                            }
                        }
                        rows[c].insert(i);

                        // For col (j)
                        if (cols.find(c) != cols.end()) {
                            unordered_set<int> col = cols.at(c);
                            if (col.find(j) != col.end()) {
                                return false;
                            }
                        }
                        cols[c].insert(j);

                        // check 3x3
                        int matrix = getMatrix(i, j);
                        if (matrixs.find(c) != matrixs.end()) {
                            unordered_set<int> mat = matrixs.at(c);
                            if (mat.find(matrix) != mat.end()) {
                                return false;
                            }
                        }
                        matrixs[c].insert(matrix);
                    }
                }
            }
            return true;
        }
    */
};