vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        q.push(0);
        vector<int> res;
        vector<bool> visited(V, false);
        visited[0] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(int v: adj[u]){
                if(visited[v]==false){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return res;
    }