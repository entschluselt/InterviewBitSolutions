//    https://leetcode.com/problems/unique-paths-ii/


class Solution {
public:
    int dp[101][101];
    int f(int i , int j, int n, int m, vector<vector<int>> &grid){
        if(i >= n or j >= m) return 0;
        if(grid[i][j] == 1) return dp[i][j] = 0;
        if(i == n-1 and j == m-1) return dp[i][j] = 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i+1,j, n, m, grid) + f(i,j+1,n,m,grid);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,n,m,grid);
    }
};
