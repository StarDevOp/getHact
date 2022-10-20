// M-1 T/C: O(n*len(prefix))
string longestCommonPrefix(vector<string>& strs) {
        int j=0;
        string ans="";
        int n = strs.size();
        while(true){
            char temp;
            for(int i=0; i<n; i++){
                if(strs[i].size()==j){
                    return ans;
                }
                if(i==0){
                    temp = strs[i][j];
                }else{
                    if(strs[i][j]!=temp){
                        return ans;
                    }
                }
            }
            ans = ans+temp;
            j++;
            
        }      
    }

//M-2
string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0) return "";
        string prefix = strs[0];
        for(int i=1; i<n; i++){
            while(strs[i].find(prefix)!=0){
                prefix = prefix.substr(0, prefix.size()-1);
            }
        }
        return prefix;
    }

//M-3 Trie
struct Node{
        int freq;
        Node *child[26];
        Node(){
            for(int i=0; i<26; i++){
                child[i]=nullptr;
            }
            freq=0;
        }
    };
    void buildTrie(string s, Node *curr){
        int n = s.size();
        for(int i=0; i<n; i++){
            int index=s[i]-'a';
            if(curr->child[index]==nullptr){
                curr->child[index] = new Node();
            }
            curr->child[index]->freq++;     
            curr = curr->child[index];
        }
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        Node *root = new Node();
        for(int i=0; i<n; i++){
            buildTrie(strs[i], root);
        }
        string ans="";
        string prefix=strs[0];
        for(int i=0; i<prefix.size(); i++){
            int index = prefix[i]-'a';
            if(root->child[index]->freq==n){
                ans+= prefix[i];
            }else{
                break;
            }
            root = root->child[index];
        }
        return ans;
        
    }    