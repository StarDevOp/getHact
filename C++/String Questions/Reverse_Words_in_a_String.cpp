//Sol1
//T/C: O(n), S/C:O(n) vector/stack used
string reverseWords(string s) {
        vector<string> v;
        string temp="";
        for(int i=0; i<s.size(); i++){
           if(s[i]!=' '){
               temp+=s[i];
           }else{
               if(temp!=""){
                   v.push_back(temp);
                   temp="";
               }
           }    
        }
        if(temp!=""){
            v.push_back(temp);
        }
        string ans="";
        int n = v.size();
        for(int i=n-1; i>=0; i--){
            ans = ans+ v[i];
            ans= ans+ (i==0?"":" ");
        }
        return ans;
    }


//Sol2
//T/C: O(n), S/C:O(1)only output string used
string reverseWords(string s) {
        string ans="", temp="";
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]!=' '){
                temp+=s[i];
            }else{
                ans = temp+ (ans.size()!=0?" ":"") +ans;
                temp=""; 
            }
        }
        if(temp!=""){
            ans = temp+ (ans.size()!=0?" ":"") +ans;
        }
        return ans;
    } 


//Diff Imp
string reverseWords(string s) {
        int i=0, j, n=s.size();
        string ans;
        string temp;
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            j=i+1;
            while(j<n && s[j]!=' '){
                j++;
            }
            if(i==n){
                break;
            }
            temp = s.substr(i, j-i);
            if(ans.empty()){
                ans =temp;
                temp="";
            }else{
                ans = temp+" "+ans;
                temp="";
            }
            i=j+1;
        }
        return ans;
    }    



//S/C: O(1)
void reverse(string &s, int i, int j){
        while(i<j){
            swap(s[i++], s[j--]);
        }
    }
    string reverseWords(string s) {
        int n = s.size();
        int i=0, j=0;
        int wordsCount=0;
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            if(i==n){
                break;
            }
            if(wordsCount){
                s[j++] = ' ';
            }
            int start = j;
            while(i<n && s[i]!=' '){
                s[j++] = s[i++];
            }
            reverse(s, start, j-1);
            wordsCount++;
        }
        s.resize(j);
        reverse(s, 0, j-1);
        return s;
    }    