void dfs(int u, vector<int> adj[], vector<bool> &visited, vector<int> &res){
        visited[u] = true;
        res.push_back(u);
        for(int v: adj[u]){
            if(visited[v]==false){
                dfs(v, adj, visited, res);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> res;
        dfs(0, adj, visited, res);
        return res;
    }