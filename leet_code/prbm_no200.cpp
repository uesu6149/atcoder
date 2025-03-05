class Solution {
public:

    void findIsland(int row, int col, vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        // Check Range
        if (row >= rows || col >= cols || row < 0 || col < 0 || grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';

        findIsland(row+1,col, grid);    // Top
        findIsland(row-1,col, grid);    // Bottom]
        findIsland(row,col+1, grid);    // Left]
        findIsland(row,col-1, grid);    // Right]
    }

    void findIslandByStack(int row, int col, vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // stack�ɂ�row,col���Ǘ�����
        stack<pair<int, int>> s;
        s.push({row,col});

        // �㉺���E�̈ړ��������`
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!s.empty()) {
            auto[x,y] = s.top();
            s.pop();
        
            // �z��O��K��ς݁A�ʂ�Ȃ��Z�����X�L�b�v
            if (x >= rows || y >= cols || x < 0 || y < 0 || grid[x][y] == '0') {
                continue;
            }
            
            grid[x][y] = '0';

            // �אڃZ�����X�^�b�N�ɒǉ�
            for (const auto& [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;
                s.push({newX, newY});
            }
        }
    }
 
    int numIslands(vector<vector<char>>& grid) {

        int numIsland = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == '1') {
                    //findIsland(row,col,grid);
                    findIslandByStack(row,col,grid);
                    numIsland++;
                }
            }
        }
       
        return numIsland;
    }
};