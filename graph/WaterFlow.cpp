/*
Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the number of cells from where water can flow to both the Blue and Red lake.

*/

/*

Basically we multiexplore the grid from each lake and then check if a node is reachable from both lakes then that node is the boundary

*/


int n , m;
void bfs(vector<vector<bool>> &vis, vector<vector<int>> a, queue<pair<int,int>> &q){
    vector<int> dx(4),dy(4);
    dx[0] = -1, dy[0] = 0, dx[1] = 1, dy[1] = 0, dx[2] = 0, dy[2] = 1, dx[3] = 0, dy[3] = -1;
      
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        vis[x][y] = true;
        q.pop();
        for(int i = 0; i < 4; i++){
            int temp_x = x + dx[i];
            int temp_y = y + dy[i];
            if(temp_x < 0 or temp_x > n-1 or temp_y < 0 or temp_y > m-1)
                continue;
            
            else if(!vis[temp_x][temp_y] and a[temp_x][temp_y] >= a[x][y]) {
                vis[temp_x][temp_y] = true;
                q.push({temp_x,temp_y});
            }
        }    
    }
}
int Solution::solve(vector<vector<int> > &a) {
    n = a.size();
    m = a[0].size();
    vector<vector<bool>> vis_red(n,vector<bool> (m,false));
    vector<vector<bool>> vis_blue(n, vector<bool> (m,false));
    // red 
    queue<pair<int,int>> q_red;
    for(int i = 0; i < n; i++) q_red.push({i,m-1});
    for(int i = 0; i < m; i++) q_red.push({n-1,i});
    bfs(vis_red,a,q_red);
  
    queue<pair<int,int>> q_blue;
    for(int i = 0; i < m; i++) q_blue.push({0,i});
    for(int i = 0; i < n; i++) q_blue.push({i,0});
    bfs(vis_blue,a,q_blue);
    
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis_red[i][j] == true and vis_blue[i][j] == true) count++;
        }
    }
    return count;
}
