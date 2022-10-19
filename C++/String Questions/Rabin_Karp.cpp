//T/C: O((n-m+1)*m)
vector<int> stringMatch(string &str, string &pat) {
    vector<int> v;
    int d=5;
    int mod = 100000;
    int n=str.size(), m=pat.size();
    int p=0, t=0;
    int h=1;
    for(int i=1; i<=m-1; i++){
        h = (h*d)%mod;
    }
    for(int i=0; i<m; i++){
        p = (p*d + pat[i])%mod;
        t = (t*d + str[i])%mod;
    }
    for(int i=0; i<=n-m; i++){
        if(t==p){
            bool flag = true;
            for(int j=0; j<m; j++){
                if(str[i+j]!=pat[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                v.push_back(i);
            }
        }
            if(i<n-m){
                t = (d*(t-str[i]*h))%mod + str[i+m];
                if(t<0){
                    t = t+mod;
                }
            }
        
    }
    return v;
}