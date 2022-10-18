vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
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
	    while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(int v: adj[u]){
                inDeg[v]--;
                if(inDeg[v]==0){
                    q.push(v);
                }
            }
	    }
	    return res;
	}