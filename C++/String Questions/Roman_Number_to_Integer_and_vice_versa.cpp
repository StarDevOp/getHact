//String to Int
int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int n = s.size();
        int ans=0;
        for(int i=0; i<n; i++){
            if(m[s[i]]<m[s[i+1]]){
                int temp = m[s[i+1]] - m[s[i]];
                ans+= temp;
                i++;
            }else{
                ans+= m[s[i]];
            }
        }
        return ans;
    }

//Int to String   
//T/C: O(n) numbers of symbols 
//sol1
string intToRoman(int num) {
        vector<pair<int, string>> v;
        v.push_back({1000, "M"});
        v.push_back({900, "CM"});
        v.push_back({500, "D"});
        v.push_back({400, "CD"});
        v.push_back({100, "C"});
        v.push_back({90, "XC"});
        v.push_back({50, "L"});
        v.push_back({40, "XL"});
        v.push_back({10, "X"});
        v.push_back({9, "IX"});
        v.push_back({5, "V"});
        v.push_back({4, "IV"});
        v.push_back({1, "I"});
        int n = v.size();
        string ans="";
        for(int i=0; i<n; i++){
            while(v[i].first<=num){
                ans = ans + v[i].second;
                num = num - v[i].first;
            }
        }
        return ans;
    }

//sol2
string intToRoman(int num) {
        vector<pair<int, string>> v;
        v.push_back({1000, "M"});
        v.push_back({900, "CM"});
        v.push_back({500, "D"});
        v.push_back({400, "CD"});
        v.push_back({100, "C"});
        v.push_back({90, "XC"});
        v.push_back({50, "L"});
        v.push_back({40, "XL"});
        v.push_back({10, "X"});
        v.push_back({9, "IX"});
        v.push_back({5, "V"});
        v.push_back({4, "IV"});
        v.push_back({1, "I"});
        int n = v.size();
        string ans="";
        for(int i=0; i<n; i++){
            if(num>=v[i].first){
                int temp = num/v[i].first;
                num = num%v[i].first;
                while(temp--){
                    ans = ans+ v[i].second;
                }
            }
        }
        return ans;
    }  