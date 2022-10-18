bool cycledfs(int u, int par, vector<int> adj[], vector<bool> &visited){
        visited[u]=true;
        for(int v: adj[u]){
            if(visited[v]==false){
                if(cycledfs(v, u, adj, visited)==true){
                    return true;
                }
            }else if(v!=par){
                return true;
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(visited[i]==false){
                if(cycledfs(i, -1, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }