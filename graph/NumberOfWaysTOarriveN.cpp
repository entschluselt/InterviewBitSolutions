#define ll long long
const ll mod = 1000000007;
class Solution {
public:
    // APPROACHING FLOYD WARSHELL 
    int countPaths(int n, vector<vector<int>>& roads) {
      ll dp[n][n][2];
      
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if(i != j){
            dp[i][j][0] = 1e13;
            dp[i][j][1] = 0;
          } else {
            dp[i][j][0] = 0;
            dp[i][j][1] = 1;
          }
        }
      }
      
      for(int i = 0; i < roads.size(); i++){
        dp[roads[i][0]][roads[i][1]][0] = roads[i][2];
        dp[roads[i][1]][roads[i][0]][0] = roads[i][2];
        
        dp[roads[i][0]][roads[i][1]][1] = 1;
        dp[roads[i][1]][roads[i][0]][1] = 1;
      }
      
      // FLOYD WARSHELL
      
      for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
            if(i != k and j != k){
              if(dp[i][k][0] + dp[k][j][0] < dp[i][j][0]){
                dp[i][j][0] = dp[i][k][0] + dp[k][j][0];
                dp[i][j][1] = (dp[i][k][1] * dp[k][j][1]) % mod;
              } else if(dp[i][k][0] + dp[k][j][0] == dp[i][j][0]) {
                dp[i][j][1] = (dp[i][j][1] + dp[i][k][1] * dp[k][j][1]) % mod;
              }
            }
          }
        }
      }
      
      return dp[0][n-1][1];
    }
};
