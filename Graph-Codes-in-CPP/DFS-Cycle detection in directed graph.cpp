bool cycledfs(int u, vector<vector<int>> &adj, vector<bool> &inStack, vector<bool> &vis){
        vis[u] = true;
        inStack[u] = true;
        for(int v: adj[u]){
            if(vis[v]==false){
                if(cycledfs(v, adj, inStack, vis)){
                    return true;
                }
            }else if(inStack[v]){
                return true;
            }
        }
        inStack[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto x: prerequisites){
            int u = x[0];
            int v = x[1];
            adj[v].push_back(u);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> inStack(numCourses, false);
        for(int i=0; i<numCourses; i++){
            if(vis[i]==false){
                if(cycledfs(i, adj, inStack, vis)){
                    return false;
                }
            }
        }
        return true;
    }