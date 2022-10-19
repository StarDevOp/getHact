//T/C: O(n^2), S/C: O(n^2)
string longestPalindrome(string s) {
        int n = s.length(), p, q;
        string ans;
        vector<vector<int>> dp(n, vector<int> (n));
        for(int g=0; g<n; g++){
            for(int i=0, j=g; j<n; j++, i++){
                if(g==0){
                    dp[i][j]=1;
                }else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=0;
                    }
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1]==1){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=0;
                    }
                }
                if(dp[i][j]==1){
                    p = i;
                    q = j;
                }
            }
        }
        return s.substr(p, q-p+1);
    }

    //T/C: O(n^2), S/C: O(1)
    int solve(int lo, int hi, int n, string &s){
        while(lo>=0 && hi<n){
            if(s[lo]!=s[hi]){
                break;
            }
            hi++;
            lo--;
        }
        return hi-lo-1;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int res = 0, st=0, en=0;
        string ans;
        for(int i=0; i<n-1; i++){
            int t1 = solve(i, i+1, n, s);
            int t2 = solve(i, i, n, s);
            int t = max(t1, t2);
            if(t>res){
                st = i - (t-1)/2;
                en = i + (t/2);
                res = t;
            }
        }
        return s.substr(st, en-st+1);
        
    }