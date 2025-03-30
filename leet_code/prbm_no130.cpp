class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y) {

        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 'O') {
            return;
        }

        grid[x][y] = '#';

        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }

    void print(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout<<board[i][j]<<",";
            }
            cout<<endl;
        }
    }

    void solve(vector<vector<char>>& board) {

        if (board.empty() || board[0].empty()) {
            return;
        }

        int rows = board.size();
        int cols = board[0].size();

        // 境界の'O'からDFSを開始
        for (int i = 0; i < rows; i++) {
           // cout<<board[i][0]<<","<<board[i][cols-1]<<endl;
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][cols-1] == 'O') {
                
                dfs(board, i, cols - 1);
            }
        }
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            if (board[rows-1][j] == 'O') {
                dfs(board, rows-1, j);
            }
        }

        // 残りの'O'を'X'に、'#'を'O'に戻す
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
        
    }

    /*
    void connect(vector<vector<char>>& board, int x, int y) {
        if ((x == 0) || (x == board.size() - 1) || (y == 0) ||
            (y == board.size() - 1) || (board[x][y] == 'X')) {
            return;
        }

        // 周りがすべて"X"があれば、"X"とする
        if ((board[x - 1][y] == 'X') || (board[x + 1][y] == 'X') ||
            (board[x][y - 1] == 'X') || (board[x][y + 1] == 'X')) {
            // "O"を"X"にする
            board[x][y] = 'X';
        }
    }
    */
};