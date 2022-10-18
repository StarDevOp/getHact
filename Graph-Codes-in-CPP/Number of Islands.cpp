//DFS
int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid){
        grid[x][y] = '0';
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='1'){
                dfs(nx, ny, n, m, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    dfs(i, j, n, m, grid);
                    count++;
                }
            }
        }
        return count;
    }

//BFS
int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
    void bfs(int i, int j, int n, int m, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j]='0';
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            
            for(int z=0; z<4; z++){
                int nx = x+dx[z];
                int ny = y+dy[z];
                if(nx>=0 && nx<n && ny>=0 & ny<m && grid[nx][ny]=='1'){
                    q.push({nx, ny});
                    grid[nx][ny] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    bfs(i, j, n, m , grid);
                    count++;
                }
                
            }
        }
        return count;
        
    }


//Iterative DFS
int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
    void dfsItr(int i, int j, int n, int m, vector<vector<char>>& grid){
        stack<pair<int, int>> st;
        st.push({i, j});
        grid[i][j]='0';
        while(!st.empty()){
            auto p = st.top();
            st.pop();
            int x = p.first, y = p.second;
            
            for(int z=0; z<4; z++){
                int nx = x+dx[z];
                int ny = y+dy[z];
                if(nx>=0 && nx<n && ny>=0 & ny<m && grid[nx][ny]=='1'){
                    st.push({nx, ny});
                    grid[nx][ny] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    dfsItr(i, j, n, m , grid);
                    count++;
                }
                
            }
        }
        return count;
        
    }        