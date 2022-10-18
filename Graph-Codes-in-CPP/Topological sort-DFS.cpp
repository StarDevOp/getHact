void topodfs(int u, vector<int> adj[], vector<bool>&vis, stack<int> &st){
	    vis[u]=true;
	    for(int v: adj[u]){
	        if(vis[v]==false){
	            topodfs(v, adj, vis, st);
	        }
	    }
	    st.push(u);
	}
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> vis(n, false);
	    vector<int> res;
	    stack<int> st;
	    for(int i=0; i<n; i++){
	        if(vis[i]==false){
	            topodfs(i, adj, vis, st);
	        }
	    }
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}