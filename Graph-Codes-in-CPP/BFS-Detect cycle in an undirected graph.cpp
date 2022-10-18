bool bfs(int u, vector<int> adj[], vector<bool> &vis){
        queue<pair<int, int> > q;
        q.push({u, -1});
        vis[u] = true;
        while(!q.empty()){
            int x = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int v: adj[x]){
                if(vis[v]==true){
                    if(v!=parent){
                        return true;
                    }
                    
                }else{
                    vis[v] = true;
                    q.push({v, x});
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(vis[i]==false && bfs(i, adj, vis)){
                return true;
            }
        }
        return false;
    }