class Solution {
public:

	// Gemini‚Ìƒwƒ‹ƒv‚ðŽØ‚è‚é
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
 
    int numIslands(vector<vector<char>>& grid) {

        int numIsland = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == '1') {
                    findIsland(row,col,grid);
                    numIsland++;
                }
            }
        }
       
        return numIsland;
    }
};