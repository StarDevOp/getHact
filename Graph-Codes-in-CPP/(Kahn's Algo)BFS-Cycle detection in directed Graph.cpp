bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto x: prerequisites){
            int u = x[0];
            int v = x[1];
            adj[v].push_back(u);
        }
        int V = numCourses;
        vector<int> inDeg(V, 0);
	    for(int i=0; i<V; i++){
	        for(int x: adj[i]){
	            inDeg[x]++;
	        }
	    }
	    queue<int> q;
	    vector<int> res;
	    for(int i=0; i<V; i++){
	        if(inDeg[i]==0){
	            q.push(i);
	        }
	    }
        int count=0;
	    while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            for(int v: adj[u]){
                inDeg[v]--;
                if(inDeg[v]==0){
                    q.push(v);
                }
            }  
	    }
	    if(count==V){
            return true;
        }else{
            return false;
        }
	
    }