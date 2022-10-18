bool bfs(int u, vector<vector<int>>& graph, vector<int> &color){
        queue<int> q;
        q.push(u);
        color[u] = 1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            int currColor = color[x];
            for(int v: graph[x]){
                if(color[v]==-1){
                    color[v] = currColor^1;
                    q.push(v);
                }else if(color[v]==currColor){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                if(bfs(i, graph, color)==false){
                    return false;
                }
            }
        }
        return true;
    }