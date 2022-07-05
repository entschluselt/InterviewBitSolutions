// link
// https://www.interviewbit.com/problems/capture-regions-on-board/

// Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.



/*

Note that all the chunks of O which remain as O are the ones which have at least one O connected to them which is on the boundary. Otherwise they will turn into X.

Think of graph traversal.

*/
int n , m;
void dfs(vector<vector<char>> &a, vector<vector<int>> &vis, int i , int j, vector<vector<bool>> &check){
    if(i < 0 or i > n -1 or j < 0 or j > m-1 or a[i][j] == 'X') return;
    vis[i][j] = 1;
    if(a[i][j] == 'O'){
        check[i][j] = true;
        if(j + 1 < m and !vis[i][j+1]) dfs(a,vis,i,j+1,check);
        if(j-1 >= 0 and !vis[i][j-1]) dfs(a,vis,i,j-1,check);
        if(i + 1 < n and !vis[i+1][j]) dfs(a,vis,i+1,j,check);
        if(i -1 >= 0 and !vis[i-1][j]) dfs(a,vis,i-1,j,check);
    }
}
void Solution::solve(vector<vector<char> > &a) {
    
     n = a.size();
     m = a[0].size();
    vector<vector<int>> vis(n,vector<int> (m,0));
    vector<vector<bool>> check(n, vector<bool> (m,false));
    for(int i = 0; i < n; i++){
        if(!vis[i][0])
            dfs(a,vis,i,0,check);
        if(!vis[i][m-1])
            dfs(a,vis,i,m-1,check);
    }
    for(int i = 0; i < m; i++){
        if(!vis[0][i])
            dfs(a,vis,0,i,check);
        if(!vis[n-1][i])
            dfs(a,vis,n-1,i,check);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(check[i][j] == true)
                a[i][j] == 'O';
            else
                a[i][j] = 'X';
        }
    }
    
}
