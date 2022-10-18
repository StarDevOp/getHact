bool dfs(int u, vector<vector<int>> &adj, vector<int> &color){
        if(color[u]==-1) color[u] = 1;
        for(int v: adj[u]){
            if(color[v]==-1){
                color[v] = 1^color[u];
                if(dfs(v, adj,  color)==false){
                    return false;
                }
            }else if(color[v]==color[u]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        //no need to make adj list
        for(int i=0; i<n; i++){
            for(int x: graph[i]){
                adj[i].push_back(x);
            }
        }
        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i]==-1 && dfs(i, adj, color)==false){
                return false;
            }
        }
       return true;
    }