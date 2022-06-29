/*

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

*/


class Solution {
public:
    int dp[201][201];
    int dfs(int i , int j , vector<vector<int>> &matrix, int prev){
        if(i < 0 or j < 0 or i >= matrix.size() or j >= matrix[0].size() or matrix[i][j] <= prev) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 1 + max({
                dfs(i-1,j,matrix,matrix[i][j]),
                dfs(i,j-1,matrix,matrix[i][j]),
                dfs(i+1,j,matrix,matrix[i][j]),
                dfs(i,j+1,matrix,matrix[i][j])
        });
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxpath = 0;
        memset(dp,-1,sizeof(dp));
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxpath = max(maxpath,dfs(i , j , matrix, -1));
            }
        }
        return maxpath;
    }
};
