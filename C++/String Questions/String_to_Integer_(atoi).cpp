int myAtoi(string s) {
        int ans=0;
        int i=0;
        int sign=1;
        int n = s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        if(i==n) return 0;
        
        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-') sign = -1;
            i++;
        }
        
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                int temp = s[i]-'0';
                if((sign==1) && ((ans>INT_MAX/10) || (ans==INT_MAX/10 && temp>=INT_MAX%10))){
                    return INT_MAX;
                }
                if(sign==-1 && ((ans>abs(INT_MIN/10)) || (ans==abs(INT_MIN/10) && temp>=abs(INT_MIN%10)))){
                    return INT_MIN;
                }
                ans = ans*10 + temp;
            }else{
                break;
            }
            i++;
        }
        return ans*sign;
    }

 int myAtoi(string s) {
        int ans=0;
        int i=0;
        int sign=1;
        int n = s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        if(i==n) return 0;
        
        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-') sign = -1;
            i++;
        }
        
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                int temp = s[i]-'0';
                if((ans>INT_MAX/10) || (ans==INT_MAX/10 && temp>INT_MAX%10)){
                    return sign==-1? INT_MIN: INT_MAX;
                }
                ans = ans*10 + temp;
            }else{
                break;
            }
            i++;
        }
        return ans*sign;
    }   