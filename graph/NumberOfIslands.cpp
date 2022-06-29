/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

*/
class Solution {
public:
    void dfs(int i , int j, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        if(grid[i][j] == '0') return;
        vis[i][j] = true;
        
        if(i-1 >= 0 and !vis[i-1][j]) dfs(i-1,j,grid,vis);
        if(i+1 < grid.size() and !vis[i+1][j]) dfs(i+1,j,grid,vis);
        if(j-1 >= 0 and !vis[i][j-1]) dfs(i,j-1, grid,vis);
        if(j+1 < grid[0].size() and !vis[i][j+1]) dfs(i,j+1, grid, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' and !vis[i][j]){
                    dfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};
