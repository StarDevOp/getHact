//T/C: O(E*V)
//DFS 
Node* rec(Node* node, unordered_map<Node *, Node *> &mp){
        
        Node* copyNode = new Node(node->val);
        mp[node] = copyNode;
        vector<Node* > copyVector;
        for(auto v: node->neighbors){
            Node* neighCopy;
            if(mp.find(v)!=mp.end()){
                neighCopy = mp[v];
            }else{
                neighCopy = rec(v, mp);
            }
            copyVector.push_back(neighCopy);
        }
        copyNode->neighbors = copyVector;
        return copyNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node* , Node* > mp;
        if(node==nullptr){
            return nullptr;
        }
        if(node->neighbors.size()==0){
            return new Node(node->val);
        }
        return rec(node, mp);
    }

//BFS
Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        if(node->neighbors.size()==0){
            return new Node(node->val);
        }
        queue<Node* > q;
        unordered_map<Node* , Node* > mp;
        q.push(node);
        mp[node] = new Node(node->val);
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            Node* copyNode = mp[node];
            vector<Node *> copyList;
            for(Node*  v: node->neighbors){
                if(mp.find(v)!=mp.end()){
                    copyList.push_back(mp[v]);
                }else{
                    Node* neighbor = new Node(v->val);
                    mp[v] = neighbor;
                    q.push(v);
                    copyList.push_back(neighbor);
                }
            }
            copyNode->neighbors = copyList;
        }
        return mp[node];
        
    }    